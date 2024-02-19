#ifndef _FRIEND_INFORMATION_WIDGET_H_
#define _FRIEND_INFORMATION_WIDGET_H_

#include "ui_FriendInformationWidget.h"
#include "user.hpp"
#include <QWidget>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class FriendInformationWgt; };
QT_END_NAMESPACE

class FriendInformationWgt : public QWidget
{
	Q_OBJECT
public:
	FriendInformationWgt(QWidget* parent = nullptr);
	~FriendInformationWgt();

	void setFriendUsername(QString& username);
	void setFriendUserid(QString& userid);
	void setFriendPhone(QString& phone);

private:
	Ui::FriendInformationWgt* m_pUi = nullptr;
};

#endif