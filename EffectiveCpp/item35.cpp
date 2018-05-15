
/**************
 * by07.so NOTE strategy pattern
 *              '고전적인, 표준적인' strategy pattern 은 p.265 참조
 *************/
#include <iostream>
using namespace std;
class GameChar;

int defaultHealthCalc(GameChar &gc);

class GameChar
{
  public:
    typedef int (*HealthCalcFunc)(GameChar &);

    explicit GameChar(HealthCalcFunc hcf = defaultHealthCalc)
        : healthFunc(hcf), health(100) {}

    int healthValue() { return healthFunc(*this); }
    int minusHealth(int i) { health -= i; return health; }
    int plusHealth(int i) { health += i; return health; }
  private:
    HealthCalcFunc healthFunc;
    int health;
};

int defaultHealthCalc(class GameChar &gc)
{
    return gc.minusHealth(1);
}

class EvilBadGuy : public GameChar
{
  public:
    explicit EvilBadGuy(HealthCalcFunc hcf = defaultHealthCalc)
        : GameChar(hcf) {}
};

int loseHealthQuick(GameChar &gc)
{
    return gc.minusHealth(10);
}
int loseHealthSlowly(GameChar &gc)
{
    return gc.minusHealth(5);
}

int main(void)
{
    EvilBadGuy ebg1(loseHealthQuick);
    EvilBadGuy ebg2(loseHealthSlowly);

    cout << ebg1.healthValue() << endl;
    cout << ebg2.healthValue() << endl;
//find()
    return 0;
}
