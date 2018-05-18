#include <iostream>
#include "IpsecTunnHandler.h"
using namespace std;

IpsecTunnHandler::IpsecTunnHandler()
{
    cout << "ipsec tunn constructor!! " << endl;
    setDataBase();
}

void IpsecTunnHandler::test()
{
    pDataBase->test();
}

void IpsecTunnHandler::setDataBase(void)
{
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
