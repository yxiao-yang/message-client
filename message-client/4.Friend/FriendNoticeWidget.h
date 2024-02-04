#ifndef _FRIEND_NOTICE_WIDGET_H_
#define _FRIEND_NOTICE_WIDGET_H_

#include "ui_FriendNoticeWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FriendNoticeWgt; };
QT_END_NAMESPACE

class FriendNoticeWgt : public QWidget
{
	Q_OBJECT
public:
	FriendNoticeWgt(QWidget* parent = nullptr);
	~FriendNoticeWgt();

	void getFriendNotice();

signals:
	void getFriendNotice_Friend_Wgt();

private:
	Ui::FriendNoticeWgt* m_pUi = nullptr;

	void setSlots();
};

#endif