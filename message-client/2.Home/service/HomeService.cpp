#include "HomeService.h"

#pragma execution_character_set("utf-8")

HomeService::HomeService()
{
	m_pHomeWgt = new HomeWidget();
}

void HomeService::showHomeWgt()
{
	m_pHomeWgt->setStyle();
	m_pHomeWgt->show();
}
