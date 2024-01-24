#ifndef _USER_H_
#define _USER_H_

#include <string>

// User表的ORM类 对象关系映射 避免原生sql 而是操作对象
class User
{
public:
    User(std::string id = "", std::string name = "", std::string pwd = "",
        std::string phone = "", std::string time = "",
        std::string state = "offline")
    {
        this->m_iUserid = id;
        this->m_strUsername = name;
        this->m_strPassword = pwd;
        this->m_strPhone = phone;
        this->m_strTime = time;
        this->m_strState = state;
    }

    void setId(std::string id) { this->m_iUserid = id; }
    void setName(std::string name) { this->m_strUsername = name; }
    void setPwd(std::string pwd) { this->m_strPassword = pwd; }
    void setPhone(std::string phone) { this->m_strPhone = phone; }
    void setTime(std::string time) { this->m_strTime = time; }
    void setState(std::string state) { this->m_strState = state; }

    std::string getId() { return this->m_iUserid; }
    std::string getName() { return this->m_strUsername; }
    std::string getPwd() { return this->m_strPassword; }
    std::string getPhone() { return this->m_strPhone; }
    std::string getTime() { return this->m_strTime; }
    std::string getState() { return this->m_strState; }

protected:
    std::string m_iUserid;
    std::string m_strUsername;
    std::string m_strPassword;
    std::string m_strPhone;
    std::string m_strTime;
    std::string m_strState;
};

#endif