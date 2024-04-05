#include "GroupItemWidget.h"
#include <QDebug>

#pragma execution_character_set("utf-8")

GroupItemWgt::GroupItemWgt(QListWidgetItem* pItem, QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::GroupItemWgt())
	, m_pItem(pItem)
{
	m_pUi->setupUi(this);
}

GroupItemWgt::~GroupItemWgt()
{
	delete m_pUi;
}

void GroupItemWgt::setGroupName(QString& username)
{
	m_pUi->GroupNameLb->setText(username);
}

void GroupItemWgt::setGroupId(QString& userid)
{
	m_strGroupId = userid;
}

void GroupItemWgt::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		emit this->listItemClicked(m_strGroupId);
	}
}
