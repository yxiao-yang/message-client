#include "GroupWidget.h"
#include "pub_func.hpp"
#include "pub.const.h"
#include <QDebug>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

GroupWgt::GroupWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::GroupWgt())
{
	m_pUi->setupUi(this);

	m_pEmptyWgt = new QWidget;
	m_pGroupInformationWgt = new GroupInformationWgt;
	m_pUi->GroupSWgt->insertWidget(GROUP_EMPTY_WIDGET, m_pEmptyWgt);
	m_pUi->GroupSWgt->insertWidget(GROUP_INFORMATION_WIDGET, m_pGroupInformationWgt);

	setSlots();
}

GroupWgt::~GroupWgt()
{
	delete m_pUi;
}

void GroupWgt::setSlots()
{
	connect(m_pGroupInformationWgt, &GroupInformationWgt::sendMessage_Group_Wgt, this, &GroupWgt::sendMessage_Group_Wgt);
}

void GroupWgt::switchGroupSWgt(int idx)
{
	m_pUi->GroupSWgt->setCurrentIndex(idx);
}

void GroupWgt::getGroupLst()
{
	// 清空搜索结果
	for (int i = 0; i < m_arrGroupItemWgt.size(); ++i)
	{
		m_pUi->GroupLstWgt->removeItemWidget(m_arrGroupItemWgt[i]);

		delete m_arrGroupItemWgt[i]; // 如果元素是 QWidget 类型
	}
	m_arrGroupItemWgt.clear();

	emit getGroupLst_Home_Wgt();
}

void GroupWgt::showGroupLst(std::vector<Group>& arrGroup)
{
	m_arrGroup = arrGroup;
	for (int i = 0; i < arrGroup.size(); ++i)
	{
		// 创建item
		QListWidgetItem* pItem = new QListWidgetItem("");
		m_pUi->GroupLstWgt->addItem(pItem);

		// 创建自定义widget
		GroupItemWgt* pCustomItem = new GroupItemWgt(pItem);
		pCustomItem->adjustSize();
		pItem->setSizeHint(pCustomItem->size());
		m_pUi->GroupLstWgt->setItemWidget(pItem, pCustomItem);

		QString GroupName = QString::fromStdString(arrGroup[i].getName());
		QString GroupId = QString::fromStdString(arrGroup[i].getId());
		pCustomItem->setGroupId(GroupId);
		pCustomItem->setGroupName(GroupName);

		connect(pCustomItem, &GroupItemWgt::listItemClicked, this, &GroupWgt::onGroupItemWgt);

		m_arrGroupItemWgt.push_back(pItem);
	}
}

void GroupWgt::onGroupItemWgt(QString& groupid)
{
	m_pGroupInformationWgt->setGroupId(groupid);
	for (int i = 0; i < m_arrGroup.size(); ++i)
	{
		if (QString::fromStdString(m_arrGroup[i].getId()) == groupid)
		{
			QString username = QString::fromStdString(m_arrGroup[i].getName());
			m_pGroupInformationWgt->setGroupName(username);
		}
	}
	switchGroupSWgt(GROUP_INFORMATION_WIDGET);
}

void GroupWgt::sendMessage_Group_Wgt(QString& groupid)
{
	emit sendGroupMessage_Home_Wgt(groupid);
}