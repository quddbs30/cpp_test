// P. 73
#include <iostream>
using namespace std;

int main(void)
{
    int num = 12;
    int *ptr = &num;
    int **dptr = &ptr;

    /****************
     * by07.so TIP 포인터 변수에 대한 참조자 선언은 아래와 같다.
     ******************/
    int &ref = num;
    int *(&pref) = ptr;
    int **(&dpref) = dptr;

    cout << ref << endl;
    cout << *pref << endl;
    cout << **dpref << endl;
    return 0;
}