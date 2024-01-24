#include "HomeService.h"

#pragma execution_character_set("utf-8")

HomeService::HomeService()
{
	m_pHomeWgt = new HomeWidget();

	setSlots();
}

void HomeService::showHomeWgt()
{
	m_pHomeWgt->setStyle();
	m_pHomeWgt->show();
}

void HomeService::searchUser_Home_Service(QString& Userid, QString& Searchid)
{
	m_pAddFriendService->searchUser(Userid, Searchid);
}

void HomeService::setSlots()
{
	m_pMessageService = new MessageService();
	m_pFriendService = new FriendService();
	m_pAddFriendService = new AddFriendService();
	connect(m_pHomeWgt, &HomeWidget::searchUser_Home_Service, this, &HomeService::searchUser_Home_Service);
	connect(m_pAddFriendService, &AddFriendService::showSearchRes_Home_Service, this, &HomeService::showSearchRes_Home_Service);
}

void HomeService::search_ack(json& js)
{
	m_pAddFriendService->searchUserAns(js);
}

void HomeService::showSearchRes_Home_Service(std::vector<User>& arrUser)
{
	m_pHomeWgt->showSearchRes(arrUser);
}
