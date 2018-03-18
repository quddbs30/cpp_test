// P.190
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

namespace COMP_POS
{
enum
{
    CLERK,
    SENIOR,
    ASSIST,
    MANAGER
};
}

class NameCard
{
  private:
    char *name;
    char *company;
    char *phone;
    int position;

  public:
    NameCard(const char *name, const char *company, const char *phone, int position)
    {
        setString(name, &this->name);
        setString(company, &this->company);
        setString(phone, &this->phone);
        this->position = position;
    }
    ~NameCard()
    {
        delete name;
        delete company;
        delete phone;
    }
    void ShowNameCardInfo(void)
    {
        cout << "===================" << endl;
        cout << "Name : " << name << endl;
        cout << "Comp : " << company << endl;
        cout << "Phon : " << phone << endl;
        char str[10];
        switch (position)
        {
        case COMP_POS::CLERK:
            sprintf(str, "CLERK");
            break;
        case COMP_POS::SENIOR:
            sprintf(str, "SENIOR");
            break;
        case COMP_POS::ASSIST:
            sprintf(str, "ASSIST");
            break;
        case COMP_POS::MANAGER:
            sprintf(str, "MANAGER");
            break;
        default:
            sprintf(str, "OWNER");
            break;
        }
        cout << "Posi : " << str << endl;
    }

  private:
    /**********
     * by07.so NOTE 인수로 전달받은 포인터 변수에 메모리를 할당하려면, 
     * 아래와 같이 2차원 포인터로 전달받아야 한다.
    *******************/
    void setString(const char *src, char **tar)
    {
        int len = strlen(src) + 1;
        *tar = new char[len];
        strcpy(*tar, src);
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-123-1432", COMP_POS::CLERK);
    NameCard manSenior("Kim", "OrangeEng", "010-5932-5918", COMP_POS::SENIOR);
    NameCard manAssist("Hong", "SoGoodEng", "010-7777-9900", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}