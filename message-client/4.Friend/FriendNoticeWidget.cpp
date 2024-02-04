#include "FriendNoticeWidget.h"
#include "pub.const.h"

#pragma execution_character_set("utf-8")

FriendNoticeWgt::FriendNoticeWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::FriendNoticeWgt())
{
	m_pUi->setupUi(this);
	setSlots();
}

FriendNoticeWgt::~FriendNoticeWgt()
{
	delete m_pUi;
}

void FriendNoticeWgt::setSlots()
{
	
}
