#ifndef _FRIEND_SERVICE_H_
#define _FRIEND_SERVICE_H_

#include "MessageWidget.h"
#include "json.hpp"

using json = nlohmann::json;

class FriendService : public QObject
{
	Q_OBJECT
public:
	FriendService();
	~FriendService();

	void getFriendship();

	void showFriendship(json& js);

signals:
	void showFriendship_Home_Service(std::vector<User>& arrUser);
};
#endif
