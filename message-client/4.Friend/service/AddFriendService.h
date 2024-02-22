#ifndef _ADD_FRIEND_SERVICE_H_
#define _ADD_FRIEND_SERVICE_H_

#include "MessageWidget.h"
#include "json.hpp"
#include "user.hpp"
#include "pub.const.h"

using json = nlohmann::json;

class AddFriendService : public QObject
{
	Q_OBJECT
public:
	AddFriendService();
	~AddFriendService();

	void searchUser(QString& Userid, QString& Searchid);
	void searchUserAns(json& js);
	void addFriend(QString& userid);
	void addFriendAns(json& js);
signals:
	void showSearchRes_Home_Service(std::vector<User>& arrUser);
	void addFriendAns_Home_Service(enApplyType errnoType);
};
#endif
