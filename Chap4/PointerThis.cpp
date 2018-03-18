// P. 196
#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
  private:
    int num;

  public:
  /*************
   * by07.so TIP 
   * member initializer 를 사용하여 멤버변수를 초기화하고 있다.
   ***************/
    SoSimple(int n) : num(n)
    {
        cout << "num = " << num << ", ";
        cout << "address = " << this << endl;
    }
    void ShowSimpleData() { cout << num << endl; }
    SoSimple *GetThisPointer() { return this; }
};

int main(void)
{
    SoSimple sim1(100);
    SoSimple *ptr1 = sim1.GetThisPointer();  // sim1 객체의 주소값 저장
    cout << ptr1 << ", ";
    ptr1->ShowSimpleData();

    SoSimple sim2(200);
    SoSimple *ptr2 = sim2.GetThisPointer();
    cout << ptr2 << ", ";
    ptr2->ShowSimpleData();

    return 0;
}