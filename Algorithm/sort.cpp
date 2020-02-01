/******************************************************************************
 * sort.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-02-01 Create
 * Description: 常见排序算法，以整形为例
******************************************************************************/
#include <iostream>
#include <algorithm>
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
    void bubbleSort(vector<int> & v);
    void selectSort(vector<int> & v);
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
    for(std::size_t i = 1; i < v.size(); i++) // N-1 趟, 保证 0~j 为已排序状态
    {
        tmp = v.at(i);
        for(j = i; j > 0 && tmp < v.at(j-1); j--)
            v[j] = v[j-1];
        v[j] = tmp;
    }
}

void MySort::bubbleSort(vector<int> & v)
{
    std::size_t i, j;
    int tmp;
    bool change = true;
    for(i = 0; i < v.size() - 1 && change; i++) // 最多 N-1 趟排序
    {
        change = false;
        for(j = 0; j < v.size() - i - 1; j++) // 每趟都会得到较大值靠后放
        {
            if(v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
                change = true;
            }
        }
    }
}

void MySort::selectSort(vector<int> & v)
{
    std::size_t i, j, min;
    for(i = 0; i < v.size() - 1; i++) // 每趟在 N-i 个记录中找最小值作为第i个记录
    {
        min = i;
        for(j = i + 1; j < v.size(); j++)
            if(v[j] < v[min])
                min = j;
        
        if(min != i)
            swap(v[i], v[min]);
    }
}

int main()
{
    int arr[64] = {3,12,4,0,66,999,7,8,5,23,48,555555,2020,2019,43,404,31,30};
    vector<int> num;
    for(int i = 0; i < 18; i++)
        num.push_back(arr[i]);

    MySort mySort;
    //mySort.insertionSort(num);
    //mySort.bubbleSort(num);
    mySort.selectSort(num);

    for(vector<int>::iterator it = num.begin(); it != num.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}
