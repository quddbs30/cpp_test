#if 1
#include <iostream>
#include "IpAddrHandler.h"
#include "IpsecTunnHandler.h"
using namespace std;

int main(void)
{
    AConfDbHandler<tIpsecTunnConf> &rIpsecInstance = IpsecTunnHandler::getInstance();
    AConfDbHandler<tIpAddrConf> &rIpAddrInstance = IpAddrHandler::getInstance();


    return 0;
}
#else
#include <iostream>
#include "Person.h"
using namespace std;

int main(void)
{
    Person hd;

    tInfo a;
    a.name = "garbage";
    a.age = 20;
    hd.add(a);
    a.name = "ddong";
    a.age = 10;
    hd.add(a);
    hd.add(a);

    hd.getByAge(10);
    hd.getByAge(20);
    hd.getByName("ddong");
    hd.getByName("dong");

    hd.showAll();
    a.name = "garbage";
    a.age = 20;
    hd.del(a);
    hd.getByName("ddong");
    hd.getByAge(20);

    hd.showAll();


    return 0;
}
#endif