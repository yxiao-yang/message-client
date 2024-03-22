#include "HomeWidget.h"
#include "pub.const.h"
#include "pub_func.hpp"
#include <QDebug>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

HomeWidget::HomeWidget(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::HomeWgt())
{
	m_pUi->setupUi(this);

    m_pMessageWgt = new MessageWgt;
    m_pFriendWgt = new FriendWgt;
    m_pChatAiWgt = new ChatAiWgt;
    m_pUi->stackedWidget->insertWidget(MESSAGE_WIDGET, m_pMessageWgt);
    m_pUi->stackedWidget->insertWidget(FRIEND_WIDGET, m_pFriendWgt);
    m_pUi->stackedWidget->insertWidget(CHATAI_WIDGET, m_pChatAiWgt);
    
    //showMessageWgt();

    setSlots();
}

HomeWidget::~HomeWidget()
{
	qDebug() << "�����洰������";
	delete m_pUi;
}

void HomeWidget::setStyle()
{
    // ���ô��ڹ̶���С
    setFixedSize(1200, 800);

    // Ӧ����ʽ��
    QString strCssName = "HomeWidget.css";
    pub_func* func = new pub_func;
    if (func->initCssFile(strCssName))
    {
        //qDebug() << "Ӧ����ʽ��LoginWidget.css�ɹ�";
    }
    else
    {
        qDebug() << "Ӧ����ʽ��HomeWidget.cssʧ��";
    }

    // ��������
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());    // ȥ���ڱ߿�
    //setAttribute(Qt::WA_TranslucentBackground);   // ����͸��

    m_pUi->MinusTb->setIcon(QIcon(":/0.ui/img/minus.png"));
    m_pUi->CloseTb->setIcon(QIcon(":/0.ui/img/poweroff.png"));
    m_pUi->MessageTb->setIcon(QIcon(":/0.ui/img/message.png"));
    m_pUi->FriendTb->setIcon(QIcon(":/0.ui/img/user.png"));
    m_pUi->ChatAiTb->setIcon(QIcon(":/0.ui/img/reddit.png"));
}

void HomeWidget::setSlots()
{
    connect(m_pUi->MinusTb, &QToolButton::clicked, this, &HomeWidget::onTbMinus);
    connect(m_pUi->CloseTb, &QToolButton::clicked, this, &HomeWidget::onTbClose);
    connect(m_pUi->MessageTb, &QToolButton::clicked, [=]() {
        m_pMessageWgt->getMessageLst();
        m_pUi->stackedWidget->setCurrentIndex(MESSAGE_WIDGET);
	});
    connect(m_pUi->FriendTb, &QToolButton::clicked, [=]() {
        m_pFriendWgt->getFriendship();
        m_pUi->stackedWidget->setCurrentIndex(FRIEND_WIDGET);
	});
    connect(m_pUi->ChatAiTb, &QToolButton::clicked, [=]()
    {
        m_pUi->stackedWidget->setCurrentIndex(CHATAI_WIDGET);
    });
    connect(m_pMessageWgt, &MessageWgt::searchUser_Home_Wgt, this, &HomeWidget::searchUser_Home_Wgt);
    connect(m_pFriendWgt, &FriendWgt::getFriendNotice_Home_Wgt, this, &HomeWidget::getFriendNotice_Home_Wgt);
    connect(m_pMessageWgt, &MessageWgt::addFriend_Home_Wgt, this, &HomeWidget::addFriend_Home_Wgt);
    connect(m_pFriendWgt, &FriendWgt::acceptFriendApply_Home_Wgt, this, &HomeWidget::acceptFriendApply_Home_Wgt);
    connect(m_pFriendWgt, &FriendWgt::getFriendship_Home_Wgt, this, &HomeWidget::getFriendship_Home_Wgt);
    connect(m_pFriendWgt, &FriendWgt::sendMessage_Home_Wgt, this, &HomeWidget::sendMessage_Home_Wgt);
    connect(m_pMessageWgt, &MessageWgt::getMessageLst_Home_Wgt, this, &HomeWidget::getMessageLst_Home_Wgt);
    connect(m_pMessageWgt, &MessageWgt::getMessageInformation_Home_Wgt, this, &HomeWidget::getMessageInformation_Home_Wgt);
}

void HomeWidget::onTbMinus()
{
    // ��С�����ڵ�������
    setWindowState(Qt::WindowMinimized);
}

void HomeWidget::onTbClose()
{
    close();
}

void HomeWidget::mousePressEvent(QMouseEvent* event)
{
    isPressedWidget = true; // ��ǰ��갴�µļ���QWidget���ǽ����ϲ��ֵ������ؼ�
    last = event->globalPos();
}

void HomeWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (isPressedWidget)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        last = event->globalPos();
        move(x() + dx, y() + dy);
    }
}

void HomeWidget::mouseReleaseEvent(QMouseEvent* event)
{
    int dx = event->globalX() - last.x();
    int dy = event->globalY() - last.y();
    move(x() + dx, y() + dy);
    isPressedWidget = false; // ����ɿ�ʱ����Ϊfalse
}

void HomeWidget::searchUser_Home_Wgt(QString& Userid, QString& Searchid)
{
    emit searchUser_Home_Service(Userid, Searchid);
}

void HomeWidget::showSearchRes(std::vector<User>& arrUser)
{
    m_pMessageWgt->showSearchRes(arrUser);
}

void HomeWidget::getFriendNotice_Home_Wgt()
{
    emit getFriendNotice_Home_Service();
}

void HomeWidget::addFriend_Home_Wgt(QString& userid)
{
    emit addFriend_Home_Service(userid);
}

void HomeWidget::getFriendship_Home_Wgt()
{
    emit getFriendship_Home_Service();
}

void HomeWidget::showAddFriendAns(enApplyType errnoType)
{
    m_pMessageWgt->showAddFriendAns(errnoType);
}

void HomeWidget::showFriendNotice(std::vector<User>& arrApplyUser, std::vector<User>& arrAppliedUser, std::vector<std::string>& arrApplyTime, std::vector<std::string>& arrAppliedTime)
{
    m_pFriendWgt->showFriendNotice(arrApplyUser, arrAppliedUser, arrApplyTime, arrAppliedTime);
}

void HomeWidget::acceptFriendApply_Home_Wgt(QString& userid)
{
    emit acceptFriendApply_Home_Service(userid);
}

void HomeWidget::showAcceptFriendApplyAns(enAcceptApplyType errnoType)
{
    m_pFriendWgt->showAcceptFriendApplyAns(errnoType);
}

void HomeWidget::showFriendship(std::vector<User>& arrUser)
{
    m_pFriendWgt->showFriendship(arrUser);
}

void HomeWidget::sendMessage_Home_Wgt(QString& userid)
{
    emit sendMessage_Home_Service(userid);
}

void HomeWidget::showMessageWgt()
{
    m_pMessageWgt->getMessageLst();
    m_pUi->stackedWidget->setCurrentIndex(MESSAGE_WIDGET);
}

void HomeWidget::getMessageLst_Home_Wgt()
{
    emit getMessageLst_Home_Service();
}

void HomeWidget::showMessageLst(std::map<std::string, User>& mapTimeUser)
{
    m_pMessageWgt->showMessageLst(mapTimeUser);
}

void HomeWidget::getMessageInformation_Home_Wgt(QString& friendUserid)
{
    emit getMessageInformation_Home_Service(friendUserid);
}

void HomeWidget::showChatMessage(std::vector<Message*> arrMessage)
{
    m_pMessageWgt->showChatMessage(arrMessage);
}
