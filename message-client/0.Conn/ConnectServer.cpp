#include "ConnectServer.h"
#include "json.hpp"
#include "Service.h"

using json = nlohmann::json;

ConnectServer* ConnectServer::s_connect = nullptr;

ConnectServer* ConnectServer::getInstance()
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
			s_connect = new ConnectServer;
		}
	}

	return s_connect;
}

ConnectServer::ConnectServer()
{
	// 创建一个socket类
	m_pTcpSocket = new QTcpSocket(this);
}

ConnectServer::~ConnectServer()
{
}

void ConnectServer::connectServer()
{
	// 根据IP地址和端口号连接服务器
	m_pTcpSocket->connectToHost(m_strIPAddress, m_iPort);

	// 客户端连接服务器成功后会产生connected信号
	connect(m_pTcpSocket, SIGNAL(connected()), this, SLOT(onConnectedServer()));
}

void ConnectServer::onConnectedServer()
{
	m_bConnected = true;
	qDebug() << "Connect Server Success";

	// 如果客户端收到发送过来的数据，系统会产生readyRead信号
	connect(m_pTcpSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

	//断开连接
	connect(m_pTcpSocket, SIGNAL(disconnected()), SLOT(onDisconnected()));
}

void ConnectServer::onReadyRead()
{
	qDebug() << "ready read";

	// 从缓冲区拿数据
	std::string buf = m_pTcpSocket->readAll();

	// 数据反序列化
	json js = json::parse(buf);

	// 执行对应事件的回调
	auto msgHandler =
		Service::getInstance()->getHandler(js["msgid"].get<enMsgType>());
	msgHandler(js);
}

void ConnectServer::onDisconnected()
{
	m_bConnected = false;
	qDebug() << "Connect Server Fail";
}

bool ConnectServer::isConnectionSuccess()
{
	return m_bConnected;
}

QTcpSocket* ConnectServer::getTcpSocket()
{
	return m_pTcpSocket;
}