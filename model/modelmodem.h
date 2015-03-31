#ifndef MODELMODEM_H
#define MODELMODEM_H

#include <QtSql>
#include <QSqlTableModel>

class modelModem : public QSqlTableModel    {
public:
    QSqlQueryModel model;


    modelModem(QObject *parent = 0);
    //void initializeModel();
};

#endif // MODELMODEM_H
