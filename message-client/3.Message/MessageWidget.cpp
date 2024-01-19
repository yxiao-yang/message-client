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
}

MessageWgt::~MessageWgt()
{
	qDebug() << "消息窗口析构";
	delete m_pUi;
}