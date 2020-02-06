// 数字相关的编程

#include <iostream>
#include <sstream>
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
    bitset<32> bin = 9; // 二进制个数
    cout << "bits: " << bin.count() << endl;

    return 0;
}
