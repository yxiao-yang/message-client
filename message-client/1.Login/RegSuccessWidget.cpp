#include "RegSuccessWidget.h"
#include "pub_func.hpp"
#include <QMouseEvent>
#include <QDebug>

#pragma execution_character_set("utf-8")

RegSuccessWidget::RegSuccessWidget(QWidget* parent)
    : QWidget(parent)
    , m_pUi(new Ui::RegSuccessWgt())
{
    m_pUi->setupUi(this);

    setSlots();
}

RegSuccessWidget::~RegSuccessWidget()
{
    delete m_pUi;
}

void RegSuccessWidget::setStyle()
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
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());    // ȥ���ڱ߿�
}

void RegSuccessWidget::setSlots()
{
    //connect(m_pUi->ReturnTb, &QToolButton::clicked, this, &RegWidget::onReturnTb);
}

void RegSuccessWidget::mousePressEvent(QMouseEvent* event)
{
    isPressedWidget = true; // ��ǰ��갴�µļ���QWidget���ǽ����ϲ��ֵ������ؼ�
    last = event->globalPos();
}

void RegSuccessWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (isPressedWidget)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        last = event->globalPos();
        move(x() + dx, y() + dy);
    }
}

void RegSuccessWidget::mouseReleaseEvent(QMouseEvent* event)
{
    int dx = event->globalX() - last.x();
    int dy = event->globalY() - last.y();
    move(x() + dx, y() + dy);
    isPressedWidget = false; // ����ɿ�ʱ����Ϊfalse
}
