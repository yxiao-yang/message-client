#include "ConnectServer.h"

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

	// ����ͻ����յ����͹��������ݣ�ϵͳ�����readyRead�ź�
	connect(m_pTcpSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void ConnectServer::onConnectedServer()
{
	m_bConnected = true;

	// ���ӳɹ�֮���һ�η����Լ����ʻ�
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