/******************************************************************************
 * dynamicProgramming.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-02-06 Create
 * Description: 动态规划
 *  {A1->A2}; {A1,A2->A3}; {A1,A2,...,Ai}->Ai+1, 对于Ai+1需要所有前序状态才能完成推理
 *  能用动规解决的问题的特点: 
 *  1. 最优化原理, 问题的最优解所包含的子问题的解也是最优的, 最优子结构
 *  2. 无后效性, 即某阶段状态一旦确定, 就不受这个状态以后决策的影响
 *  3. 有重叠子问题, 即子问题之间是不独立的
 *  动态规划处理的问题是一个多阶段决策问题，一般由初始状态开始，通过对中间阶段决策的选择，达到结束状态
 *  划分 -> 确定状态和状态变量 -> 确定决策并写出状态转移方 -> 寻找边界条件
 *  算法实现的步骤:
 *  1. 创建一个一维数组或者二维数组，保存每一个子问题的结果
 *  2. 设置数组边界值，一维数组就是设置第一个数字，二维数组就是设置第一行跟第一列的值
 *  3. 找出状态转换方程，也就是说找到每个状态跟它上一个状态的关系，根据状态转化方程写出代码
 *  4. 返回需要的值，一般是数组的最后一个或者二维数组的最右下角
******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
//#include <stack>
//#include <queue>
using namespace std;

// 用动态规划解斐波那契数列 1,1,2,..., f(n) = f(n-1) + f(n-2)
int fibonacci(int n)
{
    if(n <= 1) 
        return n;
    else
    {
        int *result = new int[n+1]; // 创建一维数组，保存每一个子问题结果
        result[0] = 0; result[1] = 1;
        for(int i = 2; i <= n; i++)
            result[i] = result[i-1] + result[i-2];
        return result[n];
    }
}

// 最长递增子序列，可不连续
int maxArrayOrder(vector<int> & v)
{
    if(v.empty())
        return 0;
    int n = v.size();
    int *result = new int[n];
    for(int i = 0; i < n; i++)
        result[i] = 1; // 初始值
    
    for(int i = 1; i < n; i++)
    {
        int cnt = result[i];
        for(int j = 0; j < i; j++)
        {
            if(v[i] > v[j])
                cnt = max(cnt, result[j] + 1);
        }
        result[i] = cnt;
    }
    int ret = result[0];
    for(int i = 1; i < n; i++)
        ret = max(ret, result[i]);

    return ret;
}

// 最大连续子序列和
int maxArraySum(vector<int> & v)
{
    if(v.empty())
        return 0;
    int n = v.size();
    int sum = v[0];
    int ret = sum;
    for(int i = 1; i < n; i++)
    {
        sum = max(sum + v[i], v[i]);
        ret = max(ret, sum);
    }
    return ret;
}

// 数字塔最大路径
int tData[5][5] = 
{   {3, 0, 0, 0, 0},
    {1, 5, 0, 0, 0},
    {8, 6, 3, 0, 0},
    {2, 5, 7, 9, 0},
    {6, 2, 3, 5, 1}
};
void maxTriangleArray()
{
/*
    // 从下往上更简单
    int n = 5;
    int result[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            result[i][j] = tData[i][j];

    for(int i = n - 2; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            result[i][j] += max(result[i+1][j], result[i+1][j+1]);
        }
    }
    cout << "max: " << result[0][0] << endl;
    // 打印路径
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            if(result[0][0] == result[i][j])
            {
                cout << tData[i][j] << " ";
                result[0][0] -= tData[i][j];
                continue;
            }
    cout << endl;
*/
    // 从上往下
    int n = 5;
    int result[n][n];
    int sum = result[0][0] = tData[0][0];
    for(int i = 1; i < n; i++)
        for(int j = 0; j <= i; j++)
        {
            if(j == 0) // 需考虑边界
                result[i][j] = result[i-1][j] + tData[i][j];
            else if(j == i)
                result[i][j] = result[i-1][j-1] + tData[i][j];
            else
                result[i][j] = max(result[i-1][j-1], result[i-1][j]) + tData[i][j];
        }
    for(int i = 0; i < n; i++)
        sum = max(sum, result[n-1][i]);
    cout << "max: " << sum << endl;

    // 优化：动态规划中每一个需要二维数组的解法，都可以换成一维数组的滚动数组解法
    // 创建跟二维数组最后一行一样大的一维数组，每次存放某一行的值
    int dp[n]; dp[0] = tData[0][0];
    for(int i = 1; i < n; i++)
    for(int j = i; j >= 0; j--) // 这里注意反过来
    {
        if(j == 0) // 需考虑边界
            dp[j] += tData[i][j];
        else if(j == i)
            dp[j] = dp[j-1] + tData[i][j];
        else
            dp[j] = max(dp[j-1], dp[j]) + tData[i][j];
    }
    sum = 0;
    for(int i = 0; i < n; i++)
        sum = max(sum, dp[i]);
    cout << "max: " << sum << endl;
}

int main()
{
    //cout << fibonacci(20) << endl;

    vector<int> v{1, -2, -3, 9, 0, 6, 7, 8, -1};
    //cout << maxArrayOrder(v) << endl;

    //cout << maxArraySum(v) << endl;

    maxTriangleArray();

    return 0;
}
