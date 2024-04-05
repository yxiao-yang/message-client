#ifndef _GROUP_WIDGET_H_
#define _GROUP_WIDGET_H_

#include "ui_GroupWidget.h"
#include "user.hpp"
#include "group.hpp"
#include "GroupItemWidget.h"
#include "GroupInformationWidget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class GroupWgt; };
QT_END_NAMESPACE

class GroupWgt : public QWidget
{
	Q_OBJECT
public:
	GroupWgt(QWidget* parent = nullptr);
	~GroupWgt();

	void switchGroupSWgt(int idx);

	void getGroupLst();

	void showGroupLst(std::vector<Group>& arrGroup);

signals:
	void getGroupLst_Home_Wgt();
	void sendGroupMessage_Home_Wgt(QString& groupid);

private slots:
	void onGroupItemWgt(QString& groupid);

public slots:
	void sendMessage_Group_Wgt(QString& groupid);

private:
	Ui::GroupWgt* m_pUi = nullptr;
	QWidget* m_pEmptyWgt = nullptr;

	std::vector<QListWidgetItem*> m_arrGroupItemWgt;
	std::vector<Group> m_arrGroup;

	GroupInformationWgt* m_pGroupInformationWgt = nullptr;

	void setSlots();
};

#endif