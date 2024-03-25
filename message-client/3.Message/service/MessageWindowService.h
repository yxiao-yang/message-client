#ifndef _MESSAGE_WINDOW_SERVICE_H_
#define _MESSAGE_WINDOW_SERVICE_H_

#include "json.hpp"
#include "message.hpp"
#include <QWidget>

using json = nlohmann::json;

class MessageWindowService : public QObject
{
	Q_OBJECT
public:
	MessageWindowService();
	~MessageWindowService();

	void getMessageInformation(QString& friendUserid);

	void getChatMessageAck(json& js);

	void sendFriendMessage(QString& msg, QString& userid, QString& friendid);

	void getFriendMessageAck(json& js);

	void sendFriendMessageAck(json& js);

signals:
	void showChatMessage_Home_Service(std::vector<Message*> arrMessage);

	void showFriendMessage_Home_Service(std::string& message, std::string& friendID, std::string& time, std::string& status);

	void refreshMessageLst_Home_Service();
};
#endif
