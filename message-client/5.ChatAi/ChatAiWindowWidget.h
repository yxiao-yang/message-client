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

	void showTranslateRes(std::string& msg);

	void showBeautifyRes(std::string& msg);

signals:
	void getChatAiMessageInformation_ChatAi_Wgt(QString& contentid);
	void sendChatAiMessage_ChatAi_Wgt(QString& msg, QString& contentid);
	void translateMessage_ChatAi_Wgt(QString& msg);
	void beautifyMessage_ChatAi_Wgt(QString& msg);
 
private slots:
	void onPbSend();
	void onTranslatePb();
	void onBeautifyPb();
	void onRestorePb();

private:
	Ui::ChatAiWindowWgt* m_pUi = nullptr;
	QString m_strContentId;
	QString m_strOriginalMessage;

	void dealMessage(ChatAiWindowLstItemWgt* messageW, QListWidgetItem* item, QString text, ChatAiWindowLstItemWgt::User_Type type, bool isSending);
};

#endif