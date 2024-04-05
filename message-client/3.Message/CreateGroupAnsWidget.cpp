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
	m_pUi->AddFriendAnsLb->setText("创建群聊成功！");
}

void CreateGroupAnsWgt::onAckPb()
{
	this->close();
}

void CreateGroupAnsWgt::mousePressEvent(QMouseEvent* event)
{
	isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
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
	isPressedWidget = false; // 鼠标松开时，置为false
}
