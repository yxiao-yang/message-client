#include "HomeWidget.h"
#include "pub.const.h"
#include "pub_func.hpp"
#include <QDebug>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

HomeWidget::HomeWidget(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::HomeWgt())
{
	m_pUi->setupUi(this);
    setSlots();

    m_pMessageWgt = new MessageWgt;
    m_pFriendWgt = new FriendWgt;
    m_pUi->stackedWidget->insertWidget(MESSAGE_WIDGET, m_pMessageWgt);
    m_pUi->stackedWidget->insertWidget(FRIEND_WIDGET, m_pFriendWgt);

    m_pUi->stackedWidget->setCurrentIndex(MESSAGE_WIDGET);
}

HomeWidget::~HomeWidget()
{
	qDebug() << "主界面窗口析构";
	delete m_pUi;
}

void HomeWidget::setStyle()
{
    // 设置窗口固定大小
    setFixedSize(1200, 800);

    // 应用样式表
    QString strCssName = "HomeWidget.css";
    pub_func* func = new pub_func;
    if (func->initCssFile(strCssName))
    {
        //qDebug() << "应用样式表LoginWidget.css成功";
    }
    else
    {
        qDebug() << "应用样式表HomeWidget.css失败";
    }

    // 其它设置
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());    // 去窗口边框
    //setAttribute(Qt::WA_TranslucentBackground);   // 背景透明

    m_pUi->MinusTb->setIcon(QIcon(":/0.ui/img/minus.png"));
    m_pUi->CloseTb->setIcon(QIcon(":/0.ui/img/poweroff.png"));
    m_pUi->MessageTb->setIcon(QIcon(":/0.ui/img/message.png"));
    m_pUi->FriendTb->setIcon(QIcon(":/0.ui/img/user.png"));
}

void HomeWidget::setSlots()
{
    connect(m_pUi->MinusTb, &QToolButton::clicked, this, &HomeWidget::onTbMinus);
    connect(m_pUi->CloseTb, &QToolButton::clicked, this, &HomeWidget::onTbClose);
    connect(m_pUi->MessageTb, &QToolButton::clicked, [=]() {
        m_pUi->stackedWidget->setCurrentIndex(MESSAGE_WIDGET);
	});
    connect(m_pUi->FriendTb, &QToolButton::clicked, [=]() {
        m_pUi->stackedWidget->setCurrentIndex(FRIEND_WIDGET);
	});
}

void HomeWidget::onTbMinus()
{
    // 最小化窗口到任务栏
    setWindowState(Qt::WindowMinimized);
}

void HomeWidget::onTbClose()
{
    close();
}

void HomeWidget::mousePressEvent(QMouseEvent* event)
{
    isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    last = event->globalPos();
}

void HomeWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (isPressedWidget)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        last = event->globalPos();
        move(x() + dx, y() + dy);
    }
}

void HomeWidget::mouseReleaseEvent(QMouseEvent* event)
{
    int dx = event->globalX() - last.x();
    int dy = event->globalY() - last.y();
    move(x() + dx, y() + dy);
    isPressedWidget = false; // 鼠标松开时，置为false
}


