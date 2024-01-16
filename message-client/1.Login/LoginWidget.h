#ifndef _LOGIN_WIDGET_H_
#define _LOGIN_WIDGET_H_

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

    // ���÷��
    void setStyle();

    void mousePressEvent(QMouseEvent* event);       // �����
    void mouseMoveEvent(QMouseEvent* event);        // ����ƶ�
    void mouseReleaseEvent(QMouseEvent* event);     // ����ͷ�

signals:
    void showRegWgt_LoginService(); // չʾע�ᴰ��
    void loginHome_LoginService(QString& Userid, QString& Password);  // ��¼ҵ��

private slots:
    void onTbMinus();       // ��С������
    void onTbClose();       // �رմ���
    void onPbReg();         // ע�ᰴť
    void onPbLogin();       // ��¼��ť

private:
    Ui::LoginWgt* m_pUi = nullptr;
    //RegWidget* m_pRegWgt = nullptr;

    /*����¼�*/
    QPoint last;                    // �����϶��ñ���
    bool isPressedWidget = false;   // ����Ƿ�ѹwidget

    // ���òۺ���
    void setSlots();
};

#endif
