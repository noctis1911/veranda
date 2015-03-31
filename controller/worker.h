#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QXmlStreamReader>
#include <QSqlQuery>

#include "../util/util_skyw.h"
#include "../view/skywavenetwork.h"
#include "../model/get_db.h";

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);
    QXmlStreamReader xml;
signals:
    
public slots:

private slots:
    void doWork();
    void getResponSkyW();
    //void getUpdateData();
    void replyFinished(QNetworkReply* reply);
    //void replyUpdate(QNetworkReply* reply);
private:
    QTimer timer;
    util_skyw *read;
    get_db *get;


    //skywaveNetwork skw;
};

#endif // TIMER_H
