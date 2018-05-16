#ifndef __CONFIGSTRUCT_H__
#define __CONFIGSTRUCT_H__
#include <iostream>
using namespace std;

typedef struct ipsectunnconf
{
    string ifName1;
    string ifName2;
    string ifName3;
    int num;

//    REQUIRED for list.sort() 
//    bool operator>(const int other_num) const
    bool operator==(const int other_num) const
    {
        if (num == other_num) return true;
        else                  return false;
    }
    bool operator==(const string other_ifname) const
    {
        if ((ifName1 == other_ifname) ||
            (ifName2 == other_ifname) ||
            (ifName3 == other_ifname))   return true;
        else                             return false;
    }
} tIpsecTunnConf;

typedef struct ipaddrconf
{
    string ifName;
    string address;
    int num;

//    REQUIRED for list.sort() 
//    bool operator>(const int other_num) const
    bool operator==(const int other_num) const
    {
        if (num == other_num) return true;
        else                  return false;
    }
    bool operator==(const string other_ifname) const
    {
        if (ifName == other_ifname) return true;
        else                        return false;
    }
} tIpAddrConf;

#endif /* __CONFIGSTRUCT_H__ */