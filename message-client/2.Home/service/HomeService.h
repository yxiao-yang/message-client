#ifndef _HOME_SERVICE_H_
#define _HOME_SERVICE_H_

#include "HomeWidget.h"
#include "json.hpp"
#include "MessageService.h"
#include "FriendService.h"
#include "AddFriendService.h"

using json = nlohmann::json;

class HomeService : public QObject
{
	Q_OBJECT
public:
	HomeService();

	void showHomeWgt();
	void search_ack(json& js);

public slots:
	void searchUser_Home_Service(QString& Userid, QString& Searchid);
	void showSearchRes_Home_Service(std::vector<User>& arrUser);

private:
	HomeWidget* m_pHomeWgt = nullptr;
	MessageService* m_pMessageService = nullptr;
	FriendService* m_pFriendService = nullptr;
	AddFriendService* m_pAddFriendService = nullptr;

	void setSlots();
};

#endif
