/******************************************************************************
 * stack_calculator.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-01-23 Create
 * Description: 简单实现正数的加减乘除，转化为后缀表达式
******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Stack
{
private:
    int *m_data;
    int m_size;
    int m_maxSize;
public:
    Stack(int size);
    ~Stack();
    int size(void);
    int empty(void);
    int push(int data);
    int pop(void);
    int top(void);
};

Stack::Stack(int size) :m_size(0), m_maxSize(size)
{
    m_data = new int[m_maxSize];
}

Stack::~Stack()
{
    delete m_data;
}

int Stack::size(void)
{
    //cout << "size: " << m_size << endl;
    return m_size;
}

int Stack::empty(void)
{
    if(m_size <= 0)
        return true;
    else
        return false;
}

int Stack::push(int data)
{
    if((m_size + 1)  >= m_maxSize)
    {
        cout << "size error" << endl;
        return false;
    }

    *(m_data + m_size++) = data;
    return true;
}

int Stack::pop(void)
{
    if(empty())
    {
        cout << "no data" << endl;
        return false;
    }

    return *(m_data + --m_size);
}

int Stack::top(void)
{
    if(empty())
    {
        cout << "no data" << endl;
        return false;
    }

    return *(m_data + (m_size - 1));
}

int priority(char c)
{
    if('=' == c)
        return 1;
    else if('+' == c || '-' == c)
        return 2;
    else if('*' == c || '/' == c)
        return 3;
    else
    {
        cout << "not support" << endl;
        return 0;
    }
}

int calculator(Stack & numStack, Stack & opeStack)
{
    int tmp;
    switch (opeStack.pop())
    {
        case '*':
        {
            numStack.push(numStack.pop() * numStack.pop());
            break;
        }
        case '/':
        {
            tmp = numStack.pop();
            numStack.push(numStack.pop() / tmp);
            break;
        }
        case '+':
        {
            numStack.push(numStack.pop() + numStack.pop());
            break;
        }
        case '-':
        {
            tmp = numStack.pop();
            numStack.push(numStack.pop() - tmp);
            break;
        }
        default:
            break;
    }

    return true;
}

int main()
{
    Stack numStack(128);
    Stack opeStack(32);
    string input;

    cin >> input; // 2-3*3+2+4/4=
    char c;
    int num, flag = 0;
    for(size_t i = 0; i < input.size(); i++)
    {
        c = input.at(i);
        if(c >= '0' && c <= '9')
        {
            num = num * 10 + c - '0';
            flag = 1;
        }
        else
        {
            if(flag)
            {
                numStack.push(num);
                flag = 0;
                num = 0;
            }

            if(opeStack.empty() || priority(c) > priority(opeStack.top()))
            {
                opeStack.push(c);
                continue;
            }
            else
            {
                while(!opeStack.empty()) // 把栈中已存的计算完
                {
                    calculator(numStack, opeStack);
                }

                opeStack.push(c);
            }
        }
    }

    cout << "numStack size: " << numStack.size() << endl;
    cout << "opeStack size: " << opeStack.size() << endl;
    cout << "calc: " << numStack.top() << endl;

    return 0;
}
