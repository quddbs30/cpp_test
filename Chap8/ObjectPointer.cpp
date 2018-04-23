// P. 327
#include <iostream>
using namespace std;

class Person
{
  public:
    void Sleep() { cout << "Sleep" << endl; }
};

class Student : public Person
{
  public:
    void Study() { cout << "Study" << endl; }
};

class PartTimeStudent : public Student
{
  public:
    void Work() { cout << "Work" << endl; }
};

int main(void)
{
/****************************
 * by07.so NOTE 기초클래스의 포인터형을 사용해 객체에 접근할 때에는 기초클래스의 메서드만 사용 가능하다.
 *              C++ 컴파일러는 포인터 연산의 가능성 여부를 판단할 때, 포인터의 자료형을 기준으로 판단하지,
 *              실제 가리키는 객체의 자료형을 기준으로 판단하지 않는다.(P. 341) 결론적으로 포인터형에 
 *              해당하는 클래스에 정의된 멤버에만 접근이 가능한 것이다.
 **/
#if 0
    Person *ptr1 = new Student();
    Person *ptr2 = new PartTimeStudent();
#else
/****************************
 * by07.so NOTE 유도클래스의 포인터를 기초클래스의 포인터에 할당하여 사용하는 것도 가능하다. 하지만,
 *              그 반대는 성립하지 않는다.
 ***/
    Student *ptr1 = new Student();
    PartTimeStudent *ptr2 = new PartTimeStudent();
    Person *ptr3 = ptr1;
    Person *ptr4 = ptr2;
#endif
    ptr1->Study();
    ptr2->Work();

    ptr3->Sleep();
    ptr4->Sleep();

    delete ptr1;
    delete ptr2;
    delete ptr3;
    delete ptr4;

    return 0;
}
