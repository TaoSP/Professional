/******************************************************************************
 * search.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-02-03 Create
 * Description: 查找
******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
//#include <stack>
//#include <queue>
using namespace std;

class MySearch
{
private:

public:
    MySearch(/* args */);
    ~MySearch();
    int binarySearch(vector<int> & v, int key);     // 折半查找（有序表）
    int binaryTreeSearch(vector<int> & v, int key); // 见数据结构 binaryTree.cpp

};

MySearch::MySearch(/* args */)
{
}

MySearch::~MySearch()
{
}

int MySearch::binarySearch(vector<int> & v, int key)
{
    int low = 0;
    int high = v.size() - 1; // [0, size-1]
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if(v.at(mid) == key)
            return mid;
        else if(v.at(mid) > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> vSequence;
    //vector<int> vDisorder;
    for(int i = 0; i < 20; i++)
        vSequence.push_back(i+2020);

    MySearch search1;
    int key = 2031;
    int ret = search1.binarySearch(vSequence, key);
    if(ret >= 0)
        cout << vSequence.at(ret) << endl;

    return 0;
}
