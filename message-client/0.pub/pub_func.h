#pragma once

#include <QtWidgets/QApplication>
#include <QFile>
#include <QPalette>

bool initCssFile(QString& strCssFileName) 
{
    //加载样式表
    QString qss;
    QFile file(QString("0.ui/") + strCssFileName);

    if (file.open(QFile::ReadOnly))
    {
        //用readAll读取默认支持的是ANSI格式,如果不小心用creator打开编辑过了很可能打不开
        qss = QLatin1String(file.readAll());

        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();

        return true;
    }
    return false;
}

