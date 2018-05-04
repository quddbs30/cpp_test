#include <iostream>
#include <algorithm>
#include <list>
#include <cstring>
using namespace std;

typedef struct t_data
{
    char name[10];
    int age;

    bool operator==(const struct t_data &other)
    {
        if ((0 == strcmp(name, other.name)) &&
            age == other.age)
            return true;
        else
            return false;
    }
} tData;

int main(void)
{
    list<tData> lTemp;

    tData d1 = {"d1", 1};
    tData d2 = {"d2", 2};
    tData d3 = {"d3", 3};

    lTemp.push_back(d1);
    lTemp.push_back(d2);
    lTemp.push_back(d3);

    tData tt = {"d2", 2};
    if (find(lTemp.begin(), lTemp.end(), tt) != lTemp.end())
        cout << "got it " << endl;
    else
        cout << "not saved " << endl;

    return 0;
}