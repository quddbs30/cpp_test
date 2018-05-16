#ifndef __ACONFDBHANDLER_H__
#define __ACONFDBHANDLER_H__
#include <iostream>
#include "Config.h"

template <typename CONFTYPE>
class AConfDbHandler
{
  public:
    AConfDbHandler() : rConfig(Config<CONFTYPE>::getInstance()) {}
    virtual ~AConfDbHandler() = 0;

  protected:
    Config<CONFTYPE> &rConfig;
};

// 함수 본문을 정의한 이유 : Effective Cpp P.94 참조
template <typename CONFTYPE>
AConfDbHandler<CONFTYPE>::~AConfDbHandler() {}

#endif /* __ACONFDBHANDLER_H__ */