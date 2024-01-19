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
	qDebug() << "�����洰������";
	delete m_pUi;
}

void HomeWidget::setStyle()
{
    // ���ô��ڹ̶���С
    setFixedSize(1200, 800);

    // Ӧ����ʽ��
    QString strCssName = "HomeWidget.css";
    pub_func* func = new pub_func;
    if (func->initCssFile(strCssName))
    {
        //qDebug() << "Ӧ����ʽ��LoginWidget.css�ɹ�";
    }
    else
    {
        qDebug() << "Ӧ����ʽ��HomeWidget.cssʧ��";
    }

    // ��������
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());    // ȥ���ڱ߿�
    //setAttribute(Qt::WA_TranslucentBackground);   // ����͸��

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
    // ��С�����ڵ�������
    setWindowState(Qt::WindowMinimized);
}

void HomeWidget::onTbClose()
{
    close();
}

void HomeWidget::mousePressEvent(QMouseEvent* event)
{
    isPressedWidget = true; // ��ǰ��갴�µļ���QWidget���ǽ����ϲ��ֵ������ؼ�
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
    isPressedWidget = false; // ����ɿ�ʱ����Ϊfalse
}


