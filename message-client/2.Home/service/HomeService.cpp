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
	m_pFriendNoticeService = new FriendNoticeService();
	connect(m_pHomeWgt, &HomeWidget::searchUser_Home_Service, this, &HomeService::searchUser_Home_Service);
	connect(m_pAddFriendService, &AddFriendService::showSearchRes_Home_Service, this, &HomeService::showSearchRes_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::getFriendNotice_Home_Service, this, &HomeService::getFriendNotice_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::addFriend_Home_Service, this, &HomeService::addFriend_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::getFriendship_Home_Service, this, &HomeService::getFriendship_Home_Service);
	connect(m_pAddFriendService, &AddFriendService::addFriendAns_Home_Service, this, &HomeService::addFriendAns_Home_Service);
}

void HomeService::search_ack(json& js)
{
	m_pAddFriendService->searchUserAns(js);
}

void HomeService::showSearchRes_Home_Service(std::vector<User>& arrUser)
{
	m_pHomeWgt->showSearchRes(arrUser);
}

void HomeService::getFriendNotice_Home_Service()
{
	m_pFriendNoticeService->getFriendNotice();
}

void HomeService::addFriend_Home_Service(QString& userid)
{
	m_pAddFriendService->addFriend(userid);
}

void HomeService::getFriendship_Home_Service()
{
	m_pFriendService->getFriendship();
}

void HomeService::addFriendAns(json& js)
{
	m_pAddFriendService->addFriendAns(js);
}

void HomeService::addFriendAns_Home_Service(enAddFriendType errnoType)
{
	m_pHomeWgt->showAddFriendAns(errnoType);
}
