#ifndef _CHATAI_WINDOW_WIDGET_H_
#define _CHATAI_WINDOW_WIDGET_H_

#include "ui_ChatAiWindowWidget.h"
#include "ChatAiWindowLstItemWidget.h"
#include "user.hpp"
#include "message.hpp"
#include "pub.const.h"
#include "chatai_message.hpp"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ChatAiWindowWgt; };
QT_END_NAMESPACE

class ChatAiWindowWgt : public QWidget
{
	Q_OBJECT
public:
	ChatAiWindowWgt(QWidget* parent = nullptr);
	~ChatAiWindowWgt();

	void setSlots();

	void getMessageInformation(QString& friendUserid);

	void showChatAiMessage(std::vector<ChatAiMessage*> arrMessage);

	void insertMessage(std::string& message);

signals:
	void getChatAiMessageInformation_ChatAi_Wgt(QString& contentid);
	void sendChatAiMessage_ChatAi_Wgt(QString& msg, QString& contentid);
 
private slots:
	void onPbSend();

private:
	Ui::ChatAiWindowWgt* m_pUi = nullptr;
	QString m_strContentId;

	void dealMessage(ChatAiWindowLstItemWgt* messageW, QListWidgetItem* item, QString text, ChatAiWindowLstItemWgt::User_Type type, bool isSending);
};

#endif