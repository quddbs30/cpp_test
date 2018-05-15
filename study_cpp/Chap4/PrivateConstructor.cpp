// P.186
#include <iostream>
#define BY07_TEST
using namespace std;
/******************************
 * by07.so TIP private 생성자는 객체의 생성방법을 
 * 제한하고자 하는 경우 유용하게 사용된다.
**********************************/
class AAA 
{
  private:
    int num;

  public:
    AAA() : num(0) {}

    /*******************
     * by07.so TODO static 과 const 는 함께 사용되지 못 한다. 
     * 왜 그런지?? static 과 const 의 정확한 의미를 알아야 한다.
     ******/
#ifdef BY07_TEST
    static AAA &CreateInitObj(int n) // const
#else
    AAA &CreateInitObj(int n) const
#endif
    {
        AAA *ptr = new AAA(n);
        return *ptr;
    }
    void ShowNum() const { cout << num << endl; }

  private:
    AAA(int n) : num(n) {}
};

class BBB
{
  public:
    void outMsg(void) { cout << "i am b" << endl; }
};

int main(void)
{
    AAA base;
    base.ShowNum();

    AAA &obj1 = base.CreateInitObj(3);
    obj1.ShowNum();

    AAA &obj2 = base.CreateInitObj(12);
    obj2.ShowNum();

#ifdef BY07_TEST
    AAA &obj3 = AAA::CreateInitObj(33);
    obj3.ShowNum();

    delete &obj3;
#endif
    delete &obj1;
    delete &obj2;

    return 0;
}