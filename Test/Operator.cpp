#include <iostream>
using namespace std;

int main(void)
{
    int i = 0;
    char a[10];

    a[i++] = 'z';
    a[i++] = 'y';
    a[i++] = 'x';
    a[i++] = 'w';
    a[i++] = 'q';

    for(i = 0; i < 10; i++)
        cout << a[i] << " ";

    return 0;
}