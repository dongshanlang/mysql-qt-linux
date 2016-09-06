#ifndef MYMYSQL_H
#define MYMYSQL_H
#include <windows.h>//需要放在#include <C:/mysql/include/mysql.h>之前
//路径中使用‘/’符号
#include <C:/mysql/include/mysql.h>
#include <QStandardItemModel>
/*
 * linux下的包含头文件方法。
 * #include <mysql/mysql.h>
 *
 * */
//#include <mysql/mysql.h>
class mymysql
{
public:
    mymysql();
    ~mymysql();
    const char * get_error();
    //server IP地址
    int sql_connect(const char *Hostname, const char *User, const char *Password, const char *DBName);
    void sql_disconnect();
    int sql_exec(const char *SQL);
    int sql_open(const char *SQL, QStandardItemModel **p);

private:
    MYSQL *connection;
    MYSQL mysql;
    char buf[1024];

};

#endif // MYMYSQL_H
