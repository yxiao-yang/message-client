#pragma once

#include <QWidget>
#include "ui_LoginWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWgt; };
QT_END_NAMESPACE

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

    void mousePressEvent(QMouseEvent* event);       // �����
    void mouseMoveEvent(QMouseEvent* event);        // ����ƶ�
    void mouseReleaseEvent(QMouseEvent* event);     // ����ͷ�

private slots:
    void onTbMinus();   // ��С������
    void onTbClose();   // �رմ���

private:
    Ui::LoginWgt *m_pUi;

    /*����¼�*/
    QPoint last;                                    // �����϶��ñ���
    bool isPressedWidget = false;                   // ����Ƿ�ѹwidget

    // ���÷��
    void setStyle();

    // ���òۺ���
    void setSlots();
};
