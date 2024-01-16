#include "LoginService.h"
#include "pub.const.h"
#include "ConnectServer.h"

#pragma execution_character_set("utf-8")

LoginService::LoginService()
{
	m_pLoginWgt = new LoginWidget();
	connect(m_pLoginWgt, &LoginWidget::showRegWgt_LoginService, this, &LoginService::showRegWgt_LoginService);
	connect(m_pLoginWgt, &LoginWidget::loginHome_LoginService, this, &LoginService::loginHome_LoginService);
}

void LoginService::login(json& js)
{
	enMsgType errnoType = js["errno"];
	if (errnoType == LOGIN_SUCCESS)
	{
		std::string Userid = js["Userid"];
		std::string Username = js["Username"];
		std::string phone = js["Telephone"];
		std::string time = js["Time"];
		qDebug() << "登录成功";
		//emit showRegSuccessWgt_Service(Userid);
	}
	else if (errnoType == LOGIN_ERR_REPEAT)
	{
		qDebug() << "重复登录";
	}
	else if (errnoType == LOGIN_ERR_WRONG)
	{
		qDebug() << "用户名或密码错误";
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
