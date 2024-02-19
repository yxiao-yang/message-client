#ifndef _FRIENDSHIP_ITEM_WIDGET_H_
#define _FRIENDSHIP_ITEM_WIDGET_H_

#include "ui_FriendshipItemWidget.h"
#include <QWidget>
#include <QListWidgetItem>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class FriendshipItemWgt; };
QT_END_NAMESPACE

class FriendshipItemWgt : public QWidget
{
	Q_OBJECT
public:
	FriendshipItemWgt(QListWidgetItem* pItem, QWidget* parent = nullptr);
	~FriendshipItemWgt();

	void setFriendUsername(QString& username);
	void setFriendState(QString& state);
	void setFriendUserid(QString& userid);

	void mousePressEvent(QMouseEvent* event);

signals:
	void listItemClicked(QString& friendUserid);

private:
	Ui::FriendshipItemWgt* m_pUi = nullptr;
	QListWidgetItem* m_pItem;
	QString m_strFriendUserid;
};

#endif