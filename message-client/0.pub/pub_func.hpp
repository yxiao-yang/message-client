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

	void pub_func::deleteAllInLayout(QLayout* layout)
	{
		if (nullptr == layout)
		{
			return;
		}
		QLayoutItem* child;
		while ((child = layout->takeAt(0)) != nullptr)
		{
			QLayout* pLayout = child->layout();
			if (nullptr != pLayout)
			{
				deleteAllInLayout(pLayout);
			}
			else
			{
				QWidget* pCWidget = child->widget();
				if (nullptr != pCWidget)
				{
					//setParent为NULL，防止删除之后界面不消失
					pCWidget->setParent(nullptr);
					delete pCWidget;
					pCWidget = nullptr;
				}
			}
			delete child;
			child = nullptr;
		}
	}
};

#endif