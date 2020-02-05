#include "network.h"
#include <iostream>
Network::Network(QObject *parent) : QObject(parent)
{

}

void Network::postRequest(QString url)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    /*
    connect(manager, &QNetworkAccessManager::finished,
            this, &Network::replyFinished);
    */
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,
        "application/x-www-form-urlencoded");
    //QUrl postData;
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QHttpPart textPart;
    textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"dnn$ctr1025$Etusivu$txtHakuEtunimi2\""));
    textPart.setBody("Wille");

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    //manager->get(QNetworkRequest(QUrl(url)));
    //manager->post(request, postData.query().toUtf8());
    manager->post(request, multiPart);
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
        std::cout << reply->readAll().toStdString();
    }
        reply->deleteLater();
}
