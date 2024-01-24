#include "pub.cache.h"
#include "user.hpp"

#include <mutex>

PubCache* PubCache::s_pubCache = new PubCache;

PubCache* PubCache::getInstance() { return s_pubCache; }

PubCache::PubCache() {}
PubCache::~PubCache() {}

bool PubCache::setUser(std::string Userid, std::string Username, std::string Userphone, std::string Usertime)
{
	m_pMainUser = new User;
	m_pMainUser->setId(Userid);
	m_pMainUser->setName(Username);
	m_pMainUser->setPhone(Userphone);
	m_pMainUser->setTime(Usertime);

	return true;
}

User* PubCache::getUser()
{
	return m_pMainUser;
}

bool PubCache::getUserid(std::string& userid)
{
	userid = m_pMainUser->getId();
	return true;
}
