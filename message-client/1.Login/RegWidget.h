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

    // ���÷��
    void setStyle();

    void mousePressEvent(QMouseEvent* event);       // �����
    void mouseMoveEvent(QMouseEvent* event);        // ����ƶ�
    void mouseReleaseEvent(QMouseEvent* event);     // ����ͷ�

private slots:
    void onReturnTb();

signals:
    void showLoginWgt();

private:
    Ui::RegWgt* m_pUi = nullptr;
    //LoginWidget* m_pLoginWgt = nullptr;

    /*����¼�*/
    QPoint last;                    // �����϶��ñ���
    bool isPressedWidget = false;   // ����Ƿ�ѹwidget

    // ���òۺ���
    void setSlots();
};

#endif
