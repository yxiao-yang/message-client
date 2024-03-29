#ifndef _CHATAI_SERVICE_H_
#define _CHATAI_SERVICE_H_

#include <QWidget>
#include "json.hpp"
#include "chatai_message.hpp"

using json = nlohmann::json;

class ChatAiService : public QObject
{
	Q_OBJECT
public:
	ChatAiService();
	~ChatAiService();

	void getChatAiLst();
	void getChatAiLstAck(json& js);

	void startNewChat();
	void startNewChatAck(json& js);

	void getChatAiMessageInformation(QString& contentid);
	void getChatAiMessageInformationAck(json& js);

	void sendChatAiMessage(QString& msg, QString& contentid);
	void sendChatAiMessageAck(json& js);

signals:
	void showChatAiLst_Home_Service(std::map<std::string, std::string>& mapContentIdTime);
	void showNewAiChat_Home_Service(std::string& contentid);
	void showChatAiMessage_Home_Service(std::vector<ChatAiMessage*>& arrMessage);
	void showNewChatAiMessage_Home_Service(QString& msg, QString& contentid);
};
#endif
