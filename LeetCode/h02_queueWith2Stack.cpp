/******************************************************************************
 * xxx.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-02-02 Create
 * Description: 用2个栈实现队列
******************************************************************************/
#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> s1;
    stack<int> s2;
    void flush(void) // 关键
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int t = s1.top(); s1.pop();
                s2.push(t);
            }
        }
    }
public:
    void push(int n)
    {
        s1.push(n);
    }

    int front(void)
    {
        flush();
        if(s2.empty())
            throw new exception();

        return s2.top();
    }

    void pop(void)
    {
        flush();
        if(!s2.empty()) s2.pop();
    }

    int empty(void)
    {
        flush();
        return s2.empty();
    }
};

int main()
{
    MyQueue q;
    q.push(2020);
    q.push(2021);
    cout << q.front() << endl;
    q.pop();
    q.push(3);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.empty() << endl;
    //q.front();

    return 0;
}
