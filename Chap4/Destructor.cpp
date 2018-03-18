// P.188
#include <iostream>
#include <cstring>
#define BY07_TEST
using namespace std;
/******************************
 * by07.so TIP
 * 소멸자는 대게 생성자에서 할당한 리소스의 소멸에 사용된다.
 * 객체 소멸 과정에서 자동으로 처리돼야 할 일을 기술한다. 
**********************************/
class Person
{
  private:
    char *name;
    int age;

  public:
    // by07.so NOTE 문자열 상수를 전달받으므로 const 로 선언돼야 한다.(책에는 없었음. warning 발생.)
    Person(const char *myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    void ShowPersonInfo(void) const
    {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }
    ~Person()
    {
        delete name;
        cout << "called destructor" << endl;
    }
};

int main(void)
{
 /******************************
 * by07.so TIP
 * 객체 생성 방법에 따라 소멸자 호출 여부가 달라진다.
 ******/
#ifdef BY07_TEST
    Person *man1 = new Person("Lee dong woo", 24);
    Person *man2 = new Person("Kim gae ddong", 54);
    man1->ShowPersonInfo();
    man2->ShowPersonInfo();
    delete man1; // delete 필요
    delete man2;
#else
    Person man1("Lee dong woo", 24);
    Person man2("Kim gae ddong", 54);
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
#endif
    return 0;
}