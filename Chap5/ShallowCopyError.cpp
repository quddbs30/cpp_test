// P.221
#include <iostream>
#include <cstring>
using namespace std;

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