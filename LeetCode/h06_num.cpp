/******************************************************************************
 * h06_num.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-02-08 Create
 * Description: 数字相关的编程
******************************************************************************/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;

int main()
{
/*
    long num;
    while(cin >> num)
    {
        while(num != 1)
        {
            for(int i = 2; i <= num; i++)
            {
                if(num % i == 0)
                {
                    cout << i << ' '; // 打印质数因子
                    num /= i;
                    break;
                }
            }
        }
    }
*/
/*
    bitset<32> bin = 9; // 二进制个数
    cout << "bits: " << bin.count() << endl;
*/
    vector<int> v{3, 4, 5, 5, 3, 12, 12, 10, 1};
    sort(v.begin(), v.end()); // 先排序
    auto it = unique(v.begin(), v.end()); // unique 相邻元素去重, 内部是把后面不重复的元素移到前面
    for(auto a : v)
        cout << a << " ";
    cout << endl;
    // unique 返回迭代器指向去重后容器中不重复序列最后一个元素的下一个元素
    v.erase(it, v.end());
    for(auto a : v)
        cout << a << " ";
    cout << endl;

    return 0;
}
