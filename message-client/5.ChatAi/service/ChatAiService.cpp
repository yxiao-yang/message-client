#include "ChatAiService.h"
#include "pub.const.h"
#include "pub.cache.h"
#include "ConnectServer.h"
#include "user.hpp"
#include "chatai_message.hpp"
#include <QDebug>

ChatAiService::ChatAiService()
{

}

ChatAiService::~ChatAiService()
{

}

void ChatAiService::getChatAiLst()
{
	json js;
	js["msgid"] = GET_CHAT_AI_LST_MSG;
	std::string userID;
	if (PubCache::getInstance()->getUserid(userID))
	{
		js["UserID"] = userID;
	}
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send GET_CHAT_AI_LST_MSG fail";
	}
	else
	{
		qDebug() << "send GET_CHAT_AI_LST_MSG success";
	}
}

void ChatAiService::getChatAiLstAck(json& js)
{
	std::map<std::string, std::string> mapContentIdTime = js["mapContentIdTime"];
	
	emit showChatAiLst_Home_Service(mapContentIdTime);
}

void ChatAiService::startNewChat()
{
	json js;
	js["msgid"] = START_NEW_AI_CHAT_MSG;
	std::string userID;
	if (PubCache::getInstance()->getUserid(userID))
	{
		js["UserID"] = userID;
	}
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send START_NEW_AI_CHAT_MSG fail";
	}
	else
	{
		qDebug() << "send START_NEW_AI_CHAT_MSG success";
	}
}

void ChatAiService::startNewChatAck(json& js)
{
	std::string contentid = js["ContentId"];
	emit showNewAiChat_Home_Service(contentid);
}

void ChatAiService::getChatAiMessageInformation(QString& contentid)
{
	json js;
	js["msgid"] = GET_CHAT_AI_MESSAGE_INFORMATION_MSG;
	js["ContentId"] = contentid.toStdString();
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send GET_CHAT_AI_MESSAGE_INFORMATION_MSG fail";
	}
	else
	{
		qDebug() << "send GET_CHAT_AI_MESSAGE_INFORMATION_MSG success";
	}
}

void ChatAiService::getChatAiMessageInformationAck(json& js)
{
	std::vector<ChatAiMessage*> arrMessage;
	std::vector<std::string> arrMessageJson;
	arrMessageJson = js["Messages"];
	for (int i = 0; i < arrMessageJson.size(); ++i)
	{
		json js2 = json::parse(arrMessageJson[i]);
		ChatAiMessage* message = new ChatAiMessage();
		message->setMessage(js2["Message"]);
		message->setType(js2["isUser"]); 
		arrMessage.push_back(message);
	}

	emit showChatAiMessage_Home_Service(arrMessage);
}

void ChatAiService::sendChatAiMessage(QString& msg, QString& contentid)
{
	json js;
	js["msgid"] = SEND_CHAT_AI_MSG;
	js["ContentId"] = contentid.toStdString();
	js["Message"] = msg.toStdString();
	std::string userID;
	if (PubCache::getInstance()->getUserid(userID))
	{
		js["UserID"] = userID;
	}
	std::string strRequest = js.dump();

	int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
	if (len == -1)
	{
		qDebug() << "send SEND_CHAT_AI_MSG fail";
	}
	else
	{
		qDebug() << "send SEND_CHAT_AI_MSG success";
	}
}

void ChatAiService::sendChatAiMessageAck(json& js)
{
	std::string str1 = js["Contentid"];
	std::string str2 = js["Message"];
	QString contentid = QString::fromStdString(str1);
	QString message = QString::fromStdString(str2);

	emit showNewChatAiMessage_Home_Service(message, contentid);
}
