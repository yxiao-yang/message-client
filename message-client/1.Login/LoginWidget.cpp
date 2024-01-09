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
    // ���ô��ڹ̶���С
    setFixedSize(1000, 600);

    // Ӧ����ʽ��
    QString strCssName = "LoginWidget.css";
    if (initCssFile(strCssName))
    {
        qDebug() << "Ӧ����ʽ��LoginWidget.css�ɹ�";
    }
    else
    {
        qDebug() << "Ӧ����ʽ��LoginWidget.cssʧ��";
    }

    // ��������
    m_pUi->UserNameLedit->setPlaceholderText("�������û���");
    m_pUi->PasswordLedit->setPlaceholderText("����������");
	m_pUi->PasswordLedit->setEchoMode(QLineEdit::Password); // ��������
}


