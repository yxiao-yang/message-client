#ifndef _FRIEND_NOTICE_WIDGET_H_
#define _FRIEND_NOTICE_WIDGET_H_

#include "ui_FriendNoticeWidget.h"
#include "FriendNoticeResWidget.h"
#include "AcceptFriendApplyAnsWidget.h"
#include "user.hpp"
#include <QWidget>

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

	void showFriendNotice(std::vector<User>& arrApplyUser, std::vector<User>& arrAppliedUser, std::vector<std::string>& arrApplyTime, std::vector<std::string>& arrAppliedTime);

	void showAcceptFriendApplyAns(enAcceptApplyType errnoType);

public slots:
	void acceptFriendApply_FriendNotice_Wgt(QString& userid);
	void updateFriendNotice_FriendNotice_Wgt();

signals:
	void getFriendNotice_Friend_Wgt();
	void acceptFriendApply_Friend_Wgt(QString& userid);

private:
	Ui::FriendNoticeWgt* m_pUi = nullptr;

	QVBoxLayout* m_pUserLayout = nullptr;
	std::vector<FriendNoticeResWgt*> m_arrSearchResWgt;
	AcceptFriendApplyAnsWgt* m_pAcceptFriendApplyAnsWgt = nullptr;

	void setSlots();
};

#endif