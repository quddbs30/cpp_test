// P.221
#include <iostream>
#include <cstring>
using namespace std;

/***********
 * by07.so NOTE 복사 생성자가 호출 되는 시점은 아래 3가지 이다. (P. 227)
 *  1. 기존에 생성된 객체를 이용해서 새로운 객체를 초기화하는 경우.
 *  2. Call-by-value 방식의 함수 호출 과정에서 객체를 인자로 전달하는 경우.
 *  3. 객체를 반환하되, 참조형으로 반환하지 않는 경우.
 * 복사 생성자의 호출횟수는 프로그램의 성능과 관계가 있기 때문에, 호출시기를 이해하는 것은 중요!!!
 ***********/

class Person
{
  private:
    char *name;
    int age;

  public:
    Person(const char *myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    /*********************
     * by07.so NOTE 디폴트 복사 생성자만 있다면, double free 가 발생한다.
     *              그래서 아래와 같이 복사 생성자를 새로 정의해야한다.
     **************/
    Person(const Person &copy) : age(copy.age)
    {
        int len = strlen(copy.name) + 1;
        name = new char[len];
        strcpy(name, copy.name);
    }

    void ShowPersonInfo() const
    {
        cout << name << endl;
        cout << age << endl;
    }
    ~Person()
    {
        delete []name;
        cout << "called destructor" << endl;
    }
};

int main(void)
{
    Person man1("Lee don woo", 29);
    Person man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}