#include "ConnectServer.h"
#include "json.hpp"
#include "Service.h"

using json = nlohmann::json;

ConnectServer* ConnectServer::s_connect = nullptr;

ConnectServer* ConnectServer::getInstance()
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
			s_connect = new ConnectServer;
		}
	}

	return s_connect;
}

ConnectServer::ConnectServer()
{
	// ����һ��socket��
	m_pTcpSocket = new QTcpSocket(this);
}

ConnectServer::~ConnectServer()
{
}

void ConnectServer::connectServer()
{
	// ����IP��ַ�Ͷ˿ں����ӷ�����
	m_pTcpSocket->connectToHost(m_strIPAddress, m_iPort);

	// �ͻ������ӷ������ɹ�������connected�ź�
	connect(m_pTcpSocket, SIGNAL(connected()), this, SLOT(onConnectedServer()));
}

void ConnectServer::onConnectedServer()
{
	m_bConnected = true;
	qDebug() << "Connect Server Success";

	// ����ͻ����յ����͹��������ݣ�ϵͳ�����readyRead�ź�
	connect(m_pTcpSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

	//�Ͽ�����
	connect(m_pTcpSocket, SIGNAL(disconnected()), SLOT(onDisconnected()));
}

void ConnectServer::onReadyRead()
{
	qDebug() << "ready read";

	// �ӻ�����������
	std::string buf = m_pTcpSocket->readAll();

	// ���ݷ����л�
	json js = json::parse(buf);

	// ִ�ж�Ӧ�¼��Ļص�
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