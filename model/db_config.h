#ifndef DB_CONFIG_H
#define DB_CONFIG_H

#include <QFile>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

class db_config
{
public:
    db_config();

    int count_db;

    QSqlDatabase cek_exist_db(QString fileName);
    QSqlDatabase create_db(QString fileName, int count_db);
    QSqlDatabase load_db(QString fileName, int count_db);

    void crt_table_ship(QSqlDatabase db);
    void crt_table_parsing(QSqlDatabase db);
    void crt_table_data(QSqlDatabase db);
};

#endif // DB_CONFIG_H
