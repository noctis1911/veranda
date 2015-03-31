#ifndef PARSING_FUCTION_H
#define PARSING_FUCTION_H

#include <QString>
#include <QDebug>
#include <QDateTime>

#define  GMT7    25200

class parsing_function
{
public:
    parsing_function();

    QString decode_base64(QString data);
    QString hex_to_bin_conversion(QString hex);
    QString hex_to_bin(char dat);
    QString format_5cut_32get(QString biner);
    QString parse_data(QString dat);

    int bin_to_decimal(QString dat32);
    int operasi_pangkat(int n);
};

#endif // PARSING_FUCTION_H
