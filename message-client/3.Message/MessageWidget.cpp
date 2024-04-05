#include "MessageWidget.h"
#include "MessageLstItemWidget.h"
#include "pub_func.hpp"
#include "pub.const.h"
#include <QDebug>
#include <QMouseEvent>
#include <QThread>

#pragma execution_character_set("utf-8")

MessageWgt::MessageWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::MessageWgt())
{
	m_pUi->setupUi(this);

	m_pEmptyWgt = new QWidget;
	m_pAddFriendWgt = new AddFriendWgt;
	m_pMessageWindowWgt = new MessageWindowWgt;
	m_pCreateGroupWgt = new CreateGroupWgt;

	m_pUi->MessageSWgt->insertWidget(MESSAGE_EMPTY_WIDGET, m_pEmptyWgt);
	m_pUi->MessageSWgt->insertWidget(ADDFRIEND_WIDGET, m_pAddFriendWgt);
	m_pUi->MessageSWgt->insertWidget(MESSAGE_WINDOW_WIDGET, m_pMessageWindowWgt);
	m_pUi->MessageSWgt->insertWidget(CREATE_GROUP_WIDGET, m_pCreateGroupWgt);

	setSlots();
}

MessageWgt::~MessageWgt()
{
	qDebug() << "消息窗口析构";
	delete m_pUi;
}

void MessageWgt::switchMessageSWgt(int idx)
{
	m_pUi->MessageSWgt->setCurrentIndex(idx);
}

void MessageWgt::searchUser_Message_Friend_Wgt(QString& Userid, QString& Searchid)
{
	emit searchUser_Home_Wgt(Userid, Searchid);
}

void MessageWgt::setSlots()
{
	connect(m_pAddFriendWgt, &AddFriendWgt::searchUser_Message_Friend_Wgt, this, &MessageWgt::searchUser_Message_Friend_Wgt);
	connect(m_pUi->AddPb, &QPushButton::clicked, this, &MessageWgt::onAddPb);
	connect(m_pUi->CreateGroupPb, &QPushButton::clicked, this, &MessageWgt::onCreateGroupPb);
	connect(m_pAddFriendWgt, &AddFriendWgt::addFriend_Message_Friend_Wgt, this, &MessageWgt::addFriend_Message_Friend_Wgt);
	connect(m_pMessageWindowWgt, &MessageWindowWgt::getMessageInformation_Message_Wgt, this, &MessageWgt::getMessageInformation_Message_Wgt);
	connect(m_pMessageWindowWgt, &MessageWindowWgt::sendFriendMessage_Message_Wgt, this, &MessageWgt::sendFriendMessage_Message_Wgt);
	connect(m_pMessageWindowWgt, &MessageWindowWgt::translateMessage_Message_Wgt, this, &MessageWgt::translateMessage_Message_Wgt);
	connect(m_pMessageWindowWgt, &MessageWindowWgt::beautifyMessage_Message_Wgt, this, &MessageWgt::beautifyMessage_Message_Wgt);
	connect(m_pCreateGroupWgt, &CreateGroupWgt::getFriendship_Message_Wgt, this, &MessageWgt::getFriendship_Message_Wgt);
	connect(m_pCreateGroupWgt, &CreateGroupWgt::createGroup_Message_Wgt, this, &MessageWgt::createGroup_Message_Wgt);
}

void MessageWgt::showSearchRes(std::vector<User>& arrUser)
{
	m_pAddFriendWgt->showSearchRes(arrUser);
}

void MessageWgt::onAddPb()
{
	switchMessageSWgt(ADDFRIEND_WIDGET);
}

void MessageWgt::onCreateGroupPb()
{
	m_pCreateGroupWgt->getFriendship();
	switchMessageSWgt(CREATE_GROUP_WIDGET);
}

void MessageWgt::addFriend_Message_Friend_Wgt(QString& userid)
{
	emit addFriend_Home_Wgt(userid);
}

void MessageWgt::showAddFriendAns(enApplyType errnoType)
{
	m_pAddFriendWgt->showAddFriendAns(errnoType);
}

void MessageWgt::getMessageLst()
{
	// 清空结果
	for (int i = 0; i < m_arrMessageLstItemWgt.size(); ++i)
	{
		m_pUi->MessageLstWgt->removeItemWidget(m_arrMessageLstItemWgt[i]);

		delete m_arrMessageLstItemWgt[i]; // 如果元素是 QWidget 类型
	}
	m_arrMessageLstItemWgt.clear();

	emit getMessageLst_Home_Wgt();
}

