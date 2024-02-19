#ifndef _FRIENDSHIP_ITEM_WIDGET_H_
#define _FRIENDSHIP_ITEM_WIDGET_H_

#include "ui_FriendshipItemWidget.h"
#include <QWidget>
#include <QListWidgetItem>

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

private:
	Ui::FriendshipItemWgt* m_pUi = nullptr;
	QListWidgetItem* m_pItem;
};

#endif