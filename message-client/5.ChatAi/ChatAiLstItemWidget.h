#ifndef _CHATAILST_ITEM_WIDGET_H_
#define _CHATAILST_ITEM_WIDGET_H_

#include "ui_ChatAiLstItemWidget.h"
#include <QWidget>
#include <QListWidgetItem>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class ChatAiLstItemWgt; };
QT_END_NAMESPACE

class ChatAiLstItemWgt : public QWidget
{
	Q_OBJECT
public:
	ChatAiLstItemWgt(QListWidgetItem* pItem, QWidget* parent = nullptr);
	~ChatAiLstItemWgt();

	void setContentId(QString& contentid);

	void setLastTime(QString& time);

	void mousePressEvent(QMouseEvent* event);

signals:
	void listItemClicked(QString& contentid);

private:
	Ui::ChatAiLstItemWgt* m_pUi = nullptr;
	QListWidgetItem* m_pItem;
	QString m_strContentid;
};

#endif