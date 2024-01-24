#include "LoginService.h"
#include "pub.const.h"
#include "ConnectServer.h"
#include "pub.cache.h"

#pragma execution_character_set("utf-8")

LoginService::LoginService()
{
	m_pLoginWgt = new LoginWidget();
	connect(m_pLoginWgt, &LoginWidget::showRegWgt_LoginService, this, &LoginService::showRegWgt_LoginService);
	connect(m_pLoginWgt, &LoginWidget::loginHome_LoginService, this, &LoginService::loginHome_LoginService);
}

void LoginService::login(json& js)
{
	enLoginType errnoType = js["errno"];
	if (errnoType == LOGIN_SUCCESS)
	{
		std::string Userid = js["Userid"];
		std::string Username = js["Username"];
		std::string phone = js["Telephone"];
		std::string time = js["Time"];
		PubCache::getInstance()->setUser(Userid, Username, phone, time);
		qDebug() << "��¼�ɹ�";
		emit showHomeWgt_Service();
		m_pLoginWgt->hide();
	}
	else if (errnoType == LOGIN_ERR_REPEAT)
	{
		qDebug() << "�ظ���¼";
	}
	else if (errnoType == LOGIN_ERR_WRONG)
	{
		qDebug() << "�û������������";
	}
}

void LoginService::showLoginWgt()
{
	m_pLoginWgt->setStyle();
	m_pLoginWgt->show();
}

void LoginService::showRegWgt_LoginService()
{
	emit showRegWgt_Service();
}

void LoginService::loginHome_LoginService(QString& Userid, QString& Password)
{
	json js;
	js["msgid"] = LOGIN_MSG;
	js["Userid"] = Userid.toStdString();
	js["Password"] = Password.toStdString();
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send login fail";
	}
	else
	{
		qDebug() << "send login success";
	}
}
