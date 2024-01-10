#ifndef REG_WIDGET_H_
#define REG_WIDGET_H_

#include "ui_RegWidget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class RegWgt; };
QT_END_NAMESPACE

class RegWidget : public QWidget
{
	Q_OBJECT

public:
    explicit RegWidget(QWidget* parent = nullptr);
    ~RegWidget();

private:
    Ui::RegWgt* m_pUi;
};

#endif
