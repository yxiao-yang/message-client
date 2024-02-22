#include "MessageLstItemWidget.h"
#include <QDebug>

#pragma execution_character_set("utf-8")

MessageLstItemWgt::MessageLstItemWgt(QListWidgetItem* pItem, QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::MessageLstItemWgt())
	, m_pItem(pItem)
{
	m_pUi->setupUi(this);
}

MessageLstItemWgt::~MessageLstItemWgt()
{
	delete m_pUi;
}

void MessageLstItemWgt::setFriendUsername(QString& username)
{
	m_pUi->FriendUsernameLb->setText(username);
}

void MessageLstItemWgt::setLastTime(QString& time)
{
	time.remove(0, 5);
	time.remove(-3, 3);
	m_pUi->LastTimeLb->setText(time);
}

void MessageLstItemWgt::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		emit this->listItemClicked(m_strFriendUserid);
	}
}
