#include <iostream>
#include "IpsecTunnHandler.h"
using namespace std;

IpsecTunnHandler::IpsecTunnHandler()
{
    cout << "ipsec tunn constructor!! " << endl;
}

void IpsecTunnHandler::test()
{
    rDataBase.test();
}
