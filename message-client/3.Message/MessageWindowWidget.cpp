#include "MessageWindowWidget.h"

#pragma execution_character_set("utf-8")

MessageWindowWgt::MessageWindowWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::MessageWindowWgt())
{
	m_pUi->setupUi(this);
}

MessageWindowWgt::~MessageWindowWgt()
{
	delete m_pUi;
}

void MessageWindowWgt::getMessageInformation(QString& friendUserid)
{
	emit getMessageInformation_Message_Wgt(friendUserid);
}