#ifndef _CREATE_GROUP_WIDGET_H_
#define _CREATE_GROUP_WIDGET_H_

#include "ui_CreateGroupWidget.h"
#include "CreateGroupAnsWidget.h"
#include "pub.const.h"
#include "user.hpp"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CreateGroupWgt; };
QT_END_NAMESPACE

class CreateGroupWgt : public QWidget
{
	Q_OBJECT
public:
	CreateGroupWgt(QWidget* parent = nullptr);
	~CreateGroupWgt();

	void setSlots();

	void getFriendship();

	void showFriendship(std::vector<User>& arrUser);

	void showCreateGroupAck();

private slots:
	void on_tableWidget_cellClicked(int row, int column);
	void onSendPb();

signals:
	void getFriendship_Message_Wgt();
	void createGroup_Message_Wgt(QString& groupName, std::vector<User>& friendSelected);

private:
	Ui::CreateGroupWgt* m_pUi = nullptr;
	std::vector<User> m_arrFriend;

	CreateGroupAnsWgt* m_pCreateGroupAnsWgt = nullptr;
};

#endif