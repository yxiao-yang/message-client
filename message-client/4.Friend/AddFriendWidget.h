#ifndef _ADD_FRIEND_WIDGET_H_
#define _ADD_FRIEND_WIDGET_H_

#include "ui_AddFriendWidget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class AddFriendWgt; };
QT_END_NAMESPACE

class AddFriendWgt : public QWidget
{
	Q_OBJECT
public:
	AddFriendWgt(QWidget* parent = nullptr);
	~AddFriendWgt();

private:
	Ui::AddFriendWgt* m_pUi = nullptr;
};

#endif