#ifndef _PUB_CACHE_H_
#define _PUB_CACHE_H_

#include "user.hpp"
#include <string>
#include <vector>

class PubCache
{
public:
	// ��̬�ӿ�
	static PubCache* getInstance();

	// �û���ֵ
	bool setUser(std::string Userid, std::string Username, std::string Userphone, std::string Usertime);

	// ��ȡ�û�
	User* getUser();

	// ��ȡ�û�id
	bool getUserid(std::string& userid);

	std::string getCurrentDateTimeMySQLFormat();

private:
	static PubCache* s_pubCache;

	User* m_pMainUser = nullptr;

	PubCache();
	~PubCache();
};

#endif
