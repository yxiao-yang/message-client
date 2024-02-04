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

	// ¹ö¶¯ÇøÓòÍ¸Ã÷±³¾°+ÎÞ±ß¿ò
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
	emit getFriendNotice_Friend_Wgt();
}
