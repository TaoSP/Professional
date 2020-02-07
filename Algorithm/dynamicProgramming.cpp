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
#include <string>
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
// Longest increasing sequence, LIS问题
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

// 递增/递减子序列
int demoLIS(vector<int> & v)
{
    int n = v.size();
    //vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> dp(n, 1);
    vector<int> dp2(n, 1);
    for(int i = 1; i < n; i++)
        for(int j = i - 1; j >= 0; j--)
            if(v[i] > v[j] && dp[i] < dp[j]+1) // 递增
                dp[i] = dp[j] + 1;
    // 不能同时计算，递减从右边开始算起
    for(int i = n - 2; i >= 0; i--)
        for(int j = n - 1; j > i; j--)
            if(v[i] > v[j] && dp2[i] < dp2[j]+1) // 递减
                dp2[i] = dp2[j] + 1;
    for(auto a : dp)
        cout << a << " ";
    cout << endl;
    for(auto a : dp2)
        cout << a << " ";
    cout << endl;
    return true;
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

// 背包问题, 总容量W, 物品体积和价值wi,vi
// 总价值: f(n, W) = max{f(n-1, W), vn + f(n-1, W-wn)}
// dp[i][j] = max{dp[i-1][j], dp[i-1][j-wi]+vi}
int packageHelper()
{
    int w[] = {2, 2, 6, 5, 4};
    int v[] = {6, 3, 5, 4, 6};
    int n = 5;
    int weight = 10;
    vector<vector<int>> dp(n+1, vector<int>(weight+1, 0)); // vector创建二维数组
    // v.resize(n, vector<int>(m)); // 一次指定内外层大小
    for(int i = 1; i < n+1; i++)
        for(int j = 1; j < weight+1; j++)
        {
            if(j > w[i-1]) // i从1开始
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]]+v[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }
    cout << "package: " << dp[n][weight] << endl;
    // 使用一维滚动数组
    //vector<int> ap(weight+1);
    vector<int> ap(weight+1, 0);
    for(int i = 1; i < n+1; i++)
        // 滚动方向要注意，保证ap[j-w]用的是上个状态值，否则容易被自己这轮覆盖掉
        for(int j = weight; j > 0; j--)
        {
            if(j > w[i-1])
                ap[j] = max(ap[j], ap[j-w[i-1]]+v[i-1]);
            else
                ap[j] = ap[j];
        }
    cout << "package: " << ap[weight] << endl;
    return true;
}

// 找零钱问题：有几种组合方式
int money()
{
    vector<int> coins{1, 2, 5, 10, 20, 50, 100};
    int n = coins.size();
    int value = 10;
    vector<vector<int>> dp(n+1, vector<int>(value+1, 0));

    for(int i = 1; i <= value; i++)
        if(i % coins[0] == 0)
            dp[0][i] = 1; // 只用第一种货币对i找钱
    //for(int i = 0; i < n; i++)
    //    dp[i][0] = 1;

    for(int i = 1; i < n; i++)
        for(int j = 1; j <= value; j++)
        {
            if(j < coins[i]) // 这里不是coins[i-1], 上面已经用第一种货币初始化过
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
        }
    cout << "money: " << dp[n-1][value] << endl;
    // 滚动数组解法
    vector<int> ap(value+1, 0);
    for(int i = 1; i <= value; i++)
        if(i % coins[0] == 0)
            ap[i] = 1;
    for(int i = 1; i < n; i++)
        for(int j = 1; j <= value; j++)
        {
            if(j >= coins[i])
                ap[j] = ap[j] + ap[j - coins[i]];
        }
    cout << "money: " << ap[value] << endl;
    return true;
}

// 找零钱问题：货币数最少
// 还存在问题，待解决
int moneyNum()
{
    vector<int> coins{1, 2, 5, 10, 20, 50, 100};
    int n = coins.size();
    int value = 90;
    vector<vector<int>> dp(n+1, vector<int>(value+1, 0));

    for(int i = 1; i <= value; i++)
        if(i % coins[0] == 0)
            dp[0][i] = i / coins[0]; // 数量

    for(int i = 1; i < n; i++)
        for(int j = 1; j <= value; j++)
        {
            if(j < coins[i])
                dp[i][j] = dp[i-1][j];
            else if(j == coins[i])
                dp[i][j] = 1;
            else
            {
                if(dp[i-1][j] && dp[i-1][j-coins[i]]) // 2种都存在取最小的
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-coins[i]] + 1);
                else
                    dp[i][j] = dp[i-1][j] ? dp[i-1][j] : dp[i][j-coins[i]] + 1;
            }
        }
    cout << "money num: " << dp[n-1][value] << endl;
    return true;
}

// 最长回文子串
int demoLPS(string str)
{
    int n = str.size();
    // dp[i][j] 表示以...i~j...是否为回文子串
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLen = 0, start;
    //dp[0][0] = true;
    for(int j = 1; j < n; j++)
        for(int i = 0; i <= j; i++)
        {
            if(j == i)
                dp[i][j] = true;
            else if(j - i == 1)
                dp[i][j] = (str[j] == str[i]);
            else
                dp[i][j] = (dp[i+1][j-1] && str[j] == str[i]);
            if(dp[i][j] && (j - i + 1) > maxLen)
            {
                maxLen = j - i + 1;
                start = i;
            }
        }
    cout << "LPS len: " << maxLen << endl;
    cout << str.substr(start, maxLen) << endl;
    return maxLen;
}

int main()
{
    //cout << fibonacci(20) << endl;

    //vector<int> v{1, -2, -3, 9, 0, 6, 7, 8, -1};
    //cout << maxArrayOrder(v) << endl;

    //demoLIS(v);

    //cout << maxArraySum(v) << endl;

    //maxTriangleArray();

    //packageHelper();

    //money();

    //moneyNum();

    demoLPS("abbacdf");

    return 0;
}
