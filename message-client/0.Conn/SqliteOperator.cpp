#include "SqliteOperator.h"
#include <QSqlError>

SqliteOperator* SqliteOperator::s_connect = nullptr;

SqliteOperator* SqliteOperator::getInstance()
{
	// �ж��Ƿ��ǵ�һ�ε���
	// ���粻ΪNULL,��ֱ��return
	if (s_connect == nullptr)
	{
		// ��ֹ�����ͬʱ���ô���2�����������
		// ԭ������Ϊ�Ǿ�̬����ֻ�ᶨ��һ��
		static QMutex mutex;

		// ����  QMutexLocker����סmutex����QMutexLocker ���ͷŵ�ʱ����Զ�����
		// locker�Ǿֲ�����������getInstance������������֮����Զ�����
		QMutexLocker locker(&mutex);

		// ���ж�һ��,��ֹ������������new����
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
