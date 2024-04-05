#include "GroupInformationWidget.h"

#include "pub.const.h"
#include <QDebug>

#pragma execution_character_set("utf-8")

GroupInformationWgt::GroupInformationWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::GroupInformationWgt())
{
	m_pUi->setupUi(this);
	setSlots();
}

GroupInformationWgt::~GroupInformationWgt()
{
	delete m_pUi;
}

void GroupInformationWgt::setSlots()
{
	connect(m_pUi->SendMessagePb, &QPushButton::clicked, this, &GroupInformationWgt::onSendMessagePb);
}

void GroupInformationWgt::setGroupName(QString& username)
{
	m_pUi->GroupNameLb->setText(username);
}

void GroupInformationWgt::setGroupId(QString& groupid)
{
	m_strGroupId = groupid;
	m_pUi->GroupIdLb->setText(QString(groupid));
}

void GroupInformationWgt::onSendMessagePb()
{
	emit sendMessage_Group_Wgt(m_strGroupId);
}
