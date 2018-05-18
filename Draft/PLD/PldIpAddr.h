#ifndef __PLDIPADDR_H__
#define __PLDIPADDR_H__
#include <iostream>
#include "ADataBase.h"
using namespace std;

class PldIpAddr : public ADataBase<tIpAddrConf>
{
  public:
    static PldIpAddr *getInstance()
    {
        static PldIpAddr _instance;
        return &_instance;
    }
    virtual void test(void);

  private:
    virtual void setDbIdMap(void);

  private:
    PldIpAddr() { cout << "PldIpAddr constructor!!" << endl; }
    PldIpAddr(PldIpAddr const &);
    void operator=(PldIpAddr const &);
};
#endif /* __PLDIPADDR_H__ */