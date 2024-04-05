#include "CreateGroupAnsWidget.h"
#include <QDebug>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

CreateGroupAnsWgt::CreateGroupAnsWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::CreateGroupAnsWgt())
{
	m_pUi->setupUi(this);

	connect(m_pUi->AckPb, &QPushButton::clicked, this, &CreateGroupAnsWgt::onAckPb);
}

CreateGroupAnsWgt::~CreateGroupAnsWgt()
{

}

void CreateGroupAnsWgt::setAns()
{
	m_pUi->AddFriendAnsLb->setText("����Ⱥ�ĳɹ���");
}

void CreateGroupAnsWgt::onAckPb()
{
	this->close();
}

void CreateGroupAnsWgt::mousePressEvent(QMouseEvent* event)
{
	isPressedWidget = true; // ��ǰ��갴�µļ���QWidget���ǽ����ϲ��ֵ������ؼ�
	last = event->globalPos();
}

void CreateGroupAnsWgt::mouseMoveEvent(QMouseEvent* event)
{
	if (isPressedWidget)
	{
		int dx = event->globalX() - last.x();
		int dy = event->globalY() - last.y();
		last = event->globalPos();
		move(x() + dx, y() + dy);
	}
}

void CreateGroupAnsWgt::mouseReleaseEvent(QMouseEvent* event)
{
	int dx = event->globalX() - last.x();
	int dy = event->globalY() - last.y();
	move(x() + dx, y() + dy);
	isPressedWidget = false; // ����ɿ�ʱ����Ϊfalse
}
