// P. 90
#include <iostream>
using namespace std;

int main(void)
{
    const int num = 12;
    const int *pnum = &num;
    const int *(&rpnum) = pnum;

    cout << *pnum << endl;
    cout << *rpnum << endl;

    return 0; 
}