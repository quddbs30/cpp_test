#ifndef __ACONFDBHANDLER_H__
#define __ACONFDBHANDLER_H__
#include <iostream>
#include "ADataBase.h"
#include "Config.h"
#include "configStruct.h"
#include "DataBasePld.h"
#include "DataBaseYang.h"

#define DB_TYPE_PLD     0
#define DB_TYPE_YANG    1

class DbType
{
  public:
    static int getDbType()
    {
        /* by07.so type 에 할당하기 위한 함수 정의 필요. 
       해당 함수는 실행 환경(FOO 등..)에 따라 반환한다. */
        static int type = DB_TYPE_PLD;
        //static int type = DB_TYPE_YANG;
        return type;
    }

    static ADataBase &getDataBase(void)
    {
        switch (getDbType())
        {
        case DB_TYPE_YANG:
            return DataBaseYang::getInstance();
        case DB_TYPE_PLD:
        default:
            return DataBasePld::getInstance();
        }
    }
};

template <typename CONFTYPE>
class AConfDbHandler
{
  public:
    AConfDbHandler()
        : rConfig(Config<CONFTYPE>::getInstance()), rDataBase(DbType::getDataBase()) {}
    virtual ~AConfDbHandler() {}

  public:
    virtual void test(void) = 0;

  protected:
    Config<CONFTYPE> &rConfig;
    ADataBase &rDataBase;
};
#endif /* __ACONFDBHANDLER_H__ */