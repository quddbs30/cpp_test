#include <iostream>
#include "IpsecTunnHandler.h"
using namespace std;

IpsecTunnHandler::IpsecTunnHandler()
{
    cout << "ipsec tunn constructor!! " << endl;
}

void IpsecTunnHandler::test()
{
    pDataBase->test();
}

void IpsecTunnHandler::setDataBase(void)
{
    // by07.so ConfigManager::getDbType() 으로 변경해야 함.
    switch (getDbType())
    {
    case DB_TYPE_YANG:
        pDataBase = YangIpsecTunn::getInstance();
        break;
    case DB_TYPE_PLD:
    default:
        pDataBase = PldIpsecTunn::getInstance();
        break;
    }
}
