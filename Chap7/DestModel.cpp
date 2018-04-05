// P.293
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

class Person
{
  private:
    char *name;

  public:
    Person()
    {
        name = new char[10];
        sprintf(name, "No_name");
    }
    Person(const char *myname)
    {
        name = new char[strlen(myname) + 1];
        strcpy(name, myname);
    }
    ~Person()
    {
        delete[] name;
    }
    void WhatYourName() const
    {
        cout << "My name is " << name << endl;
    }
};

class UnivStudent : public Person
{
  private:
    char *major;

  public:
  /***********************
   * by07.so NOTE 유도클래스의 객체 생성 과정에서 기초클래스의 생성자는 100% 호출된다.
   *              유도클래스의 생성자에서 기초클래스의 생성자 호출을 명시하지 않으면, 기초클래스의 
   *              void 생성자가 호출된다.
   * by07.so NOTE [중요!!] 클래스의 생성자에서 멤버를 초기화해야 한다.(기본 원칙!!!)
   ****************/
    UnivStudent()
    {
        major = new char[10];
        sprintf(major, "No_major");
    }
    UnivStudent(const char *myname, const char *mymajor)
        : Person(myname)
    {
        major = new char[strlen(mymajor) + 1];
        strcpy(major, mymajor);
    }
   /******************* 
    * by07.so NOTE [중요!!] 클래스에서 동적할당한 메모리는 소멸자에서 해제 (기본 원칙!!!)
    *****************/
    ~UnivStudent()
    {
        delete []major;
    }
    void WhoAreYou() const
    {
        WhatYourName();
        cout << "My major is " << major << endl;
    }
};

int main(void)
{
    UnivStudent st1;
    st1.WhoAreYou();
    UnivStudent st2("hong", "Mathematics");
    st2.WhoAreYou();

    return 0;
}