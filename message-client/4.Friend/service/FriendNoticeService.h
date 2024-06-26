#ifndef _FRIEND_NOTICE_SERVICE_H_
#define _FRIEND_NOTICE_SERVICE_H_

#include <QWidget>
#include "json.hpp"
#include "user.hpp"
#include "pub.const.h"

using json = nlohmann::json;

class FriendNoticeService : public QObject
{
	Q_OBJECT
public:
	FriendNoticeService();
	~FriendNoticeService();

	void getFriendNotice();
	void showFriendNotice(json& js);
	void acceptFriendApply(QString& userid);
	void showAcceptFriendApplyAns(json& js);

signals:
	void showFriendNotice_Home_Service(std::vector<User>& arrApplyUser, std::vector<User>& arrAppliedUser, std::vector<std::string>& arrApplyTime, std::vector<std::string>& arrAppliedTime);
	void showAcceptFriendApplyAns_Home_Service(enAcceptApplyType errnoType);
};
#endif
