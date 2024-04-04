#ifndef _MESSAGE_WINDOW_WIDGET_H_
#define _MESSAGE_WINDOW_WIDGET_H_

#include "ui_MessageWindowWidget.h"
#include "MessageWindowLstItemWidget.h"
#include "user.hpp"
#include "message.hpp"
#include "pub.const.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MessageWindowWgt; };
QT_END_NAMESPACE

class MessageWindowWgt : public QWidget
{
	Q_OBJECT
public:
	MessageWindowWgt(QWidget* parent = nullptr);
	~MessageWindowWgt();

	void setSlots();

	void getMessageInformation(QString& friendUserid);

	void showChatMessage(std::vector<Message*> arrMessage);

	void insertMessage(std::string& message, std::string& friendID, std::string& time, std::string& status);

	void setFriendNameLb(QString& friendName);

	void showTranslateRes(std::string& msg);

	void showBeautifyRes(std::string& msg);

signals:
	void getMessageInformation_Message_Wgt(QString& friendUserid);
	void sendFriendMessage_Message_Wgt(QString& msg, QString& userid, QString& friendid);
	void translateMessage_Message_Wgt(QString& msg);
	void beautifyMessage_Message_Wgt(QString& msg);
 
private slots:
	void onPbSend();
	void onTranslatePb();
	void onBeautifyPb();
	void onRestorePb();

private:
	Ui::MessageWindowWgt* m_pUi = nullptr;
	QString m_strFriendId;
	QString m_strOriginalMessage;

	void dealMessage(MessageWindowLstItemWgt* messageW, QListWidgetItem* item, QString text, QString time, MessageWindowLstItemWgt::User_Type type, bool isSending);
	void dealMessageTime(QString curMsgTime);
};

#endif