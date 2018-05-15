// P. 192
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
  private:
    char *name;
    int age;

  public:
    Person(char *myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    Person()
    {
        name = NULL;
        age = 0;
        cout << "called Person()" << endl;
    }
    void SetPersonInfo(char *myname, int myage)
    {
        name = myname;
        age = myage;
    }
    /*******************
     * by07.so NOTE cont 함수 내에서는 '멤버변수'를 변경하지 않겠다고 선언하는 것 이다.
     * 실수로 멤버변수를 변경할 경우 컴파일 에러가 발생된다.
     * const 함수 내에서는 const 아닌 함수의 호출도 제한된다.
     **********************/
    void ShowPersonInfo() const
    {
        cout << "Name : " << name << ", ";
        cout << "Age  : " << age << endl;
    }
    ~Person()
    {
        delete []name;
        cout << "called destructor" << endl;
    }
};

int main(void)
{
    Person parr[3];
    char namestr[100];
    char *strptr;
    int age;
    int len;

    for(int i = 0; i < 3; i++)
    {
        cout << "Name : ";
        cin >> namestr;
        cout << "Age : ";
        cin >> age;
        len = strlen(namestr) + 1;
        strptr = new char[len];
        strcpy(strptr, namestr);
        parr[i].SetPersonInfo(strptr, age);
    }

    parr[0].ShowPersonInfo();
    parr[1].ShowPersonInfo();
    parr[2].ShowPersonInfo();
    return 0;
}