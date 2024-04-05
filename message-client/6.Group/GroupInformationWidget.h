#ifndef _GROUP_INFORMATION_WIDGET_H_
#define _GROUP_INFORMATION_WIDGET_H_

#include "ui_GroupInformationWidget.h"
#include "group.hpp"
#include <QWidget>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class GroupInformationWgt; };
QT_END_NAMESPACE

class GroupInformationWgt : public QWidget
{
	Q_OBJECT
public:
	GroupInformationWgt(QWidget* parent = nullptr);
	~GroupInformationWgt();

	void setGroupName(QString& username);
	void setGroupId(QString& userid);

	void setSlots();

signals:
	void sendMessage_Group_Wgt(QString& groupid);

private slots:
	void onSendMessagePb();

private:
	Ui::GroupInformationWgt* m_pUi = nullptr;
	QString m_strGroupId;
};

#endif