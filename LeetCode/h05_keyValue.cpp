/******************************************************************************
 * h05_keyValue.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-02-06 Create
 * Description: set, map 使用
******************************************************************************/
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> mp;
    int n, key, value;
    cin >> n;
    // 合并表记录，并按key值升序进行输出
    while(n-- && cin >> key >> value)
    {
        mp[key] += value;
    }
    for(auto it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second << endl;

    return 0;
}
