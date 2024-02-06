#ifndef _FRIEND_NOTICE_WIDGET_H_
#define _FRIEND_NOTICE_WIDGET_H_

#include "ui_FriendNoticeWidget.h"
#include "SearchResWidget.h"
#include "user.hpp"

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

	void showFriendNotice(std::vector<User>& arrUser);

signals:
	void getFriendNotice_Friend_Wgt();

private:
	Ui::FriendNoticeWgt* m_pUi = nullptr;

	QVBoxLayout* m_pUserLayout = nullptr;
	std::vector<SearchResWgt*> m_arrSearchResWgt;

	void setSlots();
};

#endif