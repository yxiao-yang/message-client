#include "LoginWidget.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
	, m_pUi(new Ui::LoginWgt())
{
    m_pUi->setupUi(this);
}

LoginWidget::~LoginWidget()
{
    delete m_pUi;
}
