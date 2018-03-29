// P.232
#include <iostream>
using namespace std;

class SoSimple
{
  private:
    int num;

  public:
    SoSimple(int n) : num(n)
    { }
    SoSimple(const SoSimple &copy) : num(copy.num)
    {
        cout << "Called copy-constructor" << endl;
    }
    SoSimple &AddNum(int n)
    {
        num += n;
        return *this;
    }
    void ShowData()
    {
        cout << "num :" << num << endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    cout << "Before return" << endl;
    return ob;
}

int main(void)
{
    SoSimple obj(7);
    /***********
     * by07.so NOTE SimpleFuncObj() 가 반환하는 임시객체의 AddNum()과 ShowData()가 호출됨.
     *              obj 객체와 별개이다. 그래서 ShowData()의 출력값이 다르다.
     */
    SimpleFuncObj(obj).AddNum(30).ShowData();
    obj.ShowData();

    return 0;
}