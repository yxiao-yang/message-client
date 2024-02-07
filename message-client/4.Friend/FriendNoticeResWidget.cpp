#include "FriendNoticeResWidget.h"
#include <QDebug>

#pragma execution_character_set("utf-8")

FriendNoticeResWgt::FriendNoticeResWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::FriendNoticeResWgt())
{
	m_pUi->setupUi(this);

	setSlots();
}

FriendNoticeResWgt::~FriendNoticeResWgt()
{
	delete m_pUi;
}

void FriendNoticeResWgt::setSlots()
{
	
}

void FriendNoticeResWgt::setUserid(QString& userid)
{
	m_pUi->UseridLb->setText(userid);
}

void FriendNoticeResWgt::setUsername(QString& username)
{
	m_pUi->UsernameLb->setText(username);
}

void FriendNoticeResWgt::setTime(QString& time)
{
	m_pUi->ApplyTimeLb->setText(time);
}

void FriendNoticeResWgt::setMessage(QString& message)
{
	m_pUi->MessageLb->setText(message);
}
