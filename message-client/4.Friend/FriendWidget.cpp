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
	setSlots();

	m_pEmptyWgt = new QWidget;
	m_pFriendNoticeWgt = new FriendNoticeWgt;

	m_pUi->FriendSWgt->insertWidget(FRIEND_EMPTY_WIDGET, m_pEmptyWgt);
	m_pUi->FriendSWgt->insertWidget(FRIENDNOTICE_WIDGET, m_pFriendNoticeWgt);
}

FriendWgt::~FriendWgt()
{
	delete m_pUi;
}

void FriendWgt::switchFriendSWgt(int idx)
{
	m_pUi->FriendSWgt->setCurrentIndex(idx);
}

void FriendWgt::setSlots()
{
	connect(m_pUi->NoticePb, &QPushButton::clicked, this, &FriendWgt::onNoticePb);
}

void FriendWgt::onNoticePb()
{
	switchFriendSWgt(FRIENDNOTICE_WIDGET);
}