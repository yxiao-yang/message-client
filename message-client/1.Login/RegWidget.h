#ifndef _REG_WIDGET_H_
#define _REG_WIDGET_H_

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
    // ������ذ�ť
    void onReturnTb();

    // ���ע�ᰴť
    void onRegPb();

signals:
    // չʾ��¼����
    void showLoginWgt_RegService();

    // ����ע����Ϣ
    void sendRegMessage_RegService(QString& Username, QString& Password, QString& Telephone);

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
