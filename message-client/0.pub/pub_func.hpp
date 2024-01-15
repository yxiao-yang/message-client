#ifndef _PUB_FUNC_H_
#define _PUB_FUNC_H_

#include <QtWidgets/QApplication>
#include <QFile>
#include <QPalette>
#include <QMutex>

class pub_func
{
public:
    bool pub_func::initCssFile(QString& strCssFileName)
    {
        //������ʽ��
        QString qss;
        QFile file(QString("0.ui/") + strCssFileName);

        if (file.open(QFile::ReadOnly))
        {
            //��readAll��ȡĬ��֧�ֵ���ANSI��ʽ,�����С����creator�򿪱༭���˺ܿ��ܴ򲻿�
            qss = QLatin1String(file.readAll());

            QString paletteColor = qss.mid(20, 7);
            qApp->setPalette(QPalette(QColor(paletteColor)));
            qApp->setStyleSheet(qss);
            file.close();

            return true;
        }
        return false;
    }
};

#endif