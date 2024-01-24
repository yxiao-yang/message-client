#include "RegService.h"
#include "pub.const.h"
#include "ConnectServer.h"

RegService::RegService()
{
	m_pRegWgt = new RegWidget;
	connect(m_pRegWgt, &RegWidget::showLoginWgt_RegService, this, &RegService::showLoginWgt_RegService);
	connect(m_pRegWgt, &RegWidget::sendRegMessage_RegService, this, &RegService::sendRegMessage_RegService);
}

void RegService::reg(json& js)
{
	enRegType errnoType = js["errno"];
	if (errnoType == REG_SUCCESS)
	{
		std::string Userid = js["Userid"];
		emit showRegSuccessWgt_Service(Userid);
	}
	else
	{

	}
}

void RegService::showRegWgt()
{
	m_pRegWgt->setStyle();
	m_pRegWgt->show();
}

void RegService::showLoginWgt_RegService()
{
	emit showLoginWgt_Service();
}

void RegService::sendRegMessage_RegService(QString& Username, QString& Password, QString& Telephone)
{
	json js;
	js["msgid"] = REG_MSG;
	js["Username"] = Username.toStdString();
	js["Password"] = Password.toStdString();
	js["Telephone"] = Telephone.toStdString();
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send register fail";
	}
	else
	{
		qDebug() << "send register success";
	}
}
