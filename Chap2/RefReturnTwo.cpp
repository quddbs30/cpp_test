// P. 85
#include <iostream>
using namespace std;

int &RefRetFuncOne(int &ref)
{
    ref++;
    return ref;
}

int main(void)
{
    int num1 = 1;
#if 1
    /********** by07.so TIP 참조자 반환 함수의 반환값을 참조자 변수에도 저장할 수 있고,
     * 일반 변수에도 저장할 수 있다. 당연히 그 사용법은 다르다.
     *************/
    int &num2 = RefRetFuncOne(num1);
#else
    int num2 = RefRetFuncOne(num1);
#endif

    num1++;
    num2+=100;
    cout << num1 << endl;
    cout << num2 << endl;
    return 0;
}