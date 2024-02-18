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
		m_pUi->AddFriendAnsLb->setText("接受好友请求成功！");
	}
	else if (errnoType == ACCEPT_APPLY_WRONG)
	{
		m_pUi->AddFriendAnsLb->setText("接受好友请求失败！");
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
	isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
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
	isPressedWidget = false; // 鼠标松开时，置为false
}
