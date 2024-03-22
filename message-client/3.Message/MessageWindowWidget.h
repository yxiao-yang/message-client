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

	void getMessageInformation(QString& friendUserid);

	void showChatMessage(std::vector<Message*> arrMessage);

signals:
	void getMessageInformation_Message_Wgt(QString& friendUserid);

private:
	Ui::MessageWindowWgt* m_pUi = nullptr;

	void dealMessage(MessageWindowLstItemWgt* messageW, QListWidgetItem* item, QString text, QString time, MessageWindowLstItemWgt::User_Type type);
	void dealMessageTime(QString curMsgTime);
};

#endif