#include "GroupService.h"
#include "pub.const.h"
#include "pub.cache.h"
#include "ConnectServer.h"
#include "user.hpp"
#include "group.hpp"
#include <QDebug>

#pragma execution_character_set("utf-8")

GroupService::GroupService()
{

}

GroupService::~GroupService()
{

}

void GroupService::getGroupLst()
{
	json js;
	js["msgid"] = GET_GROUPLST_MSG;
	std::string userID;
	if (PubCache::getInstance()->getUserid(userID))
	{
		js["UserID"] = userID;
	}
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send GET_GROUPLST_MSG fail";
	}
	else
	{
		qDebug() << "send GET_GROUPLST_MSG success";
	}
}

void GroupService::getGroupLstAck(json& js)
{
	std::vector<Group> arrGroup;
	std::vector<std::string> arrGroupJson;
	arrGroupJson = js["Groups"];
	for (int i = 0; i < arrGroupJson.size(); ++i)
	{
		json js = json::parse(arrGroupJson[i]);
		Group group;
		group.setId(js["GroupId"]);
		group.setName(js["GroupName"]);
		arrGroup.push_back(group);
	}
	emit showGroupLst_Home_Service(arrGroup);
}

void GroupService::sendGroupMessage(QString& groupid)
{
	json js;
	js["msgid"] = SEND_MESSAGE_MSG;
	std::string userID;
	if (PubCache::getInstance()->getUserid(userID))
	{
		js["UserID"] = userID;
	}
	js["FriendID"] = groupid.toStdString();
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send SEND_GROUP_MESSAGE_MSG fail";
	}
	else
	{
		qDebug() << "send SEND_GROUP_MESSAGE_MSG success";
	}
}
