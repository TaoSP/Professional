/******************************************************************************
 * xxx.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-01-29 Create
 * Description: 用%20替换字符串URL中空格
******************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;
#define MAX_LEN    128

int main()
{
    //char str[MAX_LEN] = "hello world, toady: 2020 01 29";
    char *s = (char *)"hello world, toady: 2020 01 29";
    char str[MAX_LEN];
    memset(str, 'a', MAX_LEN);
    memcpy(str, s, strlen(s));
    str[strlen(s)] = '\0';
    cout << str << endl;

    int len = strlen(str) + 1; // +1
    int spaceNum = 0;
    for(int i = 0; i < len; i++)
    {
        if(' ' == str[i])
            spaceNum++;
    }

    int newLen = len + spaceNum*2;
    if(newLen >= MAX_LEN)
        return false;

    char *p1 = str + len;
    char *p2 = str + newLen; // 从后向前替换, T(n) = O(n)
    while(p1 >= str)
    {
        if(' ' == *p1)
        {
            *p2 = '0'; --p2;
            *p2 = '2'; --p2;
            *p2 = '%'; --p2;
        }
        else
        {
            *p2 = *p1; --p2;
        }

        --p1;
    }

    cout << str << endl;
    return 0;
}
