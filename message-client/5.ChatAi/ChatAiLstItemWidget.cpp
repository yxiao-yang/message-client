#include "ChatAiLstItemWidget.h"
#include <QDebug>

#pragma execution_character_set("utf-8")

ChatAiLstItemWgt::ChatAiLstItemWgt(QListWidgetItem* pItem, QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::ChatAiLstItemWgt())
	, m_pItem(pItem)
{
	m_pUi->setupUi(this);
}

ChatAiLstItemWgt::~ChatAiLstItemWgt()
{
	delete m_pUi;
}

void ChatAiLstItemWgt::setContentId(QString& contentid)
{
	m_strContentid = contentid;
}

void ChatAiLstItemWgt::setLastTime(QString& time)
{
	time.remove(0, 5);
	time.remove(-3, 3);
	m_pUi->LastTimeLb->setText(time);
}

void ChatAiLstItemWgt::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		emit this->listItemClicked(m_strContentid);
	}
}
