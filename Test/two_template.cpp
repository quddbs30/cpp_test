#include <iostream>
using namespace std;

template<typename T>
class test
{
  public:
    void set(T n)
    {
        val = n;
    }

    template<typename K>
    T *get(K k)
    {
        cout << "val is " << val << endl;
        cout << "k is " << k << endl;
        return &val;
    }

  private:
    T val;
};

int main()
{
    test<int> *int_t = new test<int>;
    int_t->set(123);
    int_t->get("int");

    test<string> *string_t = new test<string>;
    string_t->set("valval");
    string_t->get("string");

    return 0;
}