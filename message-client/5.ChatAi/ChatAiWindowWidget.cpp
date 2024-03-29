#include "ChatAiWindowWidget.h"
#include "ChatAiWindowLstItemWidget.h"
#include "pub.cache.h"
#include <qDebug>
#include <QDateTime>

#pragma execution_character_set("utf-8")

ChatAiWindowWgt::ChatAiWindowWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::ChatAiWindowWgt())
{
	m_pUi->setupUi(this);
	setSlots();

	m_pUi->ChatAiWindowLstWgt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	m_pUi->ChatAiWindowLstWgt->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

ChatAiWindowWgt::~ChatAiWindowWgt()
{
	delete m_pUi;
}

void ChatAiWindowWgt::setSlots()
{
	connect(m_pUi->pbSend, &QPushButton::clicked, this, &ChatAiWindowWgt::onPbSend);
}

void ChatAiWindowWgt::getMessageInformation(QString& contentid)
{
	m_pUi->ChatAiWindowLstWgt->clear();
	m_strContentId = contentid;
	emit getChatAiMessageInformation_ChatAi_Wgt(contentid);
}

void ChatAiWindowWgt::showChatAiMessage(std::vector<ChatAiMessage*> arrMessage)
{
	for (int i = 0; i < arrMessage.size(); ++i)
	{
		QString msg = QString::fromStdString(arrMessage[i]->getMessage());
		ChatAiWindowLstItemWgt::User_Type type;
		if (arrMessage[i]->getType())
		{
			type = ChatAiWindowLstItemWgt::User_Me;
		} 
		else
		{
			type = ChatAiWindowLstItemWgt::User_Friend;
		}
		QListWidgetItem* pItem = new QListWidgetItem(m_pUi->ChatAiWindowLstWgt);
		ChatAiWindowLstItemWgt* pCustomItem = new ChatAiWindowLstItemWgt(m_pUi->ChatAiWindowLstWgt->parentWidget());
		dealMessage(pCustomItem, pItem, msg, type, false);
	}
	m_pUi->ChatAiWindowLstWgt->scrollToBottom();
}

void ChatAiWindowWgt::dealMessage(ChatAiWindowLstItemWgt* messageW, QListWidgetItem* item, QString text, ChatAiWindowLstItemWgt::User_Type type, bool isSending)
{
	messageW->setFixedWidth(this->width());
	QSize size = messageW->fontRect(text);
	item->setSizeHint(size);
	messageW->setText(text, size, type);
	if (!isSending)
	{
		messageW->setTextSuccess();
	}
	m_pUi->ChatAiWindowLstWgt->setItemWidget(item, messageW);
}

void ChatAiWindowWgt::onPbSend()
{
	QString msg = m_pUi->InputTedit->toPlainText();
	m_pUi->InputTedit->setText("");

	if (msg != "")
	{
		ChatAiWindowLstItemWgt* messageW = new ChatAiWindowLstItemWgt(m_pUi->ChatAiWindowLstWgt->parentWidget());
		QListWidgetItem* item = new QListWidgetItem(m_pUi->ChatAiWindowLstWgt);
		dealMessage(messageW, item, msg, ChatAiWindowLstItemWgt::User_Me, false);
		m_pUi->ChatAiWindowLstWgt->scrollToBottom();

		std::string id;
		PubCache::getInstance()->getUserid(id);
		QString userid = QString::fromStdString(id);
		emit sendChatAiMessage_ChatAi_Wgt(msg, m_strContentId);
	}
}

void ChatAiWindowWgt::insertMessage(std::string& message)
{
	QString message_q = QString::fromStdString(message);
	ChatAiWindowLstItemWgt* messageW = new ChatAiWindowLstItemWgt(m_pUi->ChatAiWindowLstWgt->parentWidget());
	QListWidgetItem* item = new QListWidgetItem(m_pUi->ChatAiWindowLstWgt);
	dealMessage(messageW, item, message_q, ChatAiWindowLstItemWgt::User_Friend, true);
	m_pUi->ChatAiWindowLstWgt->scrollToBottom();
}
