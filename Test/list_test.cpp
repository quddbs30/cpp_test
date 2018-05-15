#include <iostream>
#include <algorithm>
#include <list>
#include <cstring>
using namespace std;

typedef struct t_data
{
    char name[10];
    int age;

    bool operator==(const struct t_data &other) const
    {
        if ((0 == strcmp(name, other.name)) &&
            age == other.age)
            return true;
        else
            return false;
    }

    bool operator==(const char *other_name) const
    {
        if (0 == strcmp(name, other_name))
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
    /*********************
     * by07.so TIP List 에서 특정 원소를 탐색할 때 아래와 같이 하면 된다.
     *******************/

    list<tData>::iterator lTempIt;
    if ((lTempIt = find(lTemp.begin(), lTemp.end(), tt)) != lTemp.end())
        cout << "got it " << lTempIt->name << " " << lTempIt->age << endl;
    else
        cout << "not saved " << endl;

    if ((lTempIt = find(lTemp.begin(), lTemp.end(), "d3")) != lTemp.end())
        cout << "got it " << lTempIt->name << " " << lTempIt->age << endl;
    else
        cout << "not saved " << endl;

    return 0;
}
