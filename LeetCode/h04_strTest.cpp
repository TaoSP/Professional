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

int main()
{
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
    vector<string> v;
    string in;
    int n;
    cin >> n;
    while(n-- && cin >> in)
        v.push_back(in);
    
    sort(v.begin(), v.end()); // 字符串按照字典序排列
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << endl;

    return 0;
}
