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
	m_pHomeWgt->showMessageWgt();
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
	m_pMessageWindowService = new MessageWindowService();
	connect(m_pHomeWgt, &HomeWidget::searchUser_Home_Service, this, &HomeService::searchUser_Home_Service);
	connect(m_pAddFriendService, &AddFriendService::showSearchRes_Home_Service, this, &HomeService::showSearchRes_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::getFriendNotice_Home_Service, this, &HomeService::getFriendNotice_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::addFriend_Home_Service, this, &HomeService::addFriend_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::getFriendship_Home_Service, this, &HomeService::getFriendship_Home_Service);
	connect(m_pAddFriendService, &AddFriendService::addFriendAns_Home_Service, this, &HomeService::addFriendAns_Home_Service);
	connect(m_pFriendNoticeService, &FriendNoticeService::showFriendNotice_Home_Service, this, &HomeService::showFriendNotice_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::acceptFriendApply_Home_Service, this, &HomeService::acceptFriendApply_Home_Service);
	connect(m_pFriendNoticeService, &FriendNoticeService::showAcceptFriendApplyAns_Home_Service, this, &HomeService::showAcceptFriendApplyAns_Home_Service);
	connect(m_pFriendService, &FriendService::showFriendship_Home_Service, this, &HomeService::showFriendship_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::sendMessage_Home_Service, this, &HomeService::sendMessage_Home_Service);
	connect(m_pFriendService, &FriendService::sendMessageApply_Home_Service, this, &HomeService::sendMessageApply_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::getMessageLst_Home_Service, this, &HomeService::getMessageLst_Home_Service);
	connect(m_pMessageService, &MessageService::showMessageLst_Home_Service, this, &HomeService::showMessageLst_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::getMessageInformation_Home_Service, this, &HomeService::getMessageInformation_Home_Service);
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

void HomeService::addFriendAns_Home_Service(enApplyType errnoType)
{
	m_pHomeWgt->showAddFriendAns(errnoType);
}

void HomeService::showFriendNotice(json& js)
{
	m_pFriendNoticeService->showFriendNotice(js);
}

void HomeService::showFriendNotice_Home_Service(std::vector<User>& arrApplyUser, std::vector<User>& arrAppliedUser, std::vector<std::string>& arrApplyTime, std::vector<std::string>& arrAppliedTime)
{
	m_pHomeWgt->showFriendNotice(arrApplyUser, arrAppliedUser, arrApplyTime, arrAppliedTime);
}

void HomeService::acceptFriendApply_Home_Service(QString& userid)
{
	m_pFriendNoticeService->acceptFriendApply(userid);
}

void HomeService::showAcceptFriendApplyAns(json& js)
{
	m_pFriendNoticeService->showAcceptFriendApplyAns(js);
}

void HomeService::showAcceptFriendApplyAns_Home_Service(enAcceptApplyType errnoType)
{
	m_pHomeWgt->showAcceptFriendApplyAns(errnoType);
}

void HomeService::showFriendship(json& js)
{
	m_pFriendService->showFriendship(js);
}

void HomeService::showFriendship_Home_Service(std::vector<User>& arrUser)
{
	m_pHomeWgt->showFriendship(arrUser);
}

void HomeService::sendMessage_Home_Service(QString& userid)
{
	m_pFriendService->sendMessage(userid);
}

void HomeService::sendMessageApplyAck(json& js)
{
	m_pFriendService->sendMessageApplyAck(js);
}

void HomeService::sendMessageApply_Home_Service()
{
	m_pHomeWgt->showMessageWgt();
}

void HomeService::getMessageLst_Home_Service()
{
	m_pMessageService->getMessageLst();
}

void HomeService::getMessageLstAck(json& js)
{
	m_pMessageService->getMessageLstAck(js);
}

void HomeService::showMessageLst_Home_Service(std::map<std::string, User>& mapTimeUser)
{
	m_pHomeWgt->showMessageLst(mapTimeUser);
}

void HomeService::getMessageInformation_Home_Service(QString& friendUserid)
{
	m_pMessageWindowService->getMessageInformation(friendUserid);
}

void HomeService::getChatMessageAck(json& js)
{
	m_pMessageWindowService->getChatMessageAck(js);
}
