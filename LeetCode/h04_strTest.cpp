/******************************************************************************
 * h04_strTest.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-02-06 Create
 * Description: 字符串相关
******************************************************************************/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int a[128] = {0};
    string str;
    getline(cin, str);
    for(int i=0;i<str.size();i++)
        a[str[i]] = 1;

    int total = 0;
    for(int i=0;i<128;i++)
        total += a[i];
    cout << total << endl; // 字符个数统计

    return 0;
}
