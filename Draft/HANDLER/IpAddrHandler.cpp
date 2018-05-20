#include <iostream>
#include "IpAddrHandler.h"
using namespace std;

IpAddrHandler::IpAddrHandler()
{
    cout << "ip addr constructor!! " << endl;
}

void IpAddrHandler::test()
{
    pDataBase->test();
}

void IpAddrHandler::setDataBase(void)
{
    // by07.so ConfigManager::getDbType() 으로 변경해야 함.
    switch (getDbType())
    {
    case DB_TYPE_YANG:
        pDataBase = YangIpAddr::getInstance();
        break;
    case DB_TYPE_PLD:
    default:
        pDataBase = PldIpAddr::getInstance();
        break;
    }
}
