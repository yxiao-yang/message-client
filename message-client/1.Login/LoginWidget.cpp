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
    qDebug() << "��¼��������";
    delete m_pUi;
}

void LoginWidget::setStyle()
{
    // ���ô��ڹ̶���С
    setFixedSize(900, 600);

    // Ӧ����ʽ��
    QString strCssName = "LoginWidget.css";
    pub_func* func = new pub_func;
    if (func->initCssFile(strCssName))
    {
        //qDebug() << "Ӧ����ʽ��LoginWidget.css�ɹ�";
    }
    else
    {
        qDebug() << "Ӧ����ʽ��LoginWidget.cssʧ��";
    }

    // ��������
    m_pUi->UseridLedit->setPlaceholderText("�������˺�");
    m_pUi->PasswordLedit->setPlaceholderText("����������");
	m_pUi->PasswordLedit->setEchoMode(QLineEdit::Password);     // ��������
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());    // ȥ���ڱ߿�

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
    // ��С�����ڵ�������
    setWindowState(Qt::WindowMinimized);
}

void LoginWidget::onTbClose()
{
    close();
}

void LoginWidget::onPbReg()
{
    // ��ʾע�ᴰ��
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
    isPressedWidget = true; // ��ǰ��갴�µļ���QWidget���ǽ����ϲ��ֵ������ؼ�
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
    isPressedWidget = false; // ����ɿ�ʱ����Ϊfalse
}
