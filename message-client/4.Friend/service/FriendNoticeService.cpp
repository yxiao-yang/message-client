#include "FriendNoticeService.h"
#include "pub.const.h"
#include "pub.cache.h"
#include "user.hpp"
#include "ConnectServer.h"
#include <QDebug>

#pragma execution_character_set("utf-8")

FriendNoticeService::FriendNoticeService()
{

}

FriendNoticeService::~FriendNoticeService()
{

}

void FriendNoticeService::getFriendNotice()
{
	User* user = PubCache::getInstance()->getUser();
	json js;
	js["msgid"] = FRIEND_NOTICE_MSG;
	js["Userid"] = user->getId();
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send FRIEND_NOTICE_MSG fail";
	}
	else
	{
		qDebug() << "send FRIEND_NOTICE_MSG success";
	}
}

void FriendNoticeService::showFriendNotice(json& js)
{
	std::vector<User> arrUser;
	std::vector<std::string> arrUserJson;
	arrUserJson = js["users"];
	for (int i = 0; i < arrUserJson.size(); ++i)
	{
		json js = json::parse(arrUserJson[i]);
		User user;
		user.setId(js["Userid"]);
		user.setName(js["Username"]);
		arrUser.push_back(user);
	}

	emit showFriendNotice_Home_Service(arrUser);
}