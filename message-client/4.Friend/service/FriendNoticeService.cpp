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
	std::vector<User> arrApplyUser;
	std::vector<User> arrAppliedUser;
	std::vector<std::string> arrApplyTime;
	std::vector<std::string> arrAppliedTime;
	std::vector<std::string> arrUserApplyJson;
	std::vector<std::string> arrUserAppliedJson;
	arrUserApplyJson = js["ApplyUsers"];
	arrUserAppliedJson = js["AppliedUsers"];
	for (int i = 0; i < arrUserApplyJson.size(); ++i)
	{
		json js = json::parse(arrUserApplyJson[i]);
		User user;
		user.setId(js["Userid"]);
		user.setName(js["Username"]);
		arrApplyUser.push_back(user);
		std::string applyTime = js["ApplyTime"];
		arrApplyTime.push_back(applyTime);
	}

	for (int i = 0; i < arrUserAppliedJson.size(); ++i)
	{
		json js = json::parse(arrUserAppliedJson[i]);
		User user;
		user.setId(js["Userid"]);
		user.setName(js["Username"]);
		arrAppliedUser.push_back(user);
		std::string applyTime = js["ApplyTime"];
		arrAppliedTime.push_back(applyTime);
	}

	emit showFriendNotice_Home_Service(arrApplyUser, arrAppliedUser, arrApplyTime, arrAppliedTime);
}