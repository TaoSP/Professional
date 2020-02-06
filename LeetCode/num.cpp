// 数字相关的编程

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
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
    return 0;
}