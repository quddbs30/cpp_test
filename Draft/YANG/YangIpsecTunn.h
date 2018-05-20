#ifndef __YANGIPSECTUNN_H__
#define __YANGIPSECTUNN_H__
#include <iostream>
#include "ADataBase.h"
using namespace std;

class YangIpsecTunn : public ADataBase
{
  public:
    static YangIpsecTunn *getInstance()
    {
        static YangIpsecTunn _instance;
        return &_instance;
    }
    virtual void test(void);

  private:
    virtual void setDbIdMap(void);

  private:
    YangIpsecTunn() { cout << "YangIpsecTunn constructor!!" << endl; }
    YangIpsecTunn(YangIpsecTunn const &);
    void operator=(YangIpsecTunn const &);
};
#endif /* __YANGIPSECTUNN_H__ */