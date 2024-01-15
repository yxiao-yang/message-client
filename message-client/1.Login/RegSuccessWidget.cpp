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

void RegSuccessWidget::setStyle(const std::string& strUserid)
{
    // ���ô��ڹ̶���С
    setFixedSize(900, 600);

    // Ӧ����ʽ��
    QString strCssName = "RegSuccessWidget.css";
    pub_func* func = new pub_func;
    if (func->initCssFile(strCssName))
    {
        qDebug() << "Ӧ����ʽ��RegSuccessWidget.css�ɹ�";
    }
    else
    {
        qDebug() << "Ӧ����ʽ��RegSuccessWidget.cssʧ��";
    }

    // ��������
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());    // ȥ���ڱ߿�
    m_pUi->UseridLb->setText("�����˺�Ϊ��" + QString::fromLocal8Bit(strUserid.data()));
}

void RegSuccessWidget::setSlots()
{
    connect(m_pUi->RegSuccessPb, &QPushButton::clicked, this, &RegSuccessWidget::onReturnPb);
}

void RegSuccessWidget::onReturnPb()
{
    emit showLoginWgt_RegSuccessService();
    hide();
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

