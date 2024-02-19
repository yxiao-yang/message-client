#include "FriendshipItemWidget.h"
#include <QDebug>

#pragma execution_character_set("utf-8")

FriendshipItemWgt::FriendshipItemWgt(QListWidgetItem* pItem, QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::FriendshipItemWgt())
	, m_pItem(pItem)
{
	m_pUi->setupUi(this);
}

FriendshipItemWgt::~FriendshipItemWgt()
{
	delete m_pUi;
}

void FriendshipItemWgt::setFriendUsername(QString& username)
{
	m_pUi->FriendUsername->setText(username);
}

void FriendshipItemWgt::setFriendState(QString& state)
{
	if (state == "online")
	{
		m_pUi->FriendState->setText("ÔÚÏß");
	} 
	else
	{
		m_pUi->FriendState->setText("ÀëÏß");
	}
}

void FriendshipItemWgt::setFriendUserid(QString& userid)
{
	m_strFriendUserid = userid;
}

void FriendshipItemWgt::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		emit this->listItemClicked(m_strFriendUserid);
	}
}
