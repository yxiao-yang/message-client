#ifndef _FRIEND_WIDGET_H_
#define _FRIEND_WIDGET_H_

#include "ui_FriendWidget.h"
#include "FriendNoticeWidget.h"
#include "user.hpp"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class FriendWgt; };
QT_END_NAMESPACE

class FriendWgt : public QWidget
{
	Q_OBJECT
public:
	FriendWgt(QWidget* parent = nullptr);
	~FriendWgt();

	// 切换右侧tackedwidget
	void switchFriendSWgt(int idx);

	// 刷新联系人界面
	void getFriendship();

	void showFriendNotice(std::vector<User>& arrUser);

signals:
	void getFriendNotice_Home_Wgt();
	void getFriendship_Home_Wgt();

public slots:
	void getFriendNotice_Friend_Wgt();

private slots:
	void onNoticePb();

private:
	Ui::FriendWgt* m_pUi = nullptr;
	QWidget* m_pEmptyWgt = nullptr;
	FriendNoticeWgt* m_pFriendNoticeWgt = nullptr;

	void setSlots();
};

#endif