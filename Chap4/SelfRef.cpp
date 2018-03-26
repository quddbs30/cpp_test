// P. 200
#include <iostream>
using namespace std;

class SelfRef
{
  private:
    int num;

  public:
    SelfRef(int n) : num(n)
    {
        cout << "객체생성" << endl;
    }
    /************
     * by07.so TODO 참조자형 반환을 위해 this가 아닌 *this 를 사용하는 이유???
     * Answer : (non-const)참조자형 변수는 lvalue 로서, 변경 가능한 변수를 참조해야 하기 때문.
     *          *this 를 반환해야 변경 가능한 변수의 '참조 정보'를 할당 받을 수 있다.
     *          http://bunhere.tistory.com/409
    *****/ 
    SelfRef &Adder(int n)
    {
        num += n;
        return *this;
    }
    SelfRef &ShowTwoNumber()
    {
        cout << num << endl;
        return *this;
    }

    SelfRef &myRef = *this;
};

int main(void)
{
    SelfRef obj(3);
    SelfRef &ref = obj.Adder(2);

    obj.ShowTwoNumber();
    ref.ShowTwoNumber();

    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
    return 0;
}