#ifndef __IPSECTUNNHANDLER_H__
#define __IPSECTUNNHANDLER_H__
#include <iostream> 
#include "AConfDbHandler.h"
using namespace std;

typedef struct ipsectunnconf
{
    string ifName1;
    string ifName2;
    string ifName3;
    int num;

    bool operator==(const int other_num) const
    {
        if (num == other_num) return true;
        else                  return false;
    }
    bool operator==(const string other_ifname) const
    {
        if ((ifName1 == other_ifname) ||
            (ifName2 == other_ifname) ||
            (ifName3 == other_ifname))   return true;
        else                             return false;
    }
} tIpsecTunnConf;

class IpsecTunnHandler : public AConfDbHandler<tIpsecTunnConf>
{
  public:
    static IpsecTunnHandler &getInstance()
    {
        static IpsecTunnHandler _instance;
        return _instance;
    }

  private:
    IpsecTunnHandler() { cout << "ipsec tunn constructor!! " << endl; }
    IpsecTunnHandler(IpsecTunnHandler const&);
    void operator=(IpsecTunnHandler const&);
};

#endif /* __IPSECTUNNHANDLER_H__ */