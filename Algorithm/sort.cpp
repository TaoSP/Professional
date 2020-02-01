/******************************************************************************
 * sort.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-02-01 Create
 * Description: 常见排序算法，以整形为例
******************************************************************************/
#include <iostream>
#include <vector>
//#include <array>
using namespace std;

class MySort
{
private:
    /* data */
public:
    MySort(/* args */);
    ~MySort();
    void insertionSort(vector<int> & v);
};

MySort::MySort(/* args */)
{
}

MySort::~MySort()
{
}

void MySort::insertionSort(vector<int> & v)
{
    std::size_t j;
    int tmp;
    for(std::size_t i = 1; i < v.size(); i++)
    {
        tmp = v.at(i);
        for(j = i; j > 0 && tmp < v.at(j-1); j--)
            v[j] = v[j-1];
        v[j] = tmp;
    }
}

int main()
{
    int arr[64] = {3,12,4,0,66,999,7,8,5,23,48,555555,2020,2019,43,404,31,30};
    vector<int> num;
    for(int i = 0; i < 18; i++)
        num.push_back(arr[i]);

    MySort mySort;
    mySort.insertionSort(num);

    for(vector<int>::iterator it = num.begin(); it != num.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}
