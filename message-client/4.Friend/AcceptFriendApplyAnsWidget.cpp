#include "AcceptFriendApplyAnsWidget.h"
#include <QDebug>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

AcceptFriendApplyAnsWgt::AcceptFriendApplyAnsWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::AcceptFriendApplyAnsWgt())
{
	m_pUi->setupUi(this);

	connect(m_pUi->AckPb, &QPushButton::clicked, this, &AcceptFriendApplyAnsWgt::onAckPb);
}

AcceptFriendApplyAnsWgt::~AcceptFriendApplyAnsWgt()
{

}

void AcceptFriendApplyAnsWgt::setAns(enAcceptApplyType errnoType)
{
	if (errnoType == ACCEPT_APPLY_SUCCESS)
	{
		m_pUi->AddFriendAnsLb->setText("���ܺ�������ɹ���");
	}
	else if (errnoType == ACCEPT_APPLY_WRONG)
	{
		m_pUi->AddFriendAnsLb->setText("���ܺ�������ʧ�ܣ�");
	}
	else
	{
	}
}

void AcceptFriendApplyAnsWgt::onAckPb()
{
	emit updateFriendNotice_FriendNotice_Wgt();
	this->close();
}

void AcceptFriendApplyAnsWgt::mousePressEvent(QMouseEvent* event)
{
	isPressedWidget = true; // ��ǰ��갴�µļ���QWidget���ǽ����ϲ��ֵ������ؼ�
	last = event->globalPos();
}

void AcceptFriendApplyAnsWgt::mouseMoveEvent(QMouseEvent* event)
{
	if (isPressedWidget)
	{
		int dx = event->globalX() - last.x();
		int dy = event->globalY() - last.y();
		last = event->globalPos();
		move(x() + dx, y() + dy);
	}
}

void AcceptFriendApplyAnsWgt::mouseReleaseEvent(QMouseEvent* event)
{
	int dx = event->globalX() - last.x();
	int dy = event->globalY() - last.y();
	move(x() + dx, y() + dy);
	isPressedWidget = false; // ����ɿ�ʱ����Ϊfalse
}
