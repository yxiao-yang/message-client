#include "ChatAiWidget.h"
#include "ChatAiLstItemWidget.h"
#include "pub_func.hpp"
#include <QDebug>
#include <QMouseEvent>
#include <unordered_map>

#pragma execution_character_set("utf-8")

ChatAiWgt::ChatAiWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::ChatAiWgt())
{
	m_pUi->setupUi(this);

	m_pEmptyWgt = new QWidget;
	m_pChatAiWindowWgt = new ChatAiWindowWgt;
	m_pUi->ChatAiSWgt->insertWidget(CHATAI_EMPTY_WIDGET, m_pEmptyWgt);
	m_pUi->ChatAiSWgt->insertWidget(CHATAI_WINDOW_WIDGET, m_pChatAiWindowWgt);

	setSlots();
}

ChatAiWgt::~ChatAiWgt()
{
	delete m_pUi;
}

void ChatAiWgt::setSlots()
{
	connect(m_pUi->AddPb, &QPushButton::clicked, this, &ChatAiWgt::onAddPb);
	connect(m_pChatAiWindowWgt, &ChatAiWindowWgt::getChatAiMessageInformation_ChatAi_Wgt, this, &ChatAiWgt::getChatAiMessageInformation_ChatAi_Wgt);
	connect(m_pChatAiWindowWgt, &ChatAiWindowWgt::sendChatAiMessage_ChatAi_Wgt, this, &ChatAiWgt::sendChatAiMessage_ChatAi_Wgt);
}

void ChatAiWgt::switchChatAiSWgt(int idx)
{
	m_pUi->ChatAiSWgt->setCurrentIndex(idx);
}

void ChatAiWgt::getChatAiLst()
{
	// 清空结果
	for (int i = 0; i < m_arrChatAiLstItemWgt.size(); ++i)
	{
		m_pUi->ChatAiLstWgt->removeItemWidget(m_arrChatAiLstItemWgt[i]);

		delete m_arrChatAiLstItemWgt[i]; // 如果元素是 QWidget 类型
	}
	m_arrChatAiLstItemWgt.clear();

	emit getChatAiLst_Home_Wgt();
}

void ChatAiWgt::showChatAiLst(std::map<std::string, std::string>& mapContentIdTime)
{
	m_mapContentIdTime = mapContentIdTime;
	std::map<std::string, std::string>::reverse_iterator iter;
	for (iter = mapContentIdTime.rbegin(); iter != mapContentIdTime.rend(); ++iter)
	{
		// 创建item
		QListWidgetItem* pItem = new QListWidgetItem("");
		m_pUi->ChatAiLstWgt->addItem(pItem);

		// 创建自定义widget
		ChatAiLstItemWgt* pCustomItem = new ChatAiLstItemWgt(pItem);
		pCustomItem->adjustSize();
		pItem->setSizeHint(pCustomItem->size());
		m_pUi->ChatAiLstWgt->setItemWidget(pItem, pCustomItem);

		QString contentid = QString::fromStdString(iter->first);
		QString time = QString::fromStdString(iter->second);
		pCustomItem->setContentId(contentid);
		pCustomItem->setLastTime(time);

		connect(pCustomItem, &ChatAiLstItemWgt::listItemClicked, this, &ChatAiWgt::onChatAiLstItemWgt);

		m_arrChatAiLstItemWgt.push_back(pItem);
	}
}

void ChatAiWgt::onAddPb()
{
	emit startNewChat_Home_Wgt();
}

void ChatAiWgt::showNewAiChat(std::string& contentid)
{
	getChatAiLst();
	//QString id = QString::fromStdString(contentid);
	//onChatAiLstItemWgt(id);
}

void ChatAiWgt::onChatAiLstItemWgt(QString& contentid)
{
	m_strCurrentContentId = contentid;
	m_pChatAiWindowWgt->getMessageInformation(m_strCurrentContentId);

	switchChatAiSWgt(CHATAI_WINDOW_WIDGET);
}

void ChatAiWgt::getChatAiMessageInformation_ChatAi_Wgt(QString& contentid)
{
	emit getChatAiMessageInformation_Home_Wgt(contentid);
}

void ChatAiWgt::showChatAiMessage(std::vector<ChatAiMessage*>& arrMessage)
{
	m_pChatAiWindowWgt->showChatAiMessage(arrMessage);
}

void ChatAiWgt::sendChatAiMessage_ChatAi_Wgt(QString& msg, QString& contentid)
{
	emit sendChatAiMessage_Home_Wgt(msg, contentid);
}

void ChatAiWgt::showNewChatAiMessage(QString& msg, QString& contentid)
{
	qDebug() << "111";
	if (m_strCurrentContentId == contentid)
	{
		std::string message = msg.toStdString();
		m_pChatAiWindowWgt->insertMessage(message);
	}
}
