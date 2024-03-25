#ifndef _MESSAGEWINDOWLST_ITEM_WIDGET_H_
#define _MESSAGEWINDOWLST_ITEM_WIDGET_H_

#include <QWidget>
#include <QMovie>
#include <QLabel>
#include <QPainter>

class MessageWindowLstItemWgt : public QWidget
{
    Q_OBJECT
public:
    explicit MessageWindowLstItemWgt(QWidget* parent = nullptr);

    enum User_Type
    {
        User_System,    // 系统
        User_Me,        // 自己
        User_Friend,    // 用户
        User_Time,      // 时间
    };

    void setTextSuccess();
    void setText(QString text, QString time, QSize allSize, User_Type userType);

    QSize getRealString(QString src);
    QSize fontRect(QString str);

    inline QString getMsg() { return m_strMsg; }
    inline QString getTime() { return m_strTime; }
    inline User_Type getType() { return m_typeUser; }

protected:
    void paintEvent(QPaintEvent* event);

private:
    void setStyle();

    QString m_strMsg;
    QString m_strTime;
    QString m_strCurTime;

    QSize m_allSize;

    QPixmap m_pmFriend;
    QPixmap m_pmUser;
    QRect m_rectIconFriend;
    QRect m_rectIconUser;
    QMovie* m_movieLoading = nullptr;
    QLabel* m_lbLoading = nullptr;
    User_Type m_typeUser = User_System;

    QRect m_rectSquareFriend;
    QRect m_rectSquareUser;
    QRect m_rectTriangleFriend;
    QRect m_rectTriangleUser;
    QRect m_rectTextFriend;
    QRect m_rectTextUser;

    int m_iWidthSquare;
    int m_iWidthText;
    int m_iWidthSpace;
    int m_iHeightLine;

    bool m_isSending = false;

};

#endif

