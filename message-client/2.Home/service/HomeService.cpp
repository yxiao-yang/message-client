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
	m_pChatAiService = new ChatAiService();
	m_pCreateGroupService = new CreateGroupService();
	m_pGroupService = new GroupService();
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
	connect(m_pMessageWindowService, &MessageWindowService::showChatMessage_Home_Service, this, &HomeService::showChatMessage_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::sendFriendMessage_Home_Service, this, &HomeService::sendFriendMessage_Home_Service);
	connect(m_pMessageWindowService, &MessageWindowService::showFriendMessage_Home_Service, this, &HomeService::showFriendMessage_Home_Service);
	connect(m_pMessageWindowService, &MessageWindowService::refreshMessageLst_Home_Service, this, &HomeService::refreshMessageLst_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::getChatAiLst_Home_Service, this, &HomeService::getChatAiLst_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::startNewChat_Home_Service, this, &HomeService::startNewChat_Home_Service);
	connect(m_pChatAiService, &ChatAiService::showNewAiChat_Home_Service, this, &HomeService::showNewAiChat_Home_Service);
	connect(m_pChatAiService, &ChatAiService::showChatAiLst_Home_Service, this, &HomeService::showChatAiLst_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::getChatAiMessageInformation_Home_Service, this, &HomeService::getChatAiMessageInformation_Home_Service);
	connect(m_pChatAiService, &ChatAiService::showChatAiMessage_Home_Service, this, &HomeService::showChatAiMessage_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::sendChatAiMessage_Home_Service, this, &HomeService::sendChatAiMessage_Home_Service);
	connect(m_pChatAiService, &ChatAiService::showNewChatAiMessage_Home_Service, this, &HomeService::showNewChatAiMessage_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::translateMessage_Home_Service, this, &HomeService::translateMessage_Home_Service);
	connect(m_pMessageWindowService, &MessageWindowService::showTranslateRes_Home_Service, this, &HomeService::showTranslateRes_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::beautifyMessage_Home_Service, this, &HomeService::beautifyMessage_Home_Service);
	connect(m_pMessageWindowService, &MessageWindowService::showBeautifyRes_Home_Service, this, &HomeService::showBeautifyRes_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::createGroup_Home_Service, this, &HomeService::createGroup_Home_Service);
	connect(m_pCreateGroupService, &CreateGroupService::showCreateGroupAck_Home_Service, this, &HomeService::showCreateGroupAck_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::getGroupLst_Home_Service, this, &HomeService::getGroupLst_Home_Service);
	connect(m_pGroupService, &GroupService::showGroupLst_Home_Service, this, &HomeService::showGroupLst_Home_Service);
	connect(m_pHomeWgt, &HomeWidget::sendGroupMessage_Home_Service, this, &HomeService::sendGroupMessage_Home_Service);
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

void HomeService::showMessageLst_Home_Service(std::map<std::string, User>& mapTimeUser, std::map<std::string, Group>& mapTimeGroup)
{
	m_pHomeWgt->showMessageLst(mapTimeUser, mapTimeGroup);
}

void HomeService::getMessageInformation_Home_Service(QString& friendUserid)
{
	m_pMessageWindowService->getMessageInformation(friendUserid);
}

void HomeService::getChatMessageAck(json& js)
{
	m_pMessageWindowService->getChatMessageAck(js);
}

void HomeService::showChatMessage_Home_Service(std::vector<Message*> arrMessage)
{
	m_pHomeWgt->showChatMessage(arrMessage);
}

void HomeService::sendFriendMessage_Home_Service(QString& msg, QString& userid, QString& friendid)
{
	m_pMessageWindowService->sendFriendMessage(msg, userid, friendid);
}

void HomeService::getFriendMessageAck(json& js)
{
	m_pMessageWindowService->getFriendMessageAck(js);
}

