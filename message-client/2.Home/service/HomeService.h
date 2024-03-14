#ifndef _HOME_SERVICE_H_
#define _HOME_SERVICE_H_

#include "HomeWidget.h"
#include "json.hpp"
#include "MessageService.h"
#include "FriendService.h"
#include "AddFriendService.h"
#include "FriendNoticeService.h"
#include "MessageWindowService.h"
#include "pub.const.h"

using json = nlohmann::json;

class HomeService : public QObject
{
	Q_OBJECT
public:
	HomeService();

	void showHomeWgt();
	void search_ack(json& js);
	void addFriendAns(json& js);
	void showFriendNotice(json& js);
	void showAcceptFriendApplyAns(json& js);
	void showFriendship(json& js);
	void sendMessageApplyAck(json& js);
	void getMessageLstAck(json& js);
	void getChatMessageAck(json& js);

public slots:
	void searchUser_Home_Service(QString& Userid, QString& Searchid);
	void showSearchRes_Home_Service(std::vector<User>& arrUser);
	void getFriendNotice_Home_Service();
	void addFriend_Home_Service(QString& userid);
	void getFriendship_Home_Service();
	void addFriendAns_Home_Service(enApplyType errnoType);
	void showFriendNotice_Home_Service(std::vector<User>& arrApplyUser, std::vector<User>& arrAppliedUser, std::vector<std::string>& arrApplyTime, std::vector<std::string>& arrAppliedTime);
	void acceptFriendApply_Home_Service(QString& userid);
	void showAcceptFriendApplyAns_Home_Service(enAcceptApplyType errnoType);
	void showFriendship_Home_Service(std::vector<User>& arrUser);
	void sendMessage_Home_Service(QString& userid);
	void sendMessageApply_Home_Service();
	void getMessageLst_Home_Service();
	void showMessageLst_Home_Service(std::map<std::string, User>& mapTimeUser);
	void getMessageInformation_Home_Service(QString& friendUserid);

private:
	HomeWidget* m_pHomeWgt = nullptr;
	MessageService* m_pMessageService = nullptr;
	FriendService* m_pFriendService = nullptr;
	AddFriendService* m_pAddFriendService = nullptr;
	FriendNoticeService* m_pFriendNoticeService = nullptr;
	MessageWindowService* m_pMessageWindowService = nullptr;

	void setSlots();
};

#endif
