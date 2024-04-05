#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>

#include "user.hpp"
using namespace std;

// User���ORM��
class Group
{
public:
    Group(string id = "", string name = "")
    {
        this->id = id;
        this->name = name;
    }

    void setId(string id) { this->id = id; }
    void setName(string name) { this->name = name; }

    string getId() { return this->id; }
    string getName() { return this->name; }
    vector<User>& getUsers() { return this->users; }

private:
    string id;
    string name;
    vector<User> users;  // ��ȡ��ĳ�Ա
};

#endif