#ifndef _CHAT_AI_WIDGET_H_
#define _CHAT_AI_WIDGET_H_

#include "ui_ChatAiWidget.h"
#include "user.hpp"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ChatAiWgt; };
QT_END_NAMESPACE

class ChatAiWgt : public QWidget
{
	Q_OBJECT
public:
	ChatAiWgt(QWidget* parent = nullptr);
	~ChatAiWgt();

private:
	Ui::ChatAiWgt* m_pUi = nullptr;

	//void setSlots();
};

#endif