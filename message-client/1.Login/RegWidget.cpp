#include "RegWidget.h"
#include "ConnectServer.h"
#include "pub_func.hpp"
#include "json.hpp"
#include "pub.const.h"
#include <QMouseEvent>
#include <QDebug>

using json = nlohmann::json;

#pragma execution_character_set("utf-8")

RegWidget::RegWidget(QWidget* parent)
    : QWidget(parent)
    , m_pUi(new Ui::RegWgt())
{
    m_pUi->setupUi(this);

    setSlots();
}

RegWidget::~RegWidget()
{
    qDebug() << "注册窗口析构";
    delete m_pUi;
}

void RegWidget::setStyle()
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
    m_pUi->UserNameLedit->setPlaceholderText("请输入用户名");
    m_pUi->PasswordLedit->setPlaceholderText("请输入密码");
    m_pUi->PasswordLedit->setEchoMode(QLineEdit::Password);     // 密文输入
    m_pUi->PhoneLedit->setPlaceholderText("请输入手机号");
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());    // 去窗口边框

    m_pUi->ReturnTb->setIcon(QIcon(":/0.ui/img/rollback.png"));
}

void RegWidget::setSlots()
{
    connect(m_pUi->ReturnTb, &QToolButton::clicked, this, &RegWidget::onReturnTb);
    connect(m_pUi->RegPb, &QPushButton::clicked, this, &RegWidget::onRegPb);
}

void RegWidget::onReturnTb()
{
    emit showLoginWgt_RegService();
    hide();
}

void RegWidget::onRegPb()
{
    /*json js;
    js["msgid"] = REG_MSG;
    js["Username"] = m_pUi->UserNameLedit->text().toStdString();
    js["Password"] = m_pUi->PasswordLedit->text().toStdString();
    js["Telephone"] = m_pUi->PhoneLedit->text().toStdString();
    std::string strRequest = js.dump();

    int len = ConnectServer::getInstance()->getTcpSocket()->write(QString::fromStdString(strRequest).toLocal8Bit());
    if (len == -1)
    {
        qDebug() << "send register fail";
    } 
    else
    {
        qDebug() << "send register success";
        hide();
    }*/
    QString Username = m_pUi->UserNameLedit->text();
    QString Password = m_pUi->PasswordLedit->text();
    QString Telephone = m_pUi->PhoneLedit->text();

    emit sendRegMessage_RegService(Username, Password, Telephone);
    hide();
}

void RegWidget::mousePressEvent(QMouseEvent* event)
{
    isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
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
    isPressedWidget = false; // 鼠标松开时，置为false
}

