#ifndef _HOME_WIDGET_H_
#define _HOME_WIDGET_H_

#include "ui_HomeWidget.h"
#include "MessageWidget.h"
#include "FriendWidget.h"
#include "ChatAiWidget.h"
#include "user.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class HomeWgt; };
QT_END_NAMESPACE

class HomeWidget : public QWidget
{
	Q_OBJECT
public:
	HomeWidget(QWidget* parent = nullptr);
	~HomeWidget();

	// 添加好友界面 展示搜索结果
	void showSearchRes(std::vector<User>& arrUser);

	void showAddFriendAns(enAddFriendType errnoType);

	void showFriendNotice(std::vector<User>& arrUser);

	// 设置风格
	void setStyle();

	void mousePressEvent(QMouseEvent* event);       // 鼠标点击
	void mouseMoveEvent(QMouseEvent* event);        // 鼠标移动
	void mouseReleaseEvent(QMouseEvent* event);     // 鼠标释放

signals:
	void searchUser_Home_Service(QString& Userid, QString& Searchid);
	void getFriendNotice_Home_Service();
	void addFriend_Home_Service(QString& userid);
	void getFriendship_Home_Service();

public slots:
	void searchUser_Home_Wgt(QString& Userid, QString& Searchid);
	void getFriendNotice_Home_Wgt();
	void addFriend_Home_Wgt(QString& userid);
	void getFriendship_Home_Wgt();

private slots:
	void onTbMinus();       // 最小化窗口
	void onTbClose();       // 关闭窗口

private:
	Ui::HomeWgt* m_pUi = nullptr;
	MessageWgt* m_pMessageWgt = nullptr;
	FriendWgt* m_pFriendWgt = nullptr;
	ChatAiWgt* m_pChatAiWgt = nullptr;

	/*鼠标事件*/
	QPoint last;                    // 窗口拖动用变量
	bool isPressedWidget = false;   // 鼠标是否按压widget
	
	// 设置槽函数
	void setSlots();

};

#endif
