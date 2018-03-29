// P.238
#include <iostream>
using namespace std;

class SoSimple
{
  private:
    int num;

  public:
    SoSimple(int n) : num(n)
    {
        cout << "New Obj: " << this << endl;
    }
    SoSimple(const SoSimple &copy) : num(copy.num)
    {
        cout << "New Copy obj: " << this << endl;
    }
    ~SoSimple()
    {
        cout << "Destroy obj: " << this << endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    cout << "Parm ADR: " << &ob << endl;
    return ob;
}

int main(void)
{
    SoSimple obj(7);
    SimpleFuncObj(obj);

    cout << endl;
    /*********************
     * by07.so NOTE tempRef 객체가 새로 생성되고 반환되는 객체가 대입연산되는 것처럼 보이지만,
     *              사실은 반환되는 임시객체에 tempRef 라는 이름을 할당한다.(효율성)
     **/
    SoSimple tempRef = SimpleFuncObj(obj);
    cout << "Return obj: " << &tempRef << endl;
    return 0;
}