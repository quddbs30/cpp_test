#include <iostream>
using namespace std;

class AFirst
{
  public:
    AFirst() { first_construct(); }
    virtual ~AFirst() { cout << "AFirst Destructor!!" << endl; }

  private:
    void first_construct(void);

  public:
  //protected:
    virtual void doit(void) = 0;
};

void AFirst::first_construct(void)
{
    cout << "first_construct()" << endl;
}

class ASecond : public AFirst
{
  public:
    ASecond() { second_construct(); }
    virtual ~ASecond() { cout << "ASecond Destructor!!" << endl; }

  private:
    void second_construct(void);

  public:
  //protected:
    virtual void doit(void) = 0;
};

void ASecond::second_construct(void)
{
    cout << "second_construct()" << endl;
}

class Derived : public ASecond
{
  public:
    Derived() { cout << "Derived constructor" << endl; }
    virtual void doit(void);
};

void Derived::doit(void)
{
    cout << "===doit() of Derived" << endl;
}

int main(void)
{
    AFirst *pObj = new Derived;

    pObj->doit();

    delete pObj;

    return 0;
}
