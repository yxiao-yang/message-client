#ifndef _REG_SUCCESS_SERVICE_H_
#define _REG_SUCCESS_SERVICE_H_

#include "RegSuccessWidget.h"
#include "json.hpp"

using json = nlohmann::json;

class RegSuccessService : public QObject
{
	Q_OBJECT
public:
	RegSuccessService();

	// չʾע��ɹ�����
	void showRegSuccessWgt(std::string& Userid);

signals:
	void showLoginWgt_Service();

public slots:
	void showLoginWgt_RegSuccessService();

private:
	RegSuccessWidget* m_pRegSuccessWgt = nullptr;
};

#endif
