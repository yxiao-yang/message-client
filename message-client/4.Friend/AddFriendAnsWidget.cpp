#include "AddFriendAnsWidget.h"
#include <QDebug>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

AddFriendAnsWgt::AddFriendAnsWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::AddFriendAnsWgt())
{
	m_pUi->setupUi(this);

	connect(m_pUi->AckPb, &QPushButton::clicked, this, &AddFriendAnsWgt::onAckPb);
}

AddFriendAnsWgt::~AddFriendAnsWgt()
{

}

void AddFriendAnsWgt::setAns(enAddFriendType errnoType)
{
	if (errnoType == APPLY_SUCCESS)
	{
		m_pUi->AddFriendAnsLb->setText("��������ɹ���");
	} 
	else if (errnoType == APPLY_ERR_REPEAT)
	{
		m_pUi->AddFriendAnsLb->setText("�ѷ�������");
	}
	else
	{
		m_pUi->AddFriendAnsLb->setText("��������ʧ�ܣ�");
	}
}

void AddFriendAnsWgt::onAckPb()
{
	this->close();
}

void AddFriendAnsWgt::mousePressEvent(QMouseEvent* event)
{
	isPressedWidget = true; // ��ǰ��갴�µļ���QWidget���ǽ����ϲ��ֵ������ؼ�
	last = event->globalPos();
}

void AddFriendAnsWgt::mouseMoveEvent(QMouseEvent* event)
{
	if (isPressedWidget)
	{
		int dx = event->globalX() - last.x();
		int dy = event->globalY() - last.y();
		last = event->globalPos();
		move(x() + dx, y() + dy);
	}
}

void AddFriendAnsWgt::mouseReleaseEvent(QMouseEvent* event)
{
	int dx = event->globalX() - last.x();
	int dy = event->globalY() - last.y();
	move(x() + dx, y() + dy);
	isPressedWidget = false; // ����ɿ�ʱ����Ϊfalse
}
