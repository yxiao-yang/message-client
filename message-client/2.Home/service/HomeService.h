#ifndef _HOME_SERVICE_H_
#define _HOME_SERVICE_H_

#include "HomeWidget.h"
#include "json.hpp"
#include "MessageService.h"
#include "FriendService.h"
#include "AddFriendService.h"
#include "FriendNoticeService.h"
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

public slots:
	void searchUser_Home_Service(QString& Userid, QString& Searchid);
	void showSearchRes_Home_Service(std::vector<User>& arrUser);
	void getFriendNotice_Home_Service();
	void addFriend_Home_Service(QString& userid);
	void getFriendship_Home_Service();
	void addFriendAns_Home_Service(enAddFriendType errnoType);
	void showFriendNotice_Home_Service(std::vector<User>& arrApplyUser, std::vector<User>& arrAppliedUser, std::vector<std::string>& arrApplyTime, std::vector<std::string>& arrAppliedTime);

private:
	HomeWidget* m_pHomeWgt = nullptr;
	MessageService* m_pMessageService = nullptr;
	FriendService* m_pFriendService = nullptr;
	AddFriendService* m_pAddFriendService = nullptr;
	FriendNoticeService* m_pFriendNoticeService = nullptr;

	void setSlots();
};

#endif
