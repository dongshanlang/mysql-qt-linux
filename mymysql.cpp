#include "mymysql.h"
#include <QMessageBox>
#include <string.h>


//建这个类的目的是实现封装，封装所有和mysql相关的函数
mymysql::mymysql()
{
    mysql_init(&mysql);
    connection = NULL;
    memset(buf, 0, 0);
}

mymysql::~mymysql()
{
    if(connection)
    {
        mysql_close(connection);
    }
}

const char *mymysql::get_error()
{
    return buf;
}

int mymysql::sql_connect(const char *Hostname, const char *User, const char *Password, const char *DBName)
{
    connection = mysql_real_connect(&mysql, Hostname, User, Password, DBName, 0, 0, 0);
    if(connection == NULL)
    {
        memset(buf, 0, sizeof(buf));
        strcpy(buf, mysql_error(&mysql));
        //QMessageBox::information(0, "", mysql_error(&mysql));
        return -1;
    }else
    {
        mysql_query(connection ,"set names utf8");
        return 0;
    }
}

void mymysql::sql_disconnect()
{
    if(connection)
    {
        mysql_close(connection);
        connection = NULL;

    }
}

int mymysql::sql_exec(const char *SQL)
{
    if(mysql_query(connection, SQL) != 0)
    {
        memset(buf, 0, 0);
        strcpy(buf, mysql_error(&mysql));
        return -1;
    }
    return 0;
}
//二级指针是重点
int mymysql::sql_open(const char *SQL, QStandardItemModel **p)
{
    if(mysql_query(connection, SQL) != 0)
    {
        memset(buf, 0, 0);
        strcpy(buf, mysql_error(&mysql));
        return -1;
    }
    MYSQL_RES *result = mysql_store_result(connection);
    if(result == NULL)//无查询结果
    {
        memset(buf, 0, 0);
        strcpy(buf, mysql_error(&mysql));
        return -1;
    }

    int rowCount = mysql_affected_rows(connection);//返回sql语句执行后有多少列，
    int fieldCount = mysql_field_count(connection);//返回sql语句执行后有多少行

    *p = new QStandardItemModel(rowCount, fieldCount);//根据sql语句动态创建出model
    MYSQL_FIELD *field;
    int i = 0, j = 0;

    for(i = 0; i < fieldCount; i++)
    {
        field = mysql_fetch_field(result);
        (*p)->setHeaderData(i, Qt::Horizontal, field->name);
    }

    for(i = 0; i <rowCount; i++)//得到每一行
    {
         MYSQL_ROW row = mysql_fetch_row(result);
         for(j = 0; j < fieldCount; j++)//循环遍历一行当中所有的列
         {
             (*p)->setData((*p)->index(i, j ,QModelIndex()), row[j]);
         }
    }
    mysql_free_result(result);//释放mysql——store分配的内存
    return 0;
}

