// P. 264
#include <iostream>
using namespace std;

class CountryArea
{
    /**********************************
     * by07.so TIP const static 으로 멤버변수를 정의하여, #define XXX 처럼 사용할 수 있다.
     *             class name 과 함께 사용하기 때문에 대상에 대한 정보를 쉽게 노출할 수 있다.
     **************/
  public:
    const static int RUSSIA = 1707540;
};

int main(void)
{
    cout << "Russia : " << CountryArea::RUSSIA << endl;
    return 0;
}