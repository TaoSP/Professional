/******************************************************************************
 * h04_strTest.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-02-06 Create
 * Description: 字符串相关
******************************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
using namespace std;

// 字符串分割函数, str为待分割的字符串, pattern为任意分割符
vector<string> split(string str, string & pattern)
{
    vector<string> v;
    if(pattern.empty()) return v;

    int start = 0;
    int index = str.find(pattern, start); // find_first_of
    while(index != string::npos)
    {
        if(index != start)
            v.push_back(str.substr(start, index - start));

        start = index + 1;
        index = str.find_first_of(pattern, start);
    }
    if(!str.substr(start).empty())
        v.push_back(str.substr(start));

    return v;
}

bool isBigger(const pair<char, int> & p1, const pair<char, int> & p2)
{
    return p1.second > p2.second;
}

int main()
{
/*
    string str;
    while(cin >> str)
    {
        stringstream ss(str);
        int num;
        ss >> hex >> num; // 16进制转10进制
        cout << num << endl;
    }
*/
/*
    int a[128] = {0};
    string str;
    getline(cin, str);
    for(int i=0;i<str.size();i++)
        a[str[i]] = 1;

    int total = 0;
    for(int i=0;i<128;i++)
        total += a[i];
    cout << total << endl; // 字符个数统计
*/
/*
    string pattern(" ");
    string in;
    getline(cin, in);
    vector<string> v = split(in, pattern); // // 字符串分割
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << " " << endl;
*/
/*
    vector<string> v;
    string in;
    int n;
    cin >> n;
    while(n-- && cin >> in)
        v.push_back(in);
    
    sort(v.begin(), v.end()); // 字符串按照字典序排列
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << endl;
*/
/*
    // 密码验证
    // 长度超过8位, 包括大小写字母.数字.其它符号,以上四种至少三种
    // 不能有相同长度超2的子串重复
    string str;
    while(cin >> str)
    {
        bitset<8> bits = 0;
        bool error = false;
        for(auto c : str)
        {
            if(c >= '0' && c <= '9')
                bits |= 0x1;
            else if(c >= 'A' && c <= 'Z')
                bits |= 0x2;
            else if(c >= 'a' && c <= 'z')
                bits |= 0x4;
            else
                bits |= 0x8;
        }
        if(str.size() <= 8 || bits.count() < 3)
            error = true;
        if(!error)
            for(int i = 0; i <= str.size() - 6; i++) // 寻找重复子串
                for(int j = i+3; j < str.size(); j++)
                    if(str[i] == str[j] && str[i+1] == str[j+1]
                        && str[i+2] == str[j+2])
                        error = true;
        if(error)
            cout << "NG" << endl;
        else
            cout << "OK" << endl;
    }
*/
    // 字符统计：如果个数相同，则按照ASII码由小到大排序输出
    string str;
    while(getline(cin, str))
    {
        map<char, int> mp;
        for(auto a : str)
            if((a>='0' && a<='9') || (a>='a' && a<='z') || a == ' ' || (a>='A' && a<='Z'))
                mp[a]++;
        vector<pair<char, int>> v(mp.begin(), mp.end()); // 一对值
        stable_sort(v.begin(), v.end(), isBigger); // 稳定排序
        for(auto a : v)
            cout << a.first;
        cout << endl;
    }

    return 0;
}
