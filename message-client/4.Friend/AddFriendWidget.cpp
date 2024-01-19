#include "AddFriendWidget.h"
#include "pub_func.hpp"
#include <QDebug>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

AddFriendWgt::AddFriendWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::AddFriendWgt())
{
	m_pUi->setupUi(this);
	//setSlots();

	m_pUi->SearchTb->setIcon(QIcon(":/0.ui/img/search.png"));
	m_pUi->SearchLedit->setPlaceholderText("��������Ϣ");
}

AddFriendWgt::~AddFriendWgt()
{
	qDebug() << "��Ϣ��������";
	delete m_pUi;
}