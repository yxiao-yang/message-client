#include "AddFriendWidget.h"
#include "pub_func.hpp"
#include "pub.cache.h"
#include <QDebug>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

AddFriendWgt::AddFriendWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::AddFriendWgt())
{
	m_pUi->setupUi(this);
	setSlots();

	m_pUi->SearchTb->setIcon(QIcon(":/0.ui/img/search.png"));
	m_pUi->SearchLedit->setPlaceholderText("��������Ϣ");

	// ����UserPage����
	layoutUserPage = new QVBoxLayout;
	m_pUi->UserPage->setLayout(layoutUserPage);

	// ��UserPage�����scrollUserPage
	scrollUserPage = new QScrollArea;
	layoutUserPage->addWidget(scrollUserPage);

	// ��scrollUserPage�����layoutScrollUserPage
	layoutScrollUserPage = new QVBoxLayout;
	scrollUserPage->setLayout(layoutScrollUserPage);

	// ��������͸������+�ޱ߿�
	QPalette pa = scrollUserPage->palette();
	pa.setBrush(QPalette::Window, Qt::transparent);
	scrollUserPage->setPalette(pa);
	scrollUserPage->setFrameShape(QFrame::NoFrame);

	// ��ʼ������
	spacerScrollUserPage = new QSpacerItem(0, 50, QSizePolicy::Preferred, QSizePolicy::Preferred);
}

AddFriendWgt::~AddFriendWgt()
{
	qDebug() << "��Ϣ��������";
	delete m_pUi;
}

void AddFriendWgt::setSlots()
{
	connect(m_pUi->SearchTb, &QToolButton::clicked, this, &AddFriendWgt::onTbSearch);
}

void AddFriendWgt::onTbSearch()
{
	// ������н��
	

	// ���������ź�
	QString search = m_pUi->SearchLedit->text();
	std::string strUserid;
	PubCache::getInstance()->getUserid(strUserid);
	QString userid = QString::fromStdString(strUserid);
	emit searchUser_Message_Friend_Wgt(userid, search);
}

void AddFriendWgt::showSearchRes(std::vector<User>& arrUser)
{
	for (int i = 0; i < arrUser.size(); ++i)
	{
		SearchResWgt* UserWgt = new SearchResWgt;
		QString userid = QString::fromStdString(arrUser[i].getId());
		QString username = QString::fromStdString(arrUser[i].getName());
		UserWgt->setUserid(userid);
		UserWgt->setUsername(username);
		layoutScrollUserPage->addWidget(UserWgt);
	}
	layoutScrollUserPage->addItem(spacerScrollUserPage);
}
