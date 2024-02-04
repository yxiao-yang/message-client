#include "ChatAiWidget.h"
#include "pub_func.hpp"
#include <QDebug>
#include <QMouseEvent>

#pragma execution_character_set("utf-8")

ChatAiWgt::ChatAiWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::ChatAiWgt())
{
	m_pUi->setupUi(this);
}

ChatAiWgt::~ChatAiWgt()
{
	delete m_pUi;
}