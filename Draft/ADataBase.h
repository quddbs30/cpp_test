#ifndef __ADATABASE_H__
#define __ADATABASE_H__
#include <iostream>
#include "configStruct.h"
#include "DataBaseId.h"
using namespace std;

class ADataBase
{
  public:
    virtual ~ADataBase() {}

  protected:
    virtual void setDbIdMap(void) = 0;

  /* TEMP */
  public:
    virtual void test() = 0;
};

#endif /* __ADATABASE_H__ */