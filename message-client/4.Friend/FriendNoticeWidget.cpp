#include "FriendNoticeWidget.h"
#include "pub.const.h"

#pragma execution_character_set("utf-8")

FriendNoticeWgt::FriendNoticeWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::FriendNoticeWgt())
{
	m_pUi->setupUi(this);
	setSlots();

	m_pUi->DelAllTb->setIcon(QIcon(":/0.ui/img/delete.png"));

	m_pUserLayout = new QVBoxLayout;
	m_pUi->FriendNoticeShowWgt->setLayout(m_pUserLayout);

	// 滚动区域透明背景+无边框
	m_pUi->FriendNoticeScroll->setFrameShape(QFrame::NoFrame);
	m_pUi->FriendNoticeScroll->setStyleSheet("QScrollArea{background-color:transparent;margin:0px;}");
	m_pUi->FriendNoticeScroll->viewport()->setStyleSheet("background-color:transparent;margin:0px;");
}

FriendNoticeWgt::~FriendNoticeWgt()
{
	delete m_pUi;
}

void FriendNoticeWgt::setSlots()
{
	
}

void FriendNoticeWgt::getFriendNotice()
{
	// 清空搜索结果
	for (int i = 0; i < m_arrSearchResWgt.size(); ++i)
	{
		m_pUserLayout->removeWidget(m_arrSearchResWgt[i]);

		delete m_arrSearchResWgt[i]; // 如果元素是 QWidget 类型
	}
	m_arrSearchResWgt.clear();

	emit getFriendNotice_Friend_Wgt();
}

void FriendNoticeWgt::showFriendNotice(std::vector<User>& arrApplyUser, std::vector<User>& arrAppliedUser, std::vector<std::string>& arrApplyTime, std::vector<std::string>& arrAppliedTime)
{
	for (int i = 0; i < arrApplyUser.size(); ++i)
	{
		FriendNoticeResWgt* UserWgt = new FriendNoticeResWgt;
		QString userid = QString::fromStdString(arrApplyUser[i].getId());
		QString username = QString::fromStdString(arrApplyUser[i].getName());
		QString time = QString::fromStdString(arrApplyTime[i]);
		QString message = QString::fromStdString("正在验证你的邀请");
		UserWgt->setUserid(userid);
		UserWgt->setUsername(username);
		UserWgt->setTime(time);
		UserWgt->setMessage(message);

		//connect(UserWgt, &SearchResWgt::addFriend_AddFriend_Wgt, this, &AddFriendWgt::addFriend_AddFriend_Wgt);
		m_pUserLayout->addWidget(UserWgt);
		m_arrSearchResWgt.push_back(UserWgt);
	}

	for (int i = 0; i < arrAppliedUser.size(); ++i)
	{
		FriendNoticeResWgt* UserWgt = new FriendNoticeResWgt;
		QString userid = QString::fromStdString(arrAppliedUser[i].getId());
		QString username = QString::fromStdString(arrAppliedUser[i].getName());
		QString time = QString::fromStdString(arrAppliedTime[i]);
		QString message = QString::fromStdString("想要添加你为好友");
		UserWgt->setUserid(userid);
		UserWgt->setUsername(username);
		UserWgt->setTime(time);
		UserWgt->setMessage(message);

		//connect(UserWgt, &SearchResWgt::addFriend_AddFriend_Wgt, this, &AddFriendWgt::addFriend_AddFriend_Wgt);
		m_pUserLayout->addWidget(UserWgt);
		m_arrSearchResWgt.push_back(UserWgt);
	}
}
