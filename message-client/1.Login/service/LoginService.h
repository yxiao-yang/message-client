#ifndef _LOGIN_SERVICE_H_
#define _LOGIN_SERVICE_H_

#include "LoginWidget.h"
#include "json.hpp"

using json = nlohmann::json;

class LoginService : public QObject
{
	Q_OBJECT
public:
	LoginService();

	// ��¼
	void login(json& js);

	// չʾ��¼ҳ��
	void showLoginWgt();

signals:
	void showRegWgt_Service();
	void showHomeWgt_Service();

public slots:
	void showRegWgt_LoginService();
	void loginHome_LoginService(QString& Userid, QString& Password);

private:
	LoginWidget* m_pLoginWgt = nullptr;
};


#endif // ! _REG_SERVICE_H_
