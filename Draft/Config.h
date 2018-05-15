#ifndef __DATA_H__
#define __DATA_H__
#include <algorithm>
#include <iostream>
#include <list>

/*********************
 * by07.so NOTE 이 파일과는 상관없지만, ISM 구현에 필요한 내용임.
 *  define 으로 상수를 정의하는 대신 define 용 클래스에 const static 으로 선언한 게 있는데,
 *  이는 non-local static object 이므로 초기화 순서를 보장할 수 없다.(별개의 파일로 분리돼 있으므로)
 *  즉, 아직 초기화되지 않은 상태에서 이를 사용하게 될 수도 있으므로 변경할 필요가 있다.
 *  함수를 통해(local static object) 반환받도록 변경해야 한다.
 *********************/

using namespace std;

template <typename CONFTYPE>
class Config
{
  public:
    static Config &getInstance()
    {
        static Config _instance;
        return _instance;
    }

  public:
    bool isDupConfig(const CONFTYPE &) const;
    void addConfig(const CONFTYPE &) throw(exception);
    void delConfig(const CONFTYPE &) throw(exception);
    int getList(list<CONFTYPE> &) const;
    template <typename KEYTYPE>
    int getConfig(const KEYTYPE, CONFTYPE &);

  private:
    list<CONFTYPE> lConfig;

    // https://blog.naver.com/nawoo/220185652173
    Config() {};
    Config(Config const&);
    void operator=(Config const&);
};

template <typename CONFTYPE>
bool Config<CONFTYPE>::isDupConfig(const CONFTYPE &item) const
{
    if (find(lConfig.begin(), lConfig.end(), item) != lConfig.end())
        return true;
    else
        return false;
}

template <typename CONFTYPE>
void Config<CONFTYPE>::addConfig(const CONFTYPE &item) throw(exception)
{
    try
    {
        if(true == isDupConfig(item))
            throw "Duplicated Config!!";

        lConfig.push_back(item);
        //    lConfig.sort();  // 'operator>' is required.
    }
    catch (exception &ex)
    {
        cout << ex.what() << endl;
        //runtime_error(ex.what());
    }
    catch(char const *str)
    {
        cout << str << endl;
    }
}

template <typename CONFTYPE>
void Config<CONFTYPE>::delConfig(const CONFTYPE &item) throw(exception)
{
    try
    {
        if(true == isDupConfig(item))
        {
            lConfig.remove(item);
        }
    }
    catch (exception &ex)
    {
        cout << ex.what() << endl;
        //runtime_error(ex.what());
    }
}

template <typename CONFTYPE>
int Config<CONFTYPE>::getList(list<CONFTYPE> &l) const
{
    l = lConfig;
    return lConfig.size();
}

template <typename CONFTYPE>
template <typename KEYTYPE>
int Config<CONFTYPE>::getConfig(const KEYTYPE key, CONFTYPE &t)
{
    typename list<CONFTYPE>::iterator lConfigIt;
    if ((lConfigIt = find(lConfig.begin(), lConfig.end(), key)) != lConfig.end())
    {
        t = *lConfigIt;
        return 0;
    }
    else
    {
        return 1;
    }
}
#endif /* __DATA_H__ */