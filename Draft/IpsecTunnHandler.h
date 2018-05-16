#ifndef __IPSECTUNNHANDLER_H__
#define __IPSECTUNNHANDLER_H__
#include <iostream> 
#include "AConfDbHandler.h"
using namespace std;

class IpsecTunnHandler : public AConfDbHandler<tIpsecTunnConf>
{
  public:
    static IpsecTunnHandler &getInstance()
    {
        static IpsecTunnHandler _instance;
        return _instance;
    }

    virtual void test() { rDataBase.test(); }

  private:
    IpsecTunnHandler() { cout << "ipsec tunn constructor!! " << endl; }
    IpsecTunnHandler(IpsecTunnHandler const&);
    void operator=(IpsecTunnHandler const&);
};

#endif /* __IPSECTUNNHANDLER_H__ */