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

signals:
	void showChatMessage_Home_Service(std::vector<Message*> arrMessage);
};
#endif
