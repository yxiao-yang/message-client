#include "FriendWidget.h"
#include "pub_func.hpp"
#include <QDebug>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

FriendWgt::FriendWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::FriendWgt())
{
	m_pUi->setupUi(this);
	//setSlots();
}

FriendWgt::~FriendWgt()
{
	qDebug() << "��Ϣ��������";
	delete m_pUi;
}