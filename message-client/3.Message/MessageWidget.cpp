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
	//setSlots();
}

MessageWgt::~MessageWgt()
{
	qDebug() << "��Ϣ��������";
	delete m_pUi;
}