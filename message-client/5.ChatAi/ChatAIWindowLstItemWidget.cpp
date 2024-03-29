#include "ChatAiWindowLstItemWidget.h"
#include <QDateTime>
#include <QDebug>

#pragma execution_character_set("utf-8")

ChatAiWindowLstItemWgt::ChatAiWindowLstItemWgt(QWidget* parent)
	: QWidget(parent)
{
    setStyle();
}

void ChatAiWindowLstItemWgt::setStyle()
{
    // 设置字体
    QFont te_font = this->font();
    te_font.setFamily("MicrosoftYaHei");
    te_font.setPointSize(12);
    // te_font.setWordSpacing(0);
    // te_font.setLetterSpacing(QFont::PercentageSpacing,0);
    // te_font.setLetterSpacing(QFont::PercentageSpacing, 100); //300%,100为默认 //设置字间距%
    // te_font.setLetterSpacing(QFont::AbsoluteSpacing, 0); //设置字间距为3像素 //设置字间距像素值
    this->setFont(te_font);

    // 设置用户头像
    m_pmFriend = QPixmap(":/0.ui/img/user.png");
    m_pmUser = QPixmap(":/0.ui/img/user.png");

    // 加载动画
    m_movieLoading = new QMovie(this);
    m_movieLoading->setFileName(":/0.ui/img/giphy.gif");
    m_lbLoading = new QLabel(this);
    m_lbLoading->setMovie(m_movieLoading);
    m_lbLoading->resize(16, 16);
    m_lbLoading->setAttribute(Qt::WA_TranslucentBackground, true);
    m_lbLoading->setAutoFillBackground(false);
}

void ChatAiWindowLstItemWgt::setTextSuccess()
{
    m_lbLoading->hide();
    m_movieLoading->stop();
    m_isSending = true;
}

void ChatAiWindowLstItemWgt::setText(QString text, QSize allSize, ChatAiWindowLstItemWgt::User_Type userType)
{
    m_strMsg = text;
    m_typeUser = userType;
    //m_strCurTime = QDateTime::fromTime_t(time.toInt()).toString("hh:mm");
    m_allSize = allSize;
    if (userType == User_Me)
    {
        if (!m_isSending)
        {
            m_lbLoading->move(m_rectSquareUser.x() - m_lbLoading->width() - 10, m_rectSquareUser.y() + m_rectSquareUser.height() / 2 - m_lbLoading->height() / 2);
            m_lbLoading->show();
            m_movieLoading->start();
        }
    }
    else
    {
        m_lbLoading->hide();
    }

    this->update();
}

void ChatAiWindowLstItemWgt::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);//消锯齿
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::gray));

    if (m_typeUser == User_Type::User_Friend)
    {
        // 好友消息
        // painter.drawRoundedRect(m_iconLeftRect,m_iconLeftRect.width(),m_iconLeftRect.height());
        painter.drawPixmap(m_rectIconFriend, m_pmFriend);

        // 框加边
        QColor col_KuangB(234, 234, 234);
        painter.setBrush(QBrush(col_KuangB));
        painter.drawRoundedRect(m_rectSquareFriend.x() - 1, m_rectSquareFriend.y() - 1, m_rectSquareFriend.width() + 2, m_rectSquareFriend.height() + 2, 4, 4);

        // 框
        QColor col_Kuang(255, 255, 255);
        painter.setBrush(QBrush(col_Kuang));
        painter.drawRoundedRect(m_rectSquareFriend, 4, 4);

        //三角
        QPointF points[3] = {
            QPointF(m_rectTriangleFriend.x(), 30),
            QPointF(m_rectTriangleFriend.x() + m_rectTriangleFriend.width(), 25),
            QPointF(m_rectTriangleFriend.x() + m_rectTriangleFriend.width(), 35),
        };
        QPen pen;
        pen.setColor(col_Kuang);
        painter.setPen(pen);
        painter.drawPolygon(points, 3);

        //三角加边
        QPen penSanJiaoBian;
        penSanJiaoBian.setColor(col_KuangB);
        painter.setPen(penSanJiaoBian);
        painter.drawLine(QPointF(m_rectTriangleFriend.x() - 1, 30), QPointF(m_rectTriangleFriend.x() + m_rectTriangleFriend.width(), 24));
        painter.drawLine(QPointF(m_rectTriangleFriend.x() - 1, 30), QPointF(m_rectTriangleFriend.x() + m_rectTriangleFriend.width(), 36));

        //内容
        QPen penText;
        penText.setColor(QColor(51, 51, 51));
        painter.setPen(penText);
        QTextOption option(Qt::AlignLeft | Qt::AlignVCenter);
        option.setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
        painter.setFont(this->font());
        painter.drawText(m_rectTextFriend, m_strMsg, option);
    }
    else if (m_typeUser == User_Type::User_Me)
    {
        // 自己
        // painter.drawRoundedRect(m_iconRightRect,m_iconRightRect.width(),m_iconRightRect.height());
        painter.drawPixmap(m_rectIconUser, m_pmUser);

        //框
        QColor col_Kuang(75, 164, 242);
        painter.setBrush(QBrush(col_Kuang));
        painter.drawRoundedRect(m_rectSquareUser, 4, 4);

        //三角
        QPointF points[3] = {
            QPointF(m_rectTriangleUser.x() + m_rectTriangleUser.width(), 30),
            QPointF(m_rectTriangleUser.x(), 25),
            QPointF(m_rectTriangleUser.x(), 35),
        };
        QPen pen;
        pen.setColor(col_Kuang);
        painter.setPen(pen);
        painter.drawPolygon(points, 3);

        //内容
        QPen penText;
        penText.setColor(Qt::white);
        painter.setPen(penText);
        QTextOption option(Qt::AlignLeft | Qt::AlignVCenter);
        option.setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
        painter.setFont(this->font());
        painter.drawText(m_rectTextUser, m_strMsg, option);
    }
}

