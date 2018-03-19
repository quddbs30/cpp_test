#include <iostream>

using namespace std;

class A
{
  public:
    A() : num(0) {}
    static int ADD() 
    {
        a ++;
        return a;
    }

    void show()
    {
        cout << num << " "<< a << endl;
    }
  private:
    int num;  
    
    /***********
     * by07.so TIP static member 변수는 global 변수처럼 값을 초기화 해줘야 한다.
     ******/
    static int a;
};

int A::a = 10;

int main(void)
{
    A a;

    a.ADD();
    a.show();

    A::ADD();
    A::ADD();
    A::ADD();
    a.show();

    return 0;
}