#include "FriendInformationWidget.h"

#include "pub.const.h"
#include <QDebug>

#pragma execution_character_set("utf-8")

FriendInformationWgt::FriendInformationWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::FriendInformationWgt())
{
	m_pUi->setupUi(this);
	setSlots();
}

FriendInformationWgt::~FriendInformationWgt()
{
	delete m_pUi;
}

void FriendInformationWgt::setSlots()
{
	connect(m_pUi->SendMessagePb, &QPushButton::clicked, this, &FriendInformationWgt::onSendMessagePb);
}

void FriendInformationWgt::setFriendUsername(QString& username)
{
	m_pUi->FriendUsernameLb->setText(username);
}

void FriendInformationWgt::setFriendUserid(QString& userid)
{
	m_strUserid = userid;
	m_pUi->FriendUseridLb->setText(userid);
}

void FriendInformationWgt::setFriendPhone(QString& phone)
{
	m_pUi->FriendPhoneLb->setText(phone);
}

void FriendInformationWgt::onSendMessagePb()
{
	emit sendMessage_Friend_Wgt(m_strUserid);
}
