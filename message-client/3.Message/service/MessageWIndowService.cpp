#include "MessageWindowService.h"
#include "pub.const.h"
#include "pub.cache.h"
#include "ConnectServer.h"
#include "message.hpp"
#include <QDebug>

MessageWindowService::MessageWindowService()
{

}

MessageWindowService::~MessageWindowService()
{

}

void MessageWindowService::getMessageInformation(QString& friendUserid)
{
	json js;
	js["msgid"] = GET_CHAT_MESSAGE_MSG;
	std::string userID;
	if (PubCache::getInstance()->getUserid(userID))
	{
		js["UserID"] = userID;
	}
	js["FriendUserID"] = friendUserid.toStdString();
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send GET_CHAT_MESSAGE_MSG fail";
	}
	else
	{
		qDebug() << "send GET_CHAT_MESSAGE_MSG success";
	}
}

void MessageWindowService::getChatMessageAck(json& js)
{
	std::vector<std::string> arrMessageJson;
	std::vector<Message*> arrMessage;
	arrMessageJson = js["Messages"];
	for (int i = 0; i < arrMessageJson.size(); ++i)
	{
		json js = json::parse(arrMessageJson[i]);
		Message* message = new Message();
		message->setMessageId(js["MessageId"]);
		message->setSenderId(js["SenderId"]);
		message->setReceiverId(js["ReceiverId"]);
		message->setContent(js["Content"]);
		message->setSendTime(js["SendTime"]);
		arrMessage.push_back(message);
	}
}
