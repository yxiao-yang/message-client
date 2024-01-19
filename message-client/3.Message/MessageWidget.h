#ifndef _MESSAGE_WIDGET_H_
#define _MESSAGE_WIDGET_H_

#include "ui_MessageWidget.h"
#include "AddFriendWidget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MessageWgt; };
QT_END_NAMESPACE

class MessageWgt : public QWidget
{
	Q_OBJECT
public:
	MessageWgt(QWidget* parent = nullptr);
	~MessageWgt();

private:
	Ui::MessageWgt* m_pUi = nullptr;
	AddFriendWgt* m_pAddFriendWgt = nullptr;
};

#endif