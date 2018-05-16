#ifndef __IPADDRHANDLER_H__
#define __IPADDRHANDLER_H__
#include <iostream> 
#include "AConfDbHandler.h"
using namespace std;

class IpAddrHandler : public AConfDbHandler<tIpAddrConf>
{
  public:
    static IpAddrHandler &getInstance()
    {
        static IpAddrHandler _instance;
        return _instance;
    }

    virtual void test() { rDataBase.test(); }

  private:
    IpAddrHandler() { cout << "ip addr constructor!! " << endl; }
    IpAddrHandler(IpAddrHandler const&);
    void operator=(IpAddrHandler const&);
};

#endif /* __IPADDRHANDLER_H__ */