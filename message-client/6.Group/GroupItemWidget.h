#ifndef _GROUP_ITEM_WIDGET_H_
#define _GROUP_ITEM_WIDGET_H_DGET_H_

#include "ui_GroupItemWidget.h"
#include <QWidget>
#include <QListWidgetItem>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class GroupItemWgt; };
QT_END_NAMESPACE

class GroupItemWgt : public QWidget
{
	Q_OBJECT
public:
	GroupItemWgt(QListWidgetItem* pItem, QWidget* parent = nullptr);
	~GroupItemWgt();

	void setGroupName(QString& username);
	void setGroupId(QString& userid);

	void mousePressEvent(QMouseEvent* event);

signals:
	void listItemClicked(QString& groupid);

private:
	Ui::GroupItemWgt* m_pUi = nullptr;
	QListWidgetItem* m_pItem;
	QString m_strGroupId;
};

#endif