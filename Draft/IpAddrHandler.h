#ifndef __IPADDRHANDLER_H__
#define __IPADDRHANDLER_H__
#include <iostream> 
#include "AConfDbHandler.h"
using namespace std;

typedef struct ipaddrconf
{
    string ifName;
    string address;
    int num;

    bool operator==(const int other_num) const
    {
        if (num == other_num) return true;
        else                  return false;
    }
    bool operator==(const string other_ifname) const
    {
        if (ifName == other_ifname) return true;
        else                        return false;
    }
} tIpAddrConf;

class IpAddrHandler : public AConfDbHandler<tIpAddrConf>
{
  public:
    static IpAddrHandler &getInstance()
    {
        static IpAddrHandler _instance;
        return _instance;
    }

  private:
    IpAddrHandler() { cout << "ip addr constructor!! " << endl; }
    IpAddrHandler(IpAddrHandler const&);
    void operator=(IpAddrHandler const&);
};

#endif /* __IPADDRHANDLER_H__ */