void HomeService::showFriendMessage_Home_Service(std::string& message, std::string& friendID, std::string& time, std::string& status)
{
	m_pHomeWgt->getNewFriendMessage(message, friendID, time, status);
}

void HomeService::sendFriendMessageAck(json& js)
{
	m_pMessageWindowService->sendFriendMessageAck(js);
}

void HomeService::refreshMessageLst_Home_Service()
{
	m_pHomeWgt->getNewMessageLst();
}

void HomeService::getChatAiLst_Home_Service()
{
	m_pChatAiService->getChatAiLst();
}

void HomeService::getChatAiLstAck(json& js)
{
	m_pChatAiService->getChatAiLstAck(js);
}

void HomeService::showChatAiLst_Home_Service(std::map<std::string, std::string>& mapContentIdTime)
{
	m_pHomeWgt->showChatAiLst(mapContentIdTime);
}

void HomeService::startNewChat_Home_Service()
{
	m_pChatAiService->startNewChat();
}

void HomeService::startNewChatAck(json& js)
{
	m_pChatAiService->startNewChatAck(js);
}

void HomeService::showNewAiChat_Home_Service(std::string& contentid)
{
	m_pHomeWgt->showNewAiChat(contentid);
}

void HomeService::getChatAiMessageInformation_Home_Service(QString& contentid)
{
	m_pChatAiService->getChatAiMessageInformation(contentid);
}

void HomeService::getChatAiMessageInformationAck(json& js)
{
	m_pChatAiService->getChatAiMessageInformationAck(js);
}

void HomeService::showChatAiMessage_Home_Service(std::vector<ChatAiMessage*>& arrMessage)
{
	m_pHomeWgt->showChatAiMessage(arrMessage);
}

void HomeService::sendChatAiMessage_Home_Service(QString& msg, QString& contentid)
{
	m_pChatAiService->sendChatAiMessage(msg, contentid);
}

void HomeService::sendChatAiMessageAck(json& js)
{
	m_pChatAiService->sendChatAiMessageAck(js);
}

void HomeService::showNewChatAiMessage_Home_Service(QString& msg, QString& contentid)
{
	m_pHomeWgt->showNewChatAiMessage(msg, contentid);
}

void HomeService::translateMessage_Home_Service(QString& msg)
{
	m_pMessageWindowService->translateMessage(msg);
}

void HomeService::translateMessageAck(json& js)
{
	m_pMessageWindowService->translateMessageAck(js);
}

void HomeService::showTranslateRes_Home_Service(std::string& msg)
{
	m_pHomeWgt->showTranslateRes(msg);
}

void HomeService::beautifyMessage_Home_Service(QString& msg)
{
	m_pMessageWindowService->beautifyMessage(msg);
}

void HomeService::beautifyMessageAck(json& js)
{
	m_pMessageWindowService->beautifyMessageAck(js);
}

void HomeService::showBeautifyRes_Home_Service(std::string& msg)
{
	m_pHomeWgt->showBeautifyRes(msg);
}

void HomeService::createGroup_Home_Service(QString& groupName, std::vector<User>& friendSelected)
{
	m_pCreateGroupService->createGroup(groupName, friendSelected);
}

void HomeService::createGroupAck(json& js)
{
	m_pCreateGroupService->createGroupAck(js);
}

void HomeService::showCreateGroupAck_Home_Service()
{
	m_pHomeWgt->showCreateGroupAck();
}

void HomeService::getGroupLst_Home_Service()
{
	m_pGroupService->getGroupLst();
}

void HomeService::getGroupLstAck(json& js)
{
	m_pGroupService->getGroupLstAck(js);
}

void HomeService::showGroupLst_Home_Service(std::vector<Group>& arrGroup)
{
	m_pHomeWgt->showGroupLst(arrGroup);
}

void HomeService::sendGroupMessage_Home_Service(QString& groupid)
{
	m_pGroupService->sendGroupMessage(groupid);
}
