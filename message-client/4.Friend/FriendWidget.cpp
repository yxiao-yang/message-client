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

	m_pUi->FriendSWgt->insertWidget(FRIEND_EMPTY_WIDGET, m_pEmptyWgt);
	m_pUi->FriendSWgt->insertWidget(FRIENDNOTICE_WIDGET, m_pFriendNoticeWgt);

	setSlots();
}

FriendWgt::~FriendWgt()
{
	delete m_pUi;
}

void FriendWgt::switchFriendSWgt(int idx)
{
	m_pUi->FriendSWgt->setCurrentIndex(idx);
	if (idx == FRIENDNOTICE_WIDGET)
	{
		m_pFriendNoticeWgt->getFriendNotice();
	}
}

void FriendWgt::setSlots()
{
	connect(m_pUi->NoticePb, &QPushButton::clicked, this, &FriendWgt::onNoticePb);
	connect(m_pFriendNoticeWgt, &FriendNoticeWgt::getFriendNotice_Friend_Wgt, this, &FriendWgt::getFriendNotice_Friend_Wgt);
	connect(m_pFriendNoticeWgt, &FriendNoticeWgt::acceptFriendApply_Friend_Wgt, this, &FriendWgt::acceptFriendApply_Friend_Wgt);
}

void FriendWgt::onNoticePb()
{
	switchFriendSWgt(FRIENDNOTICE_WIDGET);
}

void FriendWgt::getFriendNotice_Friend_Wgt()
{
	emit getFriendNotice_Home_Wgt();
}

void FriendWgt::getFriendship()
{
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
	m_pFriendNoticeWgt->showAcceptFriendApplyAns(errnoType);
}