void MessageWgt::showMessageLst(std::map<std::string, User>& mapTimeUser, std::map<std::string, Group>& mapTimeGroup)
{
	m_mapTimeUser = mapTimeUser;
	for (auto it : mapTimeUser)
	{
		// 创建item
		QListWidgetItem* pItem = new QListWidgetItem("");
		m_pUi->MessageLstWgt->addItem(pItem);

		// 创建自定义widget
		MessageLstItemWgt* pCustomItem = new MessageLstItemWgt(pItem);
		pCustomItem->adjustSize();
		pItem->setSizeHint(pCustomItem->size());
		m_pUi->MessageLstWgt->setItemWidget(pItem, pCustomItem);

		QString friendUsername = QString::fromStdString(it.second.getName());
		QString time = QString::fromStdString(it.first);
		QString friendUserid = QString::fromStdString(it.second.getId());
		QString flag = "好友";
		pCustomItem->setFriendUsername(friendUsername);
		pCustomItem->setLastTime(time);
		pCustomItem->setFriendUserid(friendUserid);
		pCustomItem->setFlag(flag);

		connect(pCustomItem, &MessageLstItemWgt::listItemClicked, this, &MessageWgt::onMessageLstItemWgt);

		m_arrMessageLstItemWgt.push_back(pItem);
	}

	for (auto it : mapTimeGroup)
	{
		// 创建item
		QListWidgetItem* pItem = new QListWidgetItem("");
		m_pUi->MessageLstWgt->addItem(pItem);

		// 创建自定义widget
		MessageLstItemWgt* pCustomItem = new MessageLstItemWgt(pItem);
		pCustomItem->adjustSize();
		pItem->setSizeHint(pCustomItem->size());
		m_pUi->MessageLstWgt->setItemWidget(pItem, pCustomItem);

		QString groupName = QString::fromStdString(it.second.getName());
		QString time = QString::fromStdString(it.first);
		QString groupid = QString::fromStdString(it.second.getId());
		QString flag = "群组";
		pCustomItem->setFriendUsername(groupName);
		pCustomItem->setLastTime(time);
		pCustomItem->setFriendUserid(groupid);
		pCustomItem->setFlag(flag);

		connect(pCustomItem, &MessageLstItemWgt::listItemClicked, this, &MessageWgt::onMessageLstItemWgt);

		m_arrMessageLstItemWgt.push_back(pItem);
	}
}

void MessageWgt::onMessageLstItemWgt(QString& friendUserid, QString& friendName)
{
	m_strCurrentFriendId = friendUserid;
	m_pMessageWindowWgt->getMessageInformation(m_strCurrentFriendId);
	m_pMessageWindowWgt->setFriendNameLb(friendName);
	switchMessageSWgt(MESSAGE_WINDOW_WIDGET);
}

void MessageWgt::getMessageInformation_Message_Wgt(QString& friendUserid)
{
	emit getMessageInformation_Home_Wgt(friendUserid);
}

void MessageWgt::showChatMessage(std::vector<Message*> arrMessage)
{
	m_pMessageWindowWgt->showChatMessage(arrMessage);
}

void MessageWgt::sendFriendMessage_Message_Wgt(QString& msg, QString& userid, QString& friendid)
{
	emit sendFriendMessage_Home_Wgt(msg, userid, friendid);
}

void MessageWgt::getNewFriendMessage(std::string& message, std::string& friendID, std::string& time, std::string& status)
{
	getMessageLst();
	QString friendID_q = QString::fromStdString(friendID);
	if (m_strCurrentFriendId == friendID_q)
	{
		m_pMessageWindowWgt->insertMessage(message, friendID, time, status);
	}
}

void MessageWgt::showFriendName(std::string& friendName)
{
	//m_pUi->FriendNameLb
}

void MessageWgt::translateMessage_Message_Wgt(QString& msg)
{
	emit translateMessage_Home_Wgt(msg);
}

void MessageWgt::showTranslateRes(std::string& msg)
{
	m_pMessageWindowWgt->showTranslateRes(msg);
}

void MessageWgt::beautifyMessage_Message_Wgt(QString& msg)
{
	emit beautifyMessage_Home_Wgt(msg);
}

void MessageWgt::showBeautifyRes(std::string& msg)
{
	m_pMessageWindowWgt->showBeautifyRes(msg);
}

void MessageWgt::getFriendship_Message_Wgt()
{
	emit getFriendship_Home_Wgt();
}

void MessageWgt::showFriendship(std::vector<User>& arrUser)
{
	m_pCreateGroupWgt->showFriendship(arrUser);
}

void MessageWgt::createGroup_Message_Wgt(QString& groupName, std::vector<User>& friendSelected)
{
	emit createGroup_Home_Wgt(groupName, friendSelected);
}

void MessageWgt::showCreateGroupAck()
{
	m_pCreateGroupWgt->showCreateGroupAck();
}
