#ifndef __DATABASEPLD_H__
#define __DATABASEPLD_H__
#include <iostream>
#include "ADataBase.h"
using namespace std;

class DataBasePld : public ADataBase
{
  public:
    static DataBasePld &getInstance()
    {
        static DataBasePld _instance;
        return _instance;
    }
    virtual void test(void);

  private:
    DataBasePld() { cout << "DataBasePld constructor!!" << endl; }
    DataBasePld(DataBasePld const &);
    void operator=(DataBasePld const &);
};

void DataBasePld::test(void)
{
    cout << "In test() of PLD!!" << endl;
}
#endif /* __DATABASEPLD_H__ */