#include "RegWidget.h"
#include "pub_func.hpp"
#include <QMouseEvent>
#include <QDebug>

#pragma execution_character_set("utf-8")

RegWidget::RegWidget(QWidget* parent)
    : QWidget(parent)
    , m_pUi(new Ui::RegWgt())
{
    m_pUi->setupUi(this);

    setStyle();
    setSlots();
}

RegWidget::~RegWidget()
{
    delete m_pUi;
}

void RegWidget::setStyle()
{
    // ���ô��ڹ̶���С
    setFixedSize(900, 600);

    // Ӧ����ʽ��
    QString strCssName = "RegWidget.css";
    pub_func* func = new pub_func;
    if (func->initCssFile(strCssName))
    {
        qDebug() << "Ӧ����ʽ��RegWidget.css�ɹ�";
    }
    else
    {
        qDebug() << "Ӧ����ʽ��RegWidget.cssʧ��";
    }

    // ��������
    m_pUi->UserNameLedit->setPlaceholderText("�������û���");
    m_pUi->PasswordLedit->setPlaceholderText("����������");
    m_pUi->PasswordLedit->setEchoMode(QLineEdit::Password);     // ��������
    m_pUi->PhoneLedit->setPlaceholderText("�������ֻ���");
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());    // ȥ���ڱ߿�

    m_pUi->ReturnTb->setIcon(QIcon(":/0.ui/img/rollback.png"));
}

void RegWidget::setSlots()
{
    connect(m_pUi->ReturnTb, &QToolButton::clicked, this, &RegWidget::onReturnTb);
}

void RegWidget::onReturnTb()
{
    emit showLoginWgt();
    close();
}

void RegWidget::mousePressEvent(QMouseEvent* event)
{
    isPressedWidget = true; // ��ǰ��갴�µļ���QWidget���ǽ����ϲ��ֵ������ؼ�
    last = event->globalPos();
}

void RegWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (isPressedWidget)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        last = event->globalPos();
        move(x() + dx, y() + dy);
    }
}

void RegWidget::mouseReleaseEvent(QMouseEvent* event)
{
    int dx = event->globalX() - last.x();
    int dy = event->globalY() - last.y();
    move(x() + dx, y() + dy);
    isPressedWidget = false; // ����ɿ�ʱ����Ϊfalse
}

