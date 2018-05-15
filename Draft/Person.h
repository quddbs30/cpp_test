#ifndef __PERSON_H__
#define __PERSON_H__
#include <iostream>
#include "Data.h"

typedef struct t_info
{
    string name;
    int age;

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
    Person() { pData = Data<tInfo>::getInstance(); }
    void add(tInfo info)
    {
        pData->addData(info);
    }
    void getByName(string name)
    {
        tInfo tmp;
        if(0 != pData->getData(name, tmp))
            cout << "no data by name" << endl;
        else
            cout << "get by name : " << tmp.name << " " << tmp.age << endl;
    }
    void getByAge(int age)
    {
        tInfo tmp;
        if(0 != pData->getData(age, tmp))
            cout << "no data by age" << endl;
        else
            cout << "get by age : " << tmp.name << " " << tmp.age << endl;
    }
  private:
    Data<tInfo> *pData;
};

#endif /* __PERSON_H__ */