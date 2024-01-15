#ifndef _REG_SUCCESS_WIDGET_H_
#define _REG_SUCCESS_WIDGET_H_

#include "ui_RegSuccessWidget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class RegSuccessWgt; };
QT_END_NAMESPACE

class RegSuccessWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RegSuccessWidget(QWidget* parent = nullptr);
    ~RegSuccessWidget();

    // ���÷��
    void setStyle(const std::string& strUserid);

    void mousePressEvent(QMouseEvent* event);       // �����
    void mouseMoveEvent(QMouseEvent* event);        // ����ƶ�
    void mouseReleaseEvent(QMouseEvent* event);     // ����ͷ�

private slots:
    void onReturnPb();

signals:
    void showLoginWgt_RegSuccessService();

private:
    Ui::RegSuccessWgt* m_pUi = nullptr;

    /*����¼�*/
    QPoint last;                    // �����϶��ñ���
    bool isPressedWidget = false;   // ����Ƿ�ѹwidget

    // ���òۺ���
    void setSlots();
};

#endif
