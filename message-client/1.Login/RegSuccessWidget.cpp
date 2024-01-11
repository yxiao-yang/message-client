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
    // 设置窗口固定大小
    setFixedSize(900, 600);

    // 应用样式表
    QString strCssName = "RegWidget.css";
    pub_func* func = new pub_func;
    if (func->initCssFile(strCssName))
    {
        qDebug() << "应用样式表RegWidget.css成功";
    }
    else
    {
        qDebug() << "应用样式表RegWidget.css失败";
    }

    // 其它设置
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());    // 去窗口边框
}

void RegSuccessWidget::setSlots()
{
    //connect(m_pUi->ReturnTb, &QToolButton::clicked, this, &RegWidget::onReturnTb);
}

void RegSuccessWidget::mousePressEvent(QMouseEvent* event)
{
    isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
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
    isPressedWidget = false; // 鼠标松开时，置为false
}

