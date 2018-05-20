#ifndef __IPSECTUNNHANDLER_H__
#define __IPSECTUNNHANDLER_H__
#include <iostream> 
#include "AConfDbHandler.h"
#include "PldIpsecTunn.h"
#include "YangIpsecTunn.h"
using namespace std;

class IpsecTunnHandler : public AConfDbHandler<tIpsecTunnConf>
{
  public:
    static IpsecTunnHandler &getInstance()
    {
        static IpsecTunnHandler _instance;
        _instance.setDataBase();
        return _instance;
    }

    virtual void test();

  private:
    virtual void setDataBase(void);

  private:
    IpsecTunnHandler();
    IpsecTunnHandler(IpsecTunnHandler const&);
    void operator=(IpsecTunnHandler const&);
};

#endif /* __IPSECTUNNHANDLER_H__ */