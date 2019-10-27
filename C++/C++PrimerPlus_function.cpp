// 2019.10.18
// 读书笔记：第8章 函数重载，函数模板
//
// 必须通过函数原型设置默认参数，从右向左添加默认值
// 函数重载：函数特征标（参数列表），类型引用和类型本身视为同一个特征标
// C++11新特征右值引用（类型 &&引用名 = 表达式），左值引用右边必须是变量，右值引用右边必须是常量或者表达式
// 重载引用参数，调用最匹配的版本
// 当函数执行相同的任务，使用不同形式的数据时，才采用函数重载
// 函数模板（代码可重用性）：template <typename AnyType>，不创建函数，仅告诉编译器如何定义函数
// 具体化优于常规模板，而非模板函数优于具体化和常规模板
// 1.显式具体化： template <> void Swap<int>(int &, int &) 或 template <> void Swap(int &, int &)
//      为某一特定类型重写函数模板，处理模板函数所不能处理的特殊情况，它也是基于函数模板的
// 2.显式实例化（不是显示）： template void Swap<int>(int &, int &)
//      如果不使用显式实例化，每次调用函数时，模板都会消耗性能去推导使用哪个类型的函数，
//      可以用在函数调用时直接显式实例化
// C++11 decltype 查询表达式类型


/******************************************************************************
 * C++PrimerPlus_function.cpp
 *
 * Copyright (C) xxx CO.,LTD.
 * Author : Huangtao
 * Version: V1.0.0  2018-10-20 Create
 * Description: 函数重载，模板
 * 
******************************************************************************/
#include <iostream>
using namespace std;

template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <> void Swap(int &a, int &b) // 显式具体化
{
    int t = a;
    a = b;
    b = t;
    cout << "swap for int" << endl;
}

int main()
{
    double a = 22.0;
    double b = 99.88;
    Swap(a, b);
    cout << a << ' ' << b << endl;

    int n1 = 10;
    int n2 = 30;
    Swap(n1, n2);

    char c1 = 'a';
    decltype(c1) c2 = 'b';
    Swap<char>(c1, c2); // 显式实例化
    cout << c1 << ' ' << c2 << endl;

    return 0;
}







