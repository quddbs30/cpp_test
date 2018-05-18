#include <iostream>
#include "IpAddrHandler.h"
using namespace std;

IpAddrHandler::IpAddrHandler()
{
    cout << "ip addr constructor!! " << endl;
    setDataBase();
}

void IpAddrHandler::test()
{
    pDataBase->test();
}

void IpAddrHandler::setDataBase(void)
{
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
