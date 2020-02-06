/******************************************************************************
 * backTracking.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-02-06 Create
 * Description: 回溯法，通用解题法
 *  对解空间的深度优先搜索，使用递归，按照DFS，从根结点出发，当探索到某一结点时，
 *  先判断该结点是否包含问题的解，如果包含就从该结点继续探索下去，如果不包含则逐层回溯
 * 1. 八皇后问题
******************************************************************************/
#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <stack>
//#include <queue>
using namespace std;

#define MAX  8
int a[MAX]; // 存放结果，每个皇后所在的列
int count = 0;

bool check(int n)
{
    // 斜对角: |x1-x2| == |y1-y2|
    for(int i = 0; i < n; i++)
        if(a[i] == a[n] || abs(a[n]-a[i]) == n-i)
            return false;
    return true;
}

void tryBt(int n)
{
    if(n == MAX) // 终止条件
    {
        ++count;
        for(int i = 0; i < MAX; i++)
            cout << a[i] << ' ';
        cout << endl;
    }
    else
    {
        for(int i = 0; i < MAX; i++) // 枚举第n个节点所有可能路径
        {
            a[n] = i;
            if(check(n)) // 满足约束条件
                tryBt(n+1);
        }
    }
}

int main()
{
    tryBt(0);
    cout << count << endl;
    return 0;
}
