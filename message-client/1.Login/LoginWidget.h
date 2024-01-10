#ifndef _LOGIN_WIDGET_H
#define _LOGIN_WIDGET_H

#include "ui_LoginWidget.h"
#include "RegWidget.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWgt; };
QT_END_NAMESPACE

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

    void mousePressEvent(QMouseEvent* event);       // �����
    void mouseMoveEvent(QMouseEvent* event);        // ����ƶ�
    void mouseReleaseEvent(QMouseEvent* event);     // ����ͷ�

private slots:
    void onTbMinus();       // ��С������
    void onTbClose();       // �رմ���
    void onPbReg();         // ע�ᰴť
    void showLoginWgt();    // չʾ����

private:
    Ui::LoginWgt* m_pUi = nullptr;
    RegWidget* m_pRegWgt = nullptr;

    /*����¼�*/
    QPoint last;                    // �����϶��ñ���
    bool isPressedWidget = false;   // ����Ƿ�ѹwidget

    // ���÷��
    void setStyle();

    // ���òۺ���
    void setSlots();
};

#endif
