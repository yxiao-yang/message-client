#ifndef _SQLITE_OPERATOR_H_
#define _SQLITE_OPERATOR_H_

#include <QObject>
#include <QDebug>
#include <QMutex>
#include <QSqlDatabase>

class SqliteOperator : public QObject
{
	Q_OBJECT
public:
	// 静态接口
	static SqliteOperator* getInstance();

	// 创建数据库
	void createDb();

	// 打开数据库
	bool openDb();

	// 关闭数据库
	void closeDb();

	// 把编译器自动提供的拷贝构造与 = 号运算符重载移除
	SqliteOperator(const SqliteOperator& other) = delete;
	void operator = (const SqliteOperator& other) = delete;

private:
	static SqliteOperator* s_connect;
	QSqlDatabase db;

	SqliteOperator();
	~SqliteOperator();
};

#endif
