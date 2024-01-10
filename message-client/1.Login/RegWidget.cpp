#include "RegWidget.h"
#include "pub_func.hpp"

#pragma execution_character_set("utf-8")

RegWidget::RegWidget(QWidget* parent)
    : QWidget(parent)
    , m_pUi(new Ui::RegWgt())
{
    m_pUi->setupUi(this);
}

RegWidget::~RegWidget()
{
    delete m_pUi;
}

