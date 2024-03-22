#ifndef _CONNECT_SERVER_H_
#define _CONNECT_SERVER_H_

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QString>
#include <QDebug>
#include <QMutex>
#include <QByteArray>

class ConnectServer : public QObject
{
	Q_OBJECT

public:
	// ��̬�ӿ�
	static ConnectServer* getInstance();

	// ���ӷ�����
	void connectServer();

	// ����Ƿ����ӳɹ�
	bool isConnectionSuccess();

	// ��ȡsocket
	QTcpSocket* getTcpSocket();

	// �ѱ������Զ��ṩ�Ŀ��������� = ������������Ƴ�
	ConnectServer(const ConnectServer& other) = delete;
	void operator = (const ConnectServer& other) = delete;

private slots:
	void onConnectedServer();
	void onReadyRead();
	void onDisconnected();

private:
	static ConnectServer* s_connect;
	QTcpSocket* m_pTcpSocket = nullptr;
	bool m_bConnected = false;

	QString m_strIPAddress = "192.168.1.102";
	quint16 m_iPort = 6002;

	ConnectServer();
	~ConnectServer();

};

#endif