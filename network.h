#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QtCore>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <iostream>
#include <QDebug>
#include <QHttpMultiPart>
#include <QFile>
#include <QTextStream>
class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = nullptr);
    void postRequest(QString url);
signals:

public slots:
    void replyFinished(QNetworkReply *reply);
};

#endif // NETWORK_H
