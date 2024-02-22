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
	// ��̬�ӿ�
	static SqliteOperator* getInstance();

	// �������ݿ�
	void createDb();

	// �����ݿ�
	bool openDb();

	// �ر����ݿ�
	void closeDb();

	// �ѱ������Զ��ṩ�Ŀ��������� = ������������Ƴ�
	SqliteOperator(const SqliteOperator& other) = delete;
	void operator = (const SqliteOperator& other) = delete;

private:
	static SqliteOperator* s_connect;
	QSqlDatabase db;

	SqliteOperator();
	~SqliteOperator();
};

#endif
