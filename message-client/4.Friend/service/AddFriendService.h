#ifndef _ADD_FRIEND_SERVICE_H_
#define _ADD_FRIEND_SERVICE_H_

#include "MessageWidget.h"
#include "json.hpp"
#include "user.hpp"

using json = nlohmann::json;

class AddFriendService : public QObject
{
	Q_OBJECT
public:
	AddFriendService();
	~AddFriendService();

	void searchUser(QString& Userid, QString& Searchid);
	void searchUserAns(json& js);
signals:
	void showSearchRes_Home_Service(std::vector<User>& arrUser);
};
#endif
