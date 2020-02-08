/******************************************************************************
 * h05_keyValue.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-02-06 Create
 * Description: set, map 使用
******************************************************************************/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
/*
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
*/
    // 计票统计：
    // 输入候选人的人数，第二行输入候选人的名字，第三行输入投票人的人数，第四行输入投票
    int n;
    while(cin >> n)
    {
        vector<string> v;
        map<string, int> m;
        while(n--)
        {
            string s;
            cin >> s;
            v.push_back(s);
            m[s] = 0;
        }
        cin >> n;
        int errNum = 0;
        while(n--)
        {
            string s;
            cin >> s;
            if(m.find(s) == m.end())
                errNum++;
            else
                m[s]++;
        }
        for(auto a : v)
            cout << a << " : " << m[a] << endl;
        cout << "Invalid : " << errNum << endl;
    }

    return 0;
}
