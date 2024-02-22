#include "FriendService.h"
#include "pub.const.h"
#include "pub.cache.h"
#include "ConnectServer.h"
#include "user.hpp"
#include <QDebug>

#pragma execution_character_set("utf-8")

FriendService::FriendService()
{

}

FriendService::~FriendService()
{

}

void FriendService::getFriendship()
{
	json js;
	js["msgid"] = GET_FRIENDSHIP_MSG;
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

void FriendService::showFriendship(json& js)
{
	std::vector<User> arrUser;
	std::vector<std::string> arrUserJson;
	arrUserJson = js["Users"];
	for (int i = 0; i < arrUserJson.size(); ++i)
	{
		json js = json::parse(arrUserJson[i]);
		User user;
		user.setId(js["Userid"]);
		user.setName(js["Username"]);
		user.setState(js["State"]);
		arrUser.push_back(user);
	}
	emit showFriendship_Home_Service(arrUser);
}

void FriendService::sendMessage(QString& userid)
{
	// 发送服务端，在消息列表最上方插入新聊天
	json js;
	js["msgid"] = SEND_MESSAGE_MSG;
	std::string userID;
	if (PubCache::getInstance()->getUserid(userID))
	{
		js["UserID"] = userID;
	}
	js["FriendID"] = userid.toStdString();
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send SEND_MESSAGE_MSG fail";
	}
	else
	{
		qDebug() << "send SEND_MESSAGE_MSG success";
	}
}

void FriendService::sendMessageApplyAck(json& js)
{
	enApplyType errnoType = js["errno"];
	if (errnoType == APPLY_SUCCESS)
	{
		// 切换到消息页面
		emit sendMessageApply_Home_Service();
	}
	else
	{
		qDebug() << "sendMessageApplyAck fail";
	}
}
