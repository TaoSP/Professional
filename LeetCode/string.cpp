// 字符串相关的编程记录
// 2020.02.05

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        stringstream ss(str);
        int num;
        ss >> hex >> num; // 16进制转10进制
        cout << num << endl;
    }

    return 0;
}
