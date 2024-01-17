#include "LoginWidget.h"
#include "pub_func.hpp"
#include "RegWidget.h"
#include <QFile>
#include <QDebug>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
	, m_pUi(new Ui::LoginWgt())
{
    m_pUi->setupUi(this);

    setSlots();
}

LoginWidget::~LoginWidget()
{
    qDebug() << "登录窗口析构";
    delete m_pUi;
}

void LoginWidget::setStyle()
{
    // 设置窗口固定大小
    setFixedSize(900, 600);

    // 应用样式表
    QString strCssName = "LoginWidget.css";
    pub_func* func = new pub_func;
    if (func->initCssFile(strCssName))
    {
        //qDebug() << "应用样式表LoginWidget.css成功";
    }
    else
    {
        qDebug() << "应用样式表LoginWidget.css失败";
    }

    // 其它设置
    m_pUi->UseridLedit->setPlaceholderText("请输入账号");
    m_pUi->PasswordLedit->setPlaceholderText("请输入密码");
	m_pUi->PasswordLedit->setEchoMode(QLineEdit::Password);     // 密文输入
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());    // 去窗口边框

    m_pUi->MinusTb->setIcon(QIcon(":/0.ui/img/minus.png"));
    m_pUi->CloseTb->setIcon(QIcon(":/0.ui/img/poweroff.png"));
}

void LoginWidget::setSlots()
{
    connect(m_pUi->MinusTb, &QToolButton::clicked, this, &LoginWidget::onTbMinus);
    connect(m_pUi->CloseTb, &QToolButton::clicked, this, &LoginWidget::onTbClose);
    connect(m_pUi->RegPb, &QPushButton::clicked, this, &LoginWidget::onPbReg);
    connect(m_pUi->LoginPb, &QPushButton::clicked, this, &LoginWidget::onPbLogin);
}

void LoginWidget::onTbMinus()
{
    // 最小化窗口到任务栏
    setWindowState(Qt::WindowMinimized);
}

void LoginWidget::onTbClose()
{
    close();
}

void LoginWidget::onPbReg()
{
    // 显示注册窗口
    emit showRegWgt_LoginService();
    hide();
}

void LoginWidget::onPbLogin()
{
    QString Userid = m_pUi->UseridLedit->text();
    QString Password = m_pUi->PasswordLedit->text();
    emit loginHome_LoginService(Userid, Password);
}

void LoginWidget::mousePressEvent(QMouseEvent* event)
{
    isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    last = event->globalPos();
}

void LoginWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (isPressedWidget)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        last = event->globalPos();
        move(x() + dx, y() + dy);
    }
}

void LoginWidget::mouseReleaseEvent(QMouseEvent* event)
{
    int dx = event->globalX() - last.x();
    int dy = event->globalY() - last.y();
    move(x() + dx, y() + dy);
    isPressedWidget = false; // 鼠标松开时，置为false
}
