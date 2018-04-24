
// http://cafe.naver.com/myprogramming/16048
// http://cafe.naver.com/multism/6805


#include <iostream>
using namespace std;

template<typename T>
class Cstate
{
    public:
    virtual ~Cstate() {}
    virtual void Enter(T*) = 0;
};

template<typename T>
class CNormal : public Cstate<T>
{
    public:
    void Enter(*T);
    static CNormal *GetInstance();
};

template<typename T>
void CNormal<T>::Enter(T *p)
{
    cout << p << endl;
}

template<typename T>
CNormal<T> *CNormal<T>::GetInstance()
{
    // 이 함수가 호출될 때 전달될 타입이 결정되었으므로,
    // 객체 생성 시 템플릿 인자는 필요없다.
    static CNormal Instance;
    return &Instance;
}

int main(void)
{
    // char 타입에 맞는 클래스의 객체를 생성
    CNormal<char> *p = CNormal<char>::GetInstance();
    p->Enter("Enterkk");
    return 0;
}