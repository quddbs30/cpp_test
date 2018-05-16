#ifndef __DATABASEYANG_H__
#define __DATABASEYANG_H__
#include <iostream>
#include "ADataBase.h"
using namespace std;

class DataBaseYang : public ADataBase
{
  public:
    static DataBaseYang &getInstance()
    {
        static DataBaseYang _instance;
        return _instance;
    }
    virtual void test(void);

  private:
    DataBaseYang() { cout << "DataBaseYang constructor!!" << endl; }
    DataBaseYang(DataBaseYang const &);
    void operator=(DataBaseYang const &);
};

void DataBaseYang::test(void)
{
    cout << "In test() of YANG!!" << endl;
}
#endif /* __DATABASEYANG_H__ */