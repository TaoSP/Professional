/******************************************************************************
 * xxx.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-02-02 Create
 * Description: 用2个队列实现栈
******************************************************************************/
#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int n)
    {
        queue<int> & q = (!q1.empty() ? q1 : q2);
        q.push(n);
    }

    int top(void)
    {
        queue<int> & qYes = (!q1.empty() ? q1 : q2);
        queue<int> & qEmpty = (q1.empty() ? q1 : q2);
        int size = qYes.size();
        while(size-- > 1)
        {
            qEmpty.push(qYes.front());
            qYes.pop();
        }
        int num = qYes.front();
        qEmpty.push(qYes.front());
        qYes.pop();
        return num;
    }

    void pop(void)
    {
        queue<int> & qYes = (!q1.empty() ? q1 : q2);
        queue<int> & qEmpty = (q1.empty() ? q1 : q2);
        int size = qYes.size();
        while(size-- > 1)
        {
            qEmpty.push(qYes.front());
            qYes.pop();
        }
        qYes.pop();
    }

    int empty(void)
    {
        queue<int> & qYes = (!q1.empty() ? q1 : q2);
        return qYes.empty();
    }

    int size(void)
    {
        queue<int> & qYes = (!q1.empty() ? q1 : q2);
        return qYes.size();
    }
};

int main()
{
    MyStack s;
    cout << s.empty() << endl;
    s.push(2020);
    s.push(2021);
    cout << s.top() << endl;
    s.push(2022);
    s.push(2023);
    cout << s.top() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;

    return 0;
}
