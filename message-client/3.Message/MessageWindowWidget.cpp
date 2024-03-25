#include "MessageWindowWidget.h"
#include "MessageWindowLstItemWidget.h"
#include "pub.cache.h"
#include <qDebug>
#include <QDateTime>

#pragma execution_character_set("utf-8")

MessageWindowWgt::MessageWindowWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::MessageWindowWgt())
{
	m_pUi->setupUi(this);
	setSlots();

	m_pUi->MessageWindowLstWgt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	m_pUi->MessageWindowLstWgt->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MessageWindowWgt::~MessageWindowWgt()
{
	delete m_pUi;
}

void MessageWindowWgt::setSlots()
{
	connect(m_pUi->pbSend, &QPushButton::clicked, this, &MessageWindowWgt::onPbSend);
}

void MessageWindowWgt::getMessageInformation(QString& friendUserid)
{
	m_pUi->MessageWindowLstWgt->clear();
	m_strFriendId = friendUserid;
	emit getMessageInformation_Message_Wgt(friendUserid);
}

void MessageWindowWgt::showChatMessage(std::vector<Message*> arrMessage)
{
	for (int i = 0; i < arrMessage.size(); ++i)
	{
		QString time = QString::fromStdString(arrMessage[i]->getSendTime());
		QString msg = QString::fromStdString(arrMessage[i]->getContent());
		MessageWindowLstItemWgt::User_Type type;
		std::string userID;
		if (PubCache::getInstance()->getUserid(userID))
		{
			if (arrMessage[i]->getSenderId() == userID)
			{
				type = MessageWindowLstItemWgt::User_Me;
			}
			else
			{
				type = MessageWindowLstItemWgt::User_Friend;
			}
		}

		dealMessageTime(time);
		QListWidgetItem* pItem = new QListWidgetItem(m_pUi->MessageWindowLstWgt);
		MessageWindowLstItemWgt* pCustomItem = new MessageWindowLstItemWgt(m_pUi->MessageWindowLstWgt->parentWidget());
		dealMessage(pCustomItem, pItem, msg, time, type, false);
	}
	m_pUi->MessageWindowLstWgt->scrollToBottom();
}

void MessageWindowWgt::dealMessage(MessageWindowLstItemWgt* messageW, QListWidgetItem* item, QString text, QString time, MessageWindowLstItemWgt::User_Type type, bool isSending)
{
	messageW->setFixedWidth(this->width());
	QSize size = messageW->fontRect(text);
	item->setSizeHint(size);
	messageW->setText(text, time, size, type);
	if (!isSending)
	{
		messageW->setTextSuccess();
	}
	m_pUi->MessageWindowLstWgt->setItemWidget(item, messageW);
}

void MessageWindowWgt::dealMessageTime(QString curMsgTime)
{
	bool isShowTime = false;
	if (m_pUi->MessageWindowLstWgt->count() > 0)
	{
		QListWidgetItem* lastItem = m_pUi->MessageWindowLstWgt->item(m_pUi->MessageWindowLstWgt->count() - 1);
		MessageWindowLstItemWgt* messageW = (MessageWindowLstItemWgt*)m_pUi->MessageWindowLstWgt->itemWidget(lastItem);
		QString time1_t = messageW->getTime();
		QString time2_t = curMsgTime;
		time1_t.remove(-7, 7);
		time2_t.remove(-7, 7);
		QString time1 = QString::number(QDateTime::fromString(time1_t, "yyyy-MM-dd hh:mm:ss").toTime_t());
		QString time2 = QString::number(QDateTime::fromString(time2_t, "yyyy-MM-dd hh:mm:ss").toTime_t());
		int lastTime = time1.toInt();
		int curTime = time2.toInt();
		isShowTime = ((curTime - lastTime) > 60); // 两个消息相差一分钟
	}
	else
	{
		isShowTime = true;
	}
	if (isShowTime)
	{
		MessageWindowLstItemWgt* messageTime = new MessageWindowLstItemWgt(m_pUi->MessageWindowLstWgt->parentWidget());
		QListWidgetItem* itemTime = new QListWidgetItem(m_pUi->MessageWindowLstWgt);

		QSize size = QSize(this->width(), 40);
		messageTime->resize(size);
		itemTime->setSizeHint(size);
		messageTime->setText(curMsgTime, curMsgTime, size, MessageWindowLstItemWgt::User_Time);
		m_pUi->MessageWindowLstWgt->setItemWidget(itemTime, messageTime);
	}
}

void MessageWindowWgt::onPbSend()
{
	QString msg = m_pUi->InputTedit->toPlainText();
	m_pUi->InputTedit->setText("");
	//QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
	QString time = QString::fromStdString(PubCache::getInstance()->getCurrentDateTimeMySQLFormat());
	time.append(".000000");
	if (msg != "")
	{
		dealMessageTime(time);
		MessageWindowLstItemWgt* messageW = new MessageWindowLstItemWgt(m_pUi->MessageWindowLstWgt->parentWidget());
		QListWidgetItem* item = new QListWidgetItem(m_pUi->MessageWindowLstWgt);
		dealMessage(messageW, item, msg, time, MessageWindowLstItemWgt::User_Me, false);
		m_pUi->MessageWindowLstWgt->scrollToBottom();

		std::string id;
		PubCache::getInstance()->getUserid(id);
		QString userid = QString::fromStdString(id);
		emit sendFriendMessage_Message_Wgt(msg, userid, m_strFriendId);
	}
}

void MessageWindowWgt::insertMessage(std::string& message, std::string& friendID, std::string& time, std::string& status)
{
	QString time_q = QString::fromStdString(time);
	QString message_q = QString::fromStdString(message);
	time_q.append(".000000");
	dealMessageTime(time_q);
	MessageWindowLstItemWgt* messageW = new MessageWindowLstItemWgt(m_pUi->MessageWindowLstWgt->parentWidget());
	QListWidgetItem* item = new QListWidgetItem(m_pUi->MessageWindowLstWgt);
	dealMessage(messageW, item, message_q, time_q, MessageWindowLstItemWgt::User_Friend, true);
	m_pUi->MessageWindowLstWgt->scrollToBottom();
}
