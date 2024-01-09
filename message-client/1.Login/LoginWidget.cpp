#include "LoginWidget.h"
#include "pub_func.h"
#include <QFile>
#include <QDebug>

#pragma execution_character_set("utf-8")

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
	, m_pUi(new Ui::LoginWgt())
{
    m_pUi->setupUi(this);

    setStyle();
}

LoginWidget::~LoginWidget()
{
    delete m_pUi;
}

void LoginWidget::setStyle()
{
    // 设置窗口固定大小
    setFixedSize(1000, 600);

    // 应用样式表
    QString strCssName = "LoginWidget.css";
    if (initCssFile(strCssName))
    {
        qDebug() << "应用样式表LoginWidget.css成功";
    }
    else
    {
        qDebug() << "应用样式表LoginWidget.css失败";
    }

    // 其它设置
    m_pUi->UserNameLedit->setPlaceholderText("请输入用户名");
    m_pUi->PasswordLedit->setPlaceholderText("请输入密码");
	m_pUi->PasswordLedit->setEchoMode(QLineEdit::Password); // 密文输入
}


