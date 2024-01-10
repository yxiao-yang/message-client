#include "ConnectServer.h"

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

	// 如果客户端收到发送过来的数据，系统会产生readyRead信号
	connect(m_pTcpSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void ConnectServer::onConnectedServer()
{
	m_bConnected = true;

	// 连接成功之后第一次发送自己的帐户
	//QByteArray straccount = this->account.toUtf8();
	//tcpClient->write(straccount);
}

void ConnectServer::onReadyRead()
{

}

bool ConnectServer::isConnectionSuccess()
{
	return m_bConnected;
}