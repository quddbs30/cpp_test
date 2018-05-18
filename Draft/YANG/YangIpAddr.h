#ifndef __YANGIPADDR_H__
#define __YANGIPADDR_H__
#include <iostream>
#include "ADataBase.h"
using namespace std;

class YangIpAddr : public ADataBase<tIpAddrConf>
{
  public:
    static YangIpAddr *getInstance()
    {
        static YangIpAddr _instance;
        return &_instance;
    }
    virtual void test(void);

  private:
    virtual void setDbIdMap(void);

  private:
    YangIpAddr() { cout << "YangIpAddr constructor!!" << endl; }
    YangIpAddr(YangIpAddr const &);
    void operator=(YangIpAddr const &);
};
#endif /* __YANGIPADDR_H__ */