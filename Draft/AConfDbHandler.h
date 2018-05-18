#ifndef __ACONFDBHANDLER_H__
#define __ACONFDBHANDLER_H__
#include <iostream>
#include "ADataBase.h"
#include "Config.h"
#include "configStruct.h"

template <typename CONFTYPE>
class AConfDbHandler
{
  public:
    AConfDbHandler()
        : rConfig(Config<CONFTYPE>::getInstance()), pDataBase(NULL) {}
    virtual ~AConfDbHandler() {}

  public:
    virtual void test(void) = 0;

  protected:
    Config<CONFTYPE> &rConfig;
    ADataBase<CONFTYPE> *pDataBase;
    int getDbType(void) const;
    virtual void setDataBase(void) = 0;
};

#define DB_TYPE_PLD     0
#define DB_TYPE_YANG    1
template <typename CONFTYPE>
int AConfDbHandler<CONFTYPE>::getDbType(void) const
{
    /* by07.so type 에 할당하기 위한 함수 정의 필요. 
       해당 함수는 실행 환경(FOO 등..)에 따라 반환한다. */
#if 1
    static int type = DB_TYPE_PLD;
#else
    static int type = DB_TYPE_YANG;
#endif
    return type;
}
#endif /* __ACONFDBHANDLER_H__ */