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
    qDebug() << "ע�ᴰ������";
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

