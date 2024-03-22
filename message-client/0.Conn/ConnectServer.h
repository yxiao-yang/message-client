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

	// 获取socket
	QTcpSocket* getTcpSocket();

	// 把编译器自动提供的拷贝构造与 = 号运算符重载移除
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