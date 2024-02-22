#ifndef _FRIEND_WIDGET_H_
#define _FRIEND_WIDGET_H_

#include "ui_FriendWidget.h"
#include "FriendNoticeWidget.h"
#include "FriendshipItemWidget.h"
#include "FriendInformationWidget.h"
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

	void showFriendNotice(std::vector<User>& arrApplyUser, std::vector<User>& arrAppliedUser, std::vector<std::string>& arrApplyTime, std::vector<std::string>& arrAppliedTime);

	void showAcceptFriendApplyAns(enAcceptApplyType errnoType);

	void showFriendship(std::vector<User>& arrUser);

signals:
	void getFriendNotice_Home_Wgt();
	void getFriendship_Home_Wgt();
	void acceptFriendApply_Home_Wgt(QString& userid);
	void sendMessage_Home_Wgt(QString& userid);

public slots:
	void getFriendNotice_Friend_Wgt();
	void acceptFriendApply_Friend_Wgt(QString& userid);
	void sendMessage_Friend_Wgt(QString& userid);

private slots:
	void onNoticePb();
	void onFriendshipItemWgt(QString& friendUserid);

private:
	Ui::FriendWgt* m_pUi = nullptr;
	QWidget* m_pEmptyWgt = nullptr;
	FriendNoticeWgt* m_pFriendNoticeWgt = nullptr;
	FriendInformationWgt* m_pFriendInformationWgt = nullptr;
	std::vector<QListWidgetItem*> m_arrFriendshipItemWgt;
	std::vector<User> m_arrUser;

	void setSlots();
};

#endif