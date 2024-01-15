#ifndef _REG_SERVICE_H_
#define _REG_SERVICE_H_

#include "RegWidget.h"
#include "json.hpp"

using json = nlohmann::json;

class RegService : public QObject
{
	Q_OBJECT
public:
	RegService();

	// ע��
	void reg(json& js);

	// չʾע�ᴰ��
	void showRegWgt();

signals:
	void showLoginWgt_Service();
	void showRegSuccessWgt_Service(std::string& Userid);

public slots:
	void showLoginWgt_RegService();
	void sendRegMessage_RegService(QString& Username, QString& Password, QString& Telephone);

private:
	RegWidget* m_pRegWgt = nullptr;
};


#endif // ! _REG_SERVICE_H_
