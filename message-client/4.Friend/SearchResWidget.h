#ifndef _SEARCH_RES_WIDGET_H_
#define _SEARCH_RES_WIDGET_H_

#include "ui_SearchResWidget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SearchResWgt; };
QT_END_NAMESPACE

class SearchResWgt : public QWidget
{
	Q_OBJECT
public:
	SearchResWgt(QWidget* parent = nullptr);
	~SearchResWgt();

	void setUserid(QString& userid);
	void setUsername(QString& username);
	void changeAddPb();

signals:
	void addFriend_AddFriend_Wgt(QString& userid, QString& username);

private slots:
	void onAddPb();

private:
	Ui::SearchResWgt* m_pUi = nullptr;

	void setSlots();
};

#endif