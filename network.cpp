#include "network.h"
#include <iostream>
Network::Network(QObject *parent) : QObject(parent)
{

}

void Network::postRequest(QString url)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,
        "application/x-www-form-urlencoded");
    //QUrl postData;

    // Tähän saa form-dataa...
    // täytyy deletoida jossain vaiheessa! https://doc.qt.io/archives/qt-4.8/qhttpmultipart.html
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    // ... näin ->
    /*
    QHttpPart textPart;
    textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"dnn$ctr1025$Etusivu$txtHakuEtunimi2\""));
    textPart.setBody("Wille");

    multipart->append(textPart);
    */

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    //manager->get(QNetworkRequest(QUrl(url)));
    //manager->post(request, postData.query().toUtf8());
   QNetworkReply* reply = manager->post(request, multiPart);

   // nyt multipart poistuu kun reply poistuu :)
   multiPart->setParent(reply);
}

void Network::replyFinished(QNetworkReply *reply)
{
    //std::cout << reply->readAll();
    if (reply->error()){
        qDebug() << reply->errorString();
    }
    else {
        /*
        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        */
        std::string data = reply->readAll().toStdString();
        std::vector<std::string> variables = {"__EVENTTARGET", "__EVENTARGUMENT", "__VIEWSTATE", "__VIEWSTATEGENERATOR", "__EVENTVALIDATION"};
        std::map<std::string, std::string> variableData;
        Parser parser;
        variableData = parser.parseVariables(data, variables);

        // Debugging stuff ***************
        for (auto x : variableData){
            std::cout << x.first << ": " << x.second << std::endl;
        }
        // *******************************
        //std::cout << reply->readAll().toStdString();
    }
        reply->deleteLater();
}
