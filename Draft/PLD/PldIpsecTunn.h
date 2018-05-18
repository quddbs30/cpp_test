#ifndef __PLDIPSECTUNN_H__
#define __PLDIPSECTUNN_H__
#include <iostream>
#include "ADataBase.h"
using namespace std;

class PldIpsecTunn : public ADataBase<tIpsecTunnConf>
{
  public:
    static PldIpsecTunn *getInstance()
    {
        static PldIpsecTunn _instance;
        return &_instance;
    }
    virtual void test(void);

  private:
    virtual void setDbIdMap(void);

  private:
    PldIpsecTunn() { cout << "PldIpsecTunn constructor!!" << endl; }
    PldIpsecTunn(PldIpsecTunn const &);
    void operator=(PldIpsecTunn const &);
};
#endif /* __PLDIPSECTUNN_H__ */