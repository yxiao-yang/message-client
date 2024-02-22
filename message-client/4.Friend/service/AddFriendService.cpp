#include "AddFriendService.h"
#include "pub.const.h"
#include "pub.cache.h"
#include "user.hpp"
#include "ConnectServer.h"

#pragma execution_character_set("utf-8")

AddFriendService::AddFriendService()
{

}

AddFriendService::~AddFriendService()
{

}

void AddFriendService::searchUser(QString& Userid, QString& Searchid)
{
	json js;
	js["msgid"] = SEARCH_USER_MSG;
	js["Userid"] = Userid.toStdString();
	js["Searchid"] = Searchid.toStdString();
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send SEARCH_USER_MSG fail";
	}
	else
	{
		qDebug() << "send SEARCH_USER_MSG success";
	}
}

void AddFriendService::searchUserAns(json& js)
{
	enSearchType errnoType = js["errno"];
	if (errnoType == SEARCH_SUCCESS)
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
			user.setPhone(js["Telephone"]);
			user.setTime(js["Time"]);
			arrUser.push_back(user);
		}
		emit showSearchRes_Home_Service(arrUser);
	} 
	else
	{
		qDebug() << "search_fail";
	}
}

void AddFriendService::addFriend(QString& userid)
{
	json js;
	js["msgid"] = ADD_FRIEND_MSG;
	std::string user1id;
	if (PubCache::getInstance()->getUserid(user1id))
	{
		js["User1ID"] = user1id;
	}
	js["User2ID"] = userid.toStdString();
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send ADD_FRIEND_MSG fail";
	}
	else
	{
		qDebug() << "send ADD_FRIEND_MSG success";
	}
}

void AddFriendService::addFriendAns(json& js)
{
	enApplyType errnoType = js["errno"];
	emit addFriendAns_Home_Service(errnoType);
}
