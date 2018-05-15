#ifndef __DATA_H__
#define __DATA_H__
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

template <typename T>
class Data
{
  public:
    static Data *getInstance()
    {
        static Data _instance;
        return &_instance;
    }

  public:
    int addData(const T &item);
//    int delData(const T &item);
    template <typename K>
    int getData(K key, T &t)
    {
        typename list<T>::iterator lDataIt;
        if ((lDataIt = find(lData.begin(), lData.end(), key)) != lData.end())
        {
            t = *lDataIt;
            return 0;
        }
        else
        {
            return 1;
        }
    }

  private:
    list<T> lData;
    Data() {};
    Data(Data const&);
    void operator=(Data const&);

};

template <typename T>
int Data<T>::addData(const T &item)
{
    lData.push_back(item);
    return 0;
}

#endif /* __DATA_H__ */