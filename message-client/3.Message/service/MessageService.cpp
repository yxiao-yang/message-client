#include "MessageService.h"
#include "pub.const.h"
#include "pub.cache.h"
#include "ConnectServer.h"
#include "user.hpp"
#include "group.hpp"
#include <QDebug>

MessageService::MessageService()
{

}

MessageService::~MessageService()
{

}

void MessageService::getMessageLst()
{
	json js;
	js["msgid"] = GET_MESSAGELST_MSG;
	std::string userID;
	if (PubCache::getInstance()->getUserid(userID))
	{
		js["UserID"] = userID;
	}
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send GET_FRIENDSHIP_MSG fail";
	}
	else
	{
		qDebug() << "send GET_FRIENDSHIP_MSG success";
	}
}

void MessageService::getMessageLstAck(json& js)
{
	std::vector<std::string> arrUserJson;
	std::vector<std::string> arrGroupJson;
	std::map<std::string, User> mapTimeUser;
	std::map<std::string, Group> mapTimeGroup;

	arrUserJson = js["Users"];
	for (int i = 0; i < arrUserJson.size(); ++i)
	{
		json js = json::parse(arrUserJson[i]);
		User user;
		user.setId(js["Userid"]);
		user.setName(js["Username"]);
		user.setState(js["State"]);
		mapTimeUser[js["LastTime"]] = user;
	}

	arrGroupJson = js["Groups"];
	for (int i = 0; i < arrGroupJson.size(); ++i)
	{
		json js = json::parse(arrGroupJson[i]);
		Group group;
		group.setId(js["Groupid"]);
		group.setName(js["GroupName"]);
		mapTimeGroup[js["LastTime"]] = group;
	}

	emit showMessageLst_Home_Service(mapTimeUser, mapTimeGroup);
}