QSize ChatAiWindowLstItemWgt::getRealString(QString src)
{
    QFontMetricsF fm(this->font());
    m_iHeightLine = fm.lineSpacing();
    int nCount = src.count("\n");
    int nMaxWidth = 0;
    if (nCount == 0)
    {
        nMaxWidth = fm.width(src);
        QString value = src;
        if (nMaxWidth > m_iWidthText)
        {

            nMaxWidth = m_iWidthText;
            int size = m_iWidthText / fm.width(" ");
            int num = fm.width(value) / m_iWidthText;
            int ttmp = num * fm.width(" ");
            num = (fm.width(value)) / m_iWidthText;
            nCount += num;
            QString temp = "";
            for (int i = 0; i < num; i++)
            {

                temp += value.mid(i * size, (i + 1) * size) + "\n";
            }
            src.replace(value, temp);
        }
    }
    else
    {
        for (int i = 0; i < (nCount + 1); i++)
        {
            QString value = src.split("\n").at(i);
            nMaxWidth = fm.width(value) > nMaxWidth ? fm.width(value) : nMaxWidth;
            if (fm.width(value) > m_iWidthText)
            {
                nMaxWidth = m_iWidthText;
                int size = m_iWidthText / fm.width(" ");
                int num = fm.width(value) / m_iWidthText;
                num = ((i + num) * fm.width(" ") + fm.width(value)) / m_iWidthText;
                nCount += num;
                QString temp = "";
                for (int i = 0; i < num; i++)
                {

                    temp += value.mid(i * size, (i + 1) * size) + "\n";
                }
                src.replace(value, temp);
            }
        }
    }
    return QSize(nMaxWidth + m_iWidthSpace, (nCount + 1) * m_iHeightLine + 2 * m_iHeightLine);
}

QSize ChatAiWindowLstItemWgt::fontRect(QString str)
{
    m_strMsg = str;
    int minHei = 30;
    int iconWH = 40;
    int iconSpaceW = 20;
    int iconRectW = 5;
    int iconTMPH = 10;
    int sanJiaoW = 6;
    int kuangTMP = 20;
    int textSpaceRect = 12;
    m_iWidthSquare = this->width() - kuangTMP - 2 * (iconWH + iconSpaceW + iconRectW);
    m_iWidthText = m_iWidthSquare - 2 * textSpaceRect;
    m_iWidthSpace = this->width() - m_iWidthText;
    m_rectIconFriend = QRect(iconSpaceW, iconTMPH, iconWH, iconWH);
    m_rectIconUser = QRect(this->width() - iconSpaceW - iconWH, iconTMPH, iconWH, iconWH);

    QSize size = getRealString(m_strMsg); // 整个的size

    int hei = size.height() < minHei ? minHei : size.height();

    m_rectTriangleFriend = QRect(iconWH + iconSpaceW + iconRectW, m_iHeightLine / 2, sanJiaoW, hei - m_iHeightLine);
    m_rectTriangleUser = QRect(this->width() - iconRectW - iconWH - iconSpaceW - sanJiaoW, m_iHeightLine / 2, sanJiaoW, hei - m_iHeightLine);

    if (size.width() < (m_iWidthText + m_iWidthSpace))
    {
        m_rectSquareFriend.setRect(m_rectTriangleFriend.x() + m_rectTriangleFriend.width(), m_iHeightLine / 4 * 3, size.width() - m_iWidthSpace + 2 * textSpaceRect, hei - m_iHeightLine);
        m_rectSquareUser.setRect(this->width() - size.width() + m_iWidthSpace - 2 * textSpaceRect - iconWH - iconSpaceW - iconRectW - sanJiaoW,
            m_iHeightLine / 4 * 3, size.width() - m_iWidthSpace + 2 * textSpaceRect, hei - m_iHeightLine);
    }
    else
    {
        m_rectSquareFriend.setRect(m_rectTriangleFriend.x() + m_rectTriangleFriend.width(), m_iHeightLine / 4 * 3, m_iWidthSquare, hei - m_iHeightLine);
        m_rectSquareUser.setRect(iconWH + kuangTMP + iconSpaceW + iconRectW - sanJiaoW, m_iHeightLine / 4 * 3, m_iWidthSquare, hei - m_iHeightLine);
    }
    m_rectTextFriend.setRect(m_rectSquareFriend.x() + textSpaceRect, m_rectSquareFriend.y() + iconTMPH,
        m_rectSquareFriend.width() - 2 * textSpaceRect, m_rectSquareFriend.height() - 2 * iconTMPH);
    m_rectTextUser.setRect(m_rectSquareUser.x() + textSpaceRect, m_rectSquareUser.y() + iconTMPH,
        m_rectSquareUser.width() - 2 * textSpaceRect, m_rectSquareUser.height() - 2 * iconTMPH);

    return QSize(size.width(), hei);
}