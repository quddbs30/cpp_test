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

    hd.getByAge(10);
    hd.getByAge(20);
    hd.getByName("ddong");
    hd.getByName("dong");
    

    return 0;
}