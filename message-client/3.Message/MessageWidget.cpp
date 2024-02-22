#include "MessageWidget.h"
#include "MessageLstItemWidget.h"
#include "pub_func.hpp"
#include "pub.const.h"
#include <QDebug>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

MessageWgt::MessageWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::MessageWgt())
{
	m_pUi->setupUi(this);

	m_pEmptyWgt = new QWidget;
	m_pAddFriendWgt = new AddFriendWgt;

	m_pUi->MessageSWgt->insertWidget(MESSAGE_EMPTY_WIDGET, m_pEmptyWgt);
	m_pUi->MessageSWgt->insertWidget(ADDFRIEND_WIDGET, m_pAddFriendWgt);

	setSlots();
}

MessageWgt::~MessageWgt()
{
	qDebug() << "��Ϣ��������";
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
	connect(m_pAddFriendWgt, &AddFriendWgt::addFriend_Message_Friend_Wgt, this, &MessageWgt::addFriend_Message_Friend_Wgt);
}

void MessageWgt::showSearchRes(std::vector<User>& arrUser)
{
	m_pAddFriendWgt->showSearchRes(arrUser);
}

void MessageWgt::onAddPb()
{
	switchMessageSWgt(ADDFRIEND_WIDGET);
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
	// ��ս��
	for (int i = 0; i < m_arrMessageLstItemWgt.size(); ++i)
	{
		m_pUi->MessageLstWgt->removeItemWidget(m_arrMessageLstItemWgt[i]);

		delete m_arrMessageLstItemWgt[i]; // ���Ԫ���� QWidget ����
	}
	m_arrMessageLstItemWgt.clear();

	emit getMessageLst_Home_Wgt();
}

void MessageWgt::showMessageLst(std::map<std::string, User>& mapTimeUser)
{
	m_mapTimeUser = mapTimeUser;
	for (auto it : mapTimeUser)
	{
		// ����item
		QListWidgetItem* pItem = new QListWidgetItem("");
		m_pUi->MessageLstWgt->addItem(pItem);

		// �����Զ���widget
		MessageLstItemWgt* pCustomItem = new MessageLstItemWgt(pItem);
		pCustomItem->adjustSize();
		pItem->setSizeHint(pCustomItem->size());
		m_pUi->MessageLstWgt->setItemWidget(pItem, pCustomItem);

		QString friendUsername = QString::fromStdString(it.second.getName());
		QString time = QString::fromStdString(it.first);
		pCustomItem->setFriendUsername(friendUsername);
		pCustomItem->setLastTime(time);

		//connect(pCustomItem, &FriendshipItemWgt::listItemClicked, this, &FriendWgt::onFriendshipItemWgt);

		m_arrMessageLstItemWgt.push_back(pItem);
	}
}
