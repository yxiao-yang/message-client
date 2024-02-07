#include "SearchResWidget.h"
#include <QDebug>

#pragma execution_character_set("utf-8")

SearchResWgt::SearchResWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::SearchResWgt())
{
	m_pUi->setupUi(this);

	setSlots();

	//setAttribute(Qt::WA_TranslucentBackground, true);	// 设置窗口背景透明
}

SearchResWgt::~SearchResWgt()
{
	delete m_pUi;
}

void SearchResWgt::setUserid(QString& userid)
{
	m_pUi->UseridLb->setText(userid);
}

void SearchResWgt::setUsername(QString& username)
{
	m_pUi->UsernameLb->setText(username);
}

void SearchResWgt::setSlots()
{
	connect(m_pUi->AddSearchResPb, &QPushButton::clicked, this, &SearchResWgt::onAddPb);
}

void SearchResWgt::onAddPb()
{
	QString userid = m_pUi->UseridLb->text();
	QString username = m_pUi->UsernameLb->text();
	emit addFriend_AddFriend_Wgt(userid, username);
}

void SearchResWgt::changeAddPb()
{
	m_pUi->AddSearchResPb->setText("发消息");
}

void SearchResWgt::changeAgreePb()
{
	m_pUi->AddSearchResPb->setText("同意");
}
