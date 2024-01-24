#include "SearchResWidget.h"
#include <QDebug>

#pragma execution_character_set("utf-8")

SearchResWgt::SearchResWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::SearchResWgt())
{
	m_pUi->setupUi(this);

	setAttribute(Qt::WA_TranslucentBackground, true);	// ÉèÖÃ´°¿Ú±³¾°Í¸Ã÷
}

SearchResWgt::~SearchResWgt()
{
	delete m_pUi;
}

void SearchResWgt::setUserid(QString& userid)
{
	m_pUi->UseridLb->setText(userid);
}

void SearchResWgt::setUsername(QString& username)
{
	m_pUi->UsernameLb->setText(username);
}
