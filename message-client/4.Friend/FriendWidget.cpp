#include "FriendWidget.h"
#include "pub_func.hpp"
#include "pub.const.h"
#include <QDebug>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

FriendWgt::FriendWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::FriendWgt())
{
	m_pUi->setupUi(this);

	m_pEmptyWgt = new QWidget;
	m_pFriendNoticeWgt = new FriendNoticeWgt;
	m_pFriendInformationWgt = new FriendInformationWgt;

	m_pUi->FriendSWgt->insertWidget(FRIEND_EMPTY_WIDGET, m_pEmptyWgt);
	m_pUi->FriendSWgt->insertWidget(FRIEND_NOTICE_WIDGET, m_pFriendNoticeWgt);
	m_pUi->FriendSWgt->insertWidget(FRIEND_INFORMATION_WIDGET, m_pFriendInformationWgt);

	setSlots();
}

FriendWgt::~FriendWgt()
{
	delete m_pUi;
}

void FriendWgt::switchFriendSWgt(int idx)
{
	m_pUi->FriendSWgt->setCurrentIndex(idx);
	if (idx == FRIEND_NOTICE_WIDGET)
	{
		m_pFriendNoticeWgt->getFriendNotice();
	}
}

void FriendWgt::setSlots()
{
	connect(m_pUi->NoticePb, &QPushButton::clicked, this, &FriendWgt::onNoticePb);
	connect(m_pFriendNoticeWgt, &FriendNoticeWgt::getFriendNotice_Friend_Wgt, this, &FriendWgt::getFriendNotice_Friend_Wgt);
	connect(m_pFriendNoticeWgt, &FriendNoticeWgt::acceptFriendApply_Friend_Wgt, this, &FriendWgt::acceptFriendApply_Friend_Wgt);
	connect(m_pFriendInformationWgt, &FriendInformationWgt::sendMessage_Friend_Wgt, this, &FriendWgt::sendMessage_Friend_Wgt);
}

void FriendWgt::onNoticePb()
{
	switchFriendSWgt(FRIEND_NOTICE_WIDGET);
}

void FriendWgt::getFriendNotice_Friend_Wgt()
{
	emit getFriendNotice_Home_Wgt();
}

void FriendWgt::getFriendship()
{
	// 清空搜索结果
	for (int i = 0; i < m_arrFriendshipItemWgt.size(); ++i)
	{
		m_pUi->FriendLstWgt->removeItemWidget(m_arrFriendshipItemWgt[i]);

		delete m_arrFriendshipItemWgt[i]; // 如果元素是 QWidget 类型
	}
	m_arrFriendshipItemWgt.clear();

	emit getFriendship_Home_Wgt();
}

void FriendWgt::showFriendNotice(std::vector<User>& arrApplyUser, std::vector<User>& arrAppliedUser, std::vector<std::string>& arrApplyTime, std::vector<std::string>& arrAppliedTime)
{
	m_pFriendNoticeWgt->showFriendNotice(arrApplyUser, arrAppliedUser, arrApplyTime, arrAppliedTime);
}

void FriendWgt::acceptFriendApply_Friend_Wgt(QString& userid)
{
	emit acceptFriendApply_Home_Wgt(userid);
}

void FriendWgt::showAcceptFriendApplyAns(enAcceptApplyType errnoType)
{
	getFriendship();
	m_pFriendNoticeWgt->showAcceptFriendApplyAns(errnoType);
}

void FriendWgt::showFriendship(std::vector<User>& arrUser)
{
	m_arrUser = arrUser;
	for (int i = 0; i < arrUser.size(); ++i)
	{
		// 创建item
		QListWidgetItem* pItem = new QListWidgetItem("");
		m_pUi->FriendLstWgt->addItem(pItem);

		// 创建自定义widget
		FriendshipItemWgt* pCustomItem = new FriendshipItemWgt(pItem);
		pCustomItem->adjustSize();
		pItem->setSizeHint(pCustomItem->size());
		m_pUi->FriendLstWgt->setItemWidget(pItem, pCustomItem);

		QString friendUsername = QString::fromStdString(arrUser[i].getName());
		QString friendState = QString::fromStdString(arrUser[i].getState());
		QString friendUserid = QString::fromStdString(arrUser[i].getId());
		pCustomItem->setFriendUsername(friendUsername);
		pCustomItem->setFriendState(friendState);
		pCustomItem->setFriendUserid(friendUserid);

		connect(pCustomItem, &FriendshipItemWgt::listItemClicked, this, &FriendWgt::onFriendshipItemWgt);

		m_arrFriendshipItemWgt.push_back(pItem);
	}
}

void FriendWgt::onFriendshipItemWgt(QString& friendUserid)
{
	m_pFriendInformationWgt->setFriendUserid(friendUserid);
	for (int i = 0; i < m_arrUser.size(); ++i)
	{
		if (QString::fromStdString(m_arrUser[i].getId()) == friendUserid)
		{
			QString username = QString::fromStdString(m_arrUser[i].getName());
			QString phone = QString::fromStdString(m_arrUser[i].getPhone());
			m_pFriendInformationWgt->setFriendUsername(username);
			m_pFriendInformationWgt->setFriendPhone(phone);
		}
	}
	switchFriendSWgt(FRIEND_INFORMATION_WIDGET);
}

void FriendWgt::sendMessage_Friend_Wgt(QString& userid)
{
	emit sendMessage_Home_Wgt(userid);
}
