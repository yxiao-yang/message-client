#ifndef _FRIEND_NOTICE_RES_WIDGET_H_
#define _FRIEND_NOTICE_RES_WIDGET_H_

#include "ui_FriendNoticeResWidget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class FriendNoticeResWgt; };
QT_END_NAMESPACE

class FriendNoticeResWgt : public QWidget
{
	Q_OBJECT
public:
	FriendNoticeResWgt(QWidget* parent = nullptr);
	~FriendNoticeResWgt();

	void setUserid(QString& userid);
	void setUsername(QString& username);
	void setTime(QString& time);
	void setMessage(QString& message);
	void setButtonName(QString& button);
	void disableButton();

signals:
	void acceptFriendApply_FriendNotice_Wgt(QString& userid);

private slots:
	void onNoticePb();

private:
	Ui::FriendNoticeResWgt* m_pUi = nullptr;

	void setSlots();
};

#endif