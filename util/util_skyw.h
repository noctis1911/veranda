#ifndef UTIL_SKYW_H
#define UTIL_SKYW_H

#include <QObject>
#include <QXmlStreamReader>
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>

#include <../model/struct_xml.h>

class util_skyw : public QObject
{
    Q_OBJECT
public:
    explicit util_skyw(QObject *parent = 0);
    void parse_xml(QString skyw, QSqlDatabase db);

signals:
    
public slots:

private:
    int jum_dat;
};

#endif // UTIL_SKYW_H
