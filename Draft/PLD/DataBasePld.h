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
    virtual void setDbIdMap(void);

  private:
    DataBasePld() { cout << "DataBasePld constructor!!" << endl; }
    DataBasePld(DataBasePld const &);
    void operator=(DataBasePld const &);
};
#endif /* __DATABASEPLD_H__ */