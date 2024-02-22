#include "SqliteOperator.h"
#include <QSqlError>

SqliteOperator* SqliteOperator::s_connect = nullptr;

SqliteOperator* SqliteOperator::getInstance()
{
	// 判断是否是第一次调用
	// 假如不为NULL,会直接return
	if (s_connect == nullptr)
	{
		// 防止多进程同时调用创建2个对象的问题
		// 原理是因为是静态变量只会定义一次
		static QMutex mutex;

		// 上锁  QMutexLocker会锁住mutex，当QMutexLocker 被释放的时候会自动解锁
		// locker是局部变量，所以getInstance（）函数结束之后会自动解锁
		QMutexLocker locker(&mutex);

		// 再判断一次,防止其它进程抢先new过了
		if (s_connect == nullptr)
		{
			s_connect = new SqliteOperator;
		}
	}

	return s_connect;
}

SqliteOperator::SqliteOperator()
{

}

SqliteOperator::~SqliteOperator()
{

}

void SqliteOperator::createDb()
{
	if (QSqlDatabase::contains("qt_sql_default_connection"))
	{
		db = QSqlDatabase::database("qt_sql_default_connection");
	}
	else
	{
		db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("test.db");
		db.setUserName("test");
		db.setPassword("test");
	}
}

bool SqliteOperator::openDb()
{
	if (!db.open())
	{
		qDebug() << "Error: Failed to connect database." << db.lastError();
		return false;
	}
	return true;
}

void SqliteOperator::closeDb()
{
	db.close();
}
