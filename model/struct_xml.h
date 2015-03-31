#ifndef STRUCT_XML_H
#define STRUCT_XML_H

#endif // STRUCT_XML_H

#include <QString>
#include <QDateTime>

struct st_xml{
#if 0
    float *titik_ukur;

    int jml_ukur;
    int size;

    QDateTime SendModem;
    QDateTime receiveUTC;
#else
    QString RawPayLoad[1000];
    QString SendModem;
    QString receiveUTC;
#endif

};

struct xmll{
    QString mobile_id;
    QString NextStructUTC;

    int jml;

    struct st_xml st_xmls;
};
