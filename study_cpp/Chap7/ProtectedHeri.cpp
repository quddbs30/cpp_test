// P.300
#include <iostream>
using namespace std;

class Base
{
  private:
    int num1;
  protected:
    int num2;
  public:
    int num3;

    Base() : num1(1), num2(2), num3(3)
    {}
};

/*********************
 * by07.so NOTE 상속에 사용된 접근지시자(X) 보다 넓은 범위의 base class 지시자들을 "X로 변경하여 상속"한다. 
 *              "X로 변경하여 상속"의 의미는, derived class 가 상속받은 이후의 지시자를 말한다.
 *   예시) private 으로 상속받은 경우,
 *      Base        Derived
 *     private   =>  접근불가  (base 의 private 은 어떠한 경우에도 derived 에서 접근불가)
 *     protected =>  private (derived 에서 private 처럼 접근 가능함.)
 *     public    =>  private 
 *   그래서 private 으로 상속받은 derived 를 다시 상속받은 class 는 base의 모든 멤버에 접근불가하게 된다.
 ******/
//class Derived : private Base 
class Derived : protected Base 
//class Derived : public Base 
{
    public:
    void show(void)
    {
        cout << num2 << " " << num3 << endl;
    }
};

int main(void)
{
    Derived drv;
    drv.show();
    /* private, protected 에서 에러 발생됨. */
    //cout << drv.num3 << endl; 
    return 0;
}