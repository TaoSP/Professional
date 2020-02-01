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
#include <stack>
using namespace std;

class MySort
{
private:
    /* data */
    int getPartition(vector<int> & v, int l, int r);
    void quickSort(vector<int> & v, int l, int r);
public:
    MySort(/* args */);
    ~MySort();
    void insertionSort(vector<int> & v);        // 插入排序
    void bubbleSort(vector<int> & v);           // 冒泡
    void selectSort(vector<int> & v);           // 选择
    void quickSort(vector<int> & v);            // 快排，对冒泡排序的一种改进，分治法
    void quickSortNonRecursive(vector<int> & v); // 快排，非递归
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

int MySort::getPartition(vector<int> & v, int l, int r)
{
    int key = v.at(l); // 选一个枢轴点，同时暂存第一个值
    while(l < r)
    {
        // 顺序不能反，先找小于key的，
        while(l < r && v[r] >= key) r--;
        if(l < r)
            v[l++] = v[r];
        
        while (l < r && v[l] <= key) l++;
        if(l < r)
            v[r--] = v[l];

    }
    v[l] = key; // l=r, 一趟后，经过互相交换，比枢轴点小的在左，比它大的在右边
    return l;
}

void MySort::quickSort(vector<int> & v, int l, int r)
{
    if(l >= r) return;

    int mid = this->getPartition(v, l, r);
    quickSort(v, l, mid - 1);
    quickSort(v, mid + 1, r);
}

void MySort::quickSort(vector<int> & v)
{
    this->quickSort(v, 0, v.size() - 1);
}

void MySort::quickSortNonRecursive(vector<int> & v)
{
    if(v.empty()) return;

    stack<int> st;
    int size = v.size(); // 防止 int < size_t(1-2)
    int mid = this->getPartition(v, 0, size - 1);
    if(mid > 1)
    {
        st.push(0);
        st.push(mid - 1);
    }
    if(mid < size - 2)
    {
        st.push(mid + 1);
        st.push(size - 1);
    }

    int l, r;
    while(!st.empty())
    {
        r = st.top(); st.pop();
        l = st.top(); st.pop();
        mid = this->getPartition(v, l, r);
        if(l < mid - 1)
        {
            st.push(l);
            st.push(mid - 1);
        }
        if(r > mid + 1)
        {
            st.push(mid + 1);
            st.push(r);
        }
    }
}

int main()
{
    int arr[64] = {3,12,4,0,66,999,7,8,5,23,48,555555,2020,2019,43,404,31,30};
    vector<int> num;
    //num.push_back(0);
    for(int i = 0; i < 18; i++)
        num.push_back(arr[i]);

    MySort mySort;
    //mySort.insertionSort(num);
    //mySort.bubbleSort(num);
    //mySort.selectSort(num);
    //mySort.quickSort(num);
    mySort.quickSortNonRecursive(num);

    for(vector<int>::iterator it = num.begin(); it != num.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}
