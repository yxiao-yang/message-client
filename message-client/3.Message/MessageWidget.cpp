#include "MessageWidget.h"
#include "pub_func.hpp"
#include <QDebug>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

MessageWgt::MessageWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::MessageWgt())
{
	m_pUi->setupUi(this);

	m_pAddFriendWgt = new AddFriendWgt;

	m_pUi->MessageSWgt->insertWidget(0, m_pAddFriendWgt);

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
}

void MessageWgt::showSearchRes(std::vector<User>& arrUser)
{
	m_pAddFriendWgt->showSearchRes(arrUser);
}
