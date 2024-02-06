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
		m_pUi->AddFriendAnsLb->setText("发送请求成功！");
	} 
	else if (errnoType == APPLY_ERR_REPEAT)
	{
		m_pUi->AddFriendAnsLb->setText("已发送请求！");
	}
	else
	{
		m_pUi->AddFriendAnsLb->setText("发送请求失败！");
	}
}

void AddFriendAnsWgt::onAckPb()
{
	this->close();
}

void AddFriendAnsWgt::mousePressEvent(QMouseEvent* event)
{
	isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
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
	isPressedWidget = false; // 鼠标松开时，置为false
}
