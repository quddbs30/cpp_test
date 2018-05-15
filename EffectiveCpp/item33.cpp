#include <iostream>
using namespace std;

class Base
{
  public:
    virtual void Show() { cout << "Base show(void)" << endl; }
    virtual void Show(int a) { cout << "Base show(" << a << ")" << endl; }
    virtual void mShow() { cout << "Base mShow(void)" << endl; }
    virtual void mShow(int a) { cout << "Base mShow(" << a << ")" << endl; }
};

class Derived : public Base
{
    public:
    virtual void Show() { cout << "Derived show(void)" << endl; }
    virtual void mShow() { cout << "Derived mShow(void)" << endl; }
};

int main(void)
{
    Derived d;
//    d.Show(1); <-error
    d.Show();
    d.mShow();

    return 0;
}