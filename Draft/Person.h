#ifndef __PERSON_H__
#define __PERSON_H__
#include <iostream>
#include "Config.h"

typedef struct t_info
{
    string name;
    int age;

    bool operator==(const struct t_info &other) const
    {
        if ((age == other.age) &&
            (name == other.name))
            return true;
        else
            return false;
    }
    bool operator==(const int other_age) const
    {
        if (age == other_age)
            return true;
        else
            return false;
    }
    bool operator==(const string other_name) const
    {
        if (name == other_name)
            return true;
        else
            return false;
    }
} tInfo;

class Person
{
  public:
    Person() : rConfig(Config<tInfo>::getInstance()) {}
    void add(tInfo info)
    {
        rConfig.addConfig(info);
    }
    void del(tInfo info)
    {
        rConfig.delConfig(info);    
    }
    void showAll(void)
    {
        list<tInfo> tmp;
        list<tInfo>::iterator tmpIt;

        int cnt = rConfig.getList(tmp);
        cout << "=== show all begin ===" << endl;
        for (tmpIt = tmp.begin(); tmpIt != tmp.end(); ++tmpIt)
            cout << tmpIt->name << " " << tmpIt->age << endl;
        cout << "=== show all end ===" << endl;
    }
    void getByName(string name)
    {
        tInfo tmp;
        if(0 != rConfig.getConfig(name, tmp))
            cout << "no data by name" << endl;
        else
            cout << "get by name : " << tmp.name << " " << tmp.age << endl;
    }
    void getByAge(int age)
    {
        tInfo tmp;
        if(0 != rConfig.getConfig(age, tmp))
            cout << "no data by age" << endl;
        else
            cout << "get by age : " << tmp.name << " " << tmp.age << endl;
    }
  private:
    Config<tInfo> &rConfig;
};

#endif /* __PERSON_H__ */