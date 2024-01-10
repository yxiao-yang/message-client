#pragma once

#include <QtWidgets/QApplication>
#include <QFile>
#include <QPalette>

bool initCssFile(QString& strCssFileName) 
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

