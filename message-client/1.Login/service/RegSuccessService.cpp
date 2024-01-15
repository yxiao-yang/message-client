#include "RegSuccessService.h"

RegSuccessService::RegSuccessService()
{
	m_pRegSuccessWgt = new RegSuccessWidget;
	connect(m_pRegSuccessWgt, &RegSuccessWidget::showLoginWgt_RegSuccessService, this, &RegSuccessService::showLoginWgt_RegSuccessService);
}

void RegSuccessService::showRegSuccessWgt(std::string& Userid)
{
	m_pRegSuccessWgt->setStyle(Userid);
	m_pRegSuccessWgt->show();
}

void RegSuccessService::showLoginWgt_RegSuccessService()
{
	emit showLoginWgt_Service();
}
