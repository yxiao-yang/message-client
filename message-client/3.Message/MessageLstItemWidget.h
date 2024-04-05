#ifndef _MESSAGELST_ITEM_WIDGET_H_
#define _MESSAGELST_ITEM_WIDGET_H_

#include "ui_MessageLstItemWidget.h"
#include <QWidget>
#include <QListWidgetItem>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MessageLstItemWgt; };
QT_END_NAMESPACE

class MessageLstItemWgt : public QWidget
{
	Q_OBJECT
public:
	MessageLstItemWgt(QListWidgetItem* pItem, QWidget* parent = nullptr);
	~MessageLstItemWgt();

	void setFriendUsername(QString& username);
	void setLastTime(QString& time);
	void setFriendUserid(QString& userid);
	void setFlag(QString& flag);

	void mousePressEvent(QMouseEvent* event);

signals:
	void listItemClicked(QString& friendUserid, QString& friendName);

private:
	Ui::MessageLstItemWgt* m_pUi = nullptr;
	QListWidgetItem* m_pItem;
	QString m_strFriendUserid;
	QString m_strFriendName;
};

#endif