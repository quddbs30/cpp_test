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

  protected:
    Config<CONFTYPE> &rConfig;
    ADataBase *pDataBase;
#if 1
    // by07.so ConfigManager class 로 옮겨야 함.
    int getDbType(void) const;
#endif
    virtual void setDataBase(void) = 0;

  public:
    virtual void test(void) = 0;
};

#if 1 
// by07.so ConfigManager class 로 옮겨야 함.
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
#endif // by07.so ConfigManager class 로 옮겨야 함.
#endif /* __ACONFDBHANDLER_H__ */