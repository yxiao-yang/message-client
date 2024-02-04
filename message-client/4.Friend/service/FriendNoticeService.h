#ifndef _FRIEND_NOTICE_SERVICE_H_
#define _FRIEND_NOTICE_SERVICE_H_

#include <QWidget>
#include "json.hpp"
#include "user.hpp"

using json = nlohmann::json;

class FriendNoticeService : public QObject
{
	Q_OBJECT
public:
	FriendNoticeService();
	~FriendNoticeService();

	void getFriendNotice();
};
#endif
