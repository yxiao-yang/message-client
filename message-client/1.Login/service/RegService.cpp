#include "RegService.h"
#include "pub.const.h"

RegService::RegService()
{
	m_pRegSuccessWgt = new RegSuccessWidget();
}

void RegService::reg(json& js)
{
	enMsgType errnoType = js["errno"];
	if (errnoType == REG_SUCCESS)
	{
		std::string Userid = js["Userid"];
		m_pRegSuccessWgt->setStyle();
		m_pRegSuccessWgt->show();
	}
	else
	{

	}
}