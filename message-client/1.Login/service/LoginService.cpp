#include "LoginService.h"
#include "pub.const.h"

LoginService::LoginService()
{
	m_pLoginWgt = new LoginWidget();
	connect(m_pLoginWgt, &LoginWidget::showRegWgt_LoginService, this, &LoginService::showRegWgt_LoginService);
}

void LoginService::login(json& js)
{
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
