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
	m_pUi->SearchLedit->setPlaceholderText("请输入信息");

	m_pUserLayout = new QVBoxLayout;
	m_pUi->UserSearchWgt->setLayout(m_pUserLayout);

	// 滚动区域透明背景+无边框
	m_pUi->UserScroll->setFrameShape(QFrame::NoFrame);
	m_pUi->UserScroll->setStyleSheet("QScrollArea{background-color:transparent;margin:0px;}");
	m_pUi->UserScroll->viewport()->setStyleSheet("background-color:transparent;margin:0px;");
}

AddFriendWgt::~AddFriendWgt()
{
	delete m_pUi;
}

void AddFriendWgt::setSlots()
{
	connect(m_pUi->SearchTb, &QToolButton::clicked, this, &AddFriendWgt::onTbSearch);
}

void AddFriendWgt::onTbSearch()
{
	// 清空搜索结果
	for (int i = 0; i < m_arrSearchResWgt.size(); ++i)
	{
		m_pUserLayout->removeWidget(m_arrSearchResWgt[i]);

		delete m_arrSearchResWgt[i]; // 如果元素是 QWidget 类型
	}
	m_arrSearchResWgt.clear();

	// 发送搜索信号
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

		connect(UserWgt, &SearchResWgt::addFriend_AddFriend_Wgt, this, &AddFriendWgt::addFriend_AddFriend_Wgt);
		m_pUserLayout->addWidget(UserWgt);
		m_arrSearchResWgt.push_back(UserWgt);
	}
}

void AddFriendWgt::addFriend_AddFriend_Wgt(QString& userid, QString& username)
{
	emit addFriend_Message_Friend_Wgt(userid);
}
