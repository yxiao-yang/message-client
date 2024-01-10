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
	// 静态接口
	static ConnectServer* getInstance();

	// 连接服务器
	void connectServer();

	// 检查是否连接成功
	bool isConnectionSuccess();

	// 把编译器自动提供的拷贝构造与 = 号运算符重载移除
	ConnectServer(const ConnectServer& other) = delete;
	void operator = (const ConnectServer& other) = delete;

	QTcpSocket* m_pTcpSocket = nullptr;

private slots:
	void onConnectedServer();
	void onReadyRead();

private:
	static ConnectServer* s_connect;
	bool m_bConnected = false;

	//QTcpServer* m_pTcpServer = nullptr;
	QString m_strIPAddress = "192.168.25.129";
	quint16 m_iPort = 6000;

	ConnectServer();
	~ConnectServer();

};

#endif