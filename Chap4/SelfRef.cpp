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
     *  by07.so TODO 참조자형 반환을 위해 this가 아닌 *this 를 사용하는 이유???
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