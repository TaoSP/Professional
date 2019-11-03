// 2019.11.03
// 内存模型，名称空间，new
//
// 存储持续性、作用域和链接性
// 静态持续变量：外部链接性(extern)、内部链接性(static)、无链接性(局部变量static)
// bss段，data段，text段，heap和stack
//      bss segment 存放程序中未初始化的全局变量，Block Started by Symbol，属于静态内存分配
//      data segment 已初始化的全局变量，属于静态内存分配
//      code segment/text segment 存放程序执行代码，通常属于只读，也包含常量例如字符串常量
//      text和data段都在可执行文件中，而bss段不在可执行文件中（一个占位符）由系统初始化
// auto register static extern thread_loacl mutable const volatile(避免编译器优化读取变量值)
// const全局变量的链接性为内部，通常可将常量放到头文件中，这样每个包含该头文件的源文件都有自己的常量
// 语言链接性，C++翻译，比如 max(int,int) -> _max_i_i, 可以使用 extern "C" void max(int,int)
// 程序结束时new分配的内存通常会被释放，但有些情况下请求大型内存不会，故最佳做法配套使用delete
// 定位 new 运算符，delete不能用于静态内存指针
// namespace, 作用域解释符::
// using声明 与 using编译指令（导入后局部名称将隐藏名称空间名），使用using声明更安全
// C++11 空指针关键字 nullptr
// new delete 必须互相兼容，多个构造函数中，new要么带[]，要么都不带，因为只有一个析构
// new创建对象时：String *p  = new String("xxx")
//      为对象分配内存 -> 调用构造函数 -> 创建 p 变量 -> 将新对象地址赋值给 p
// 

/******************************************************************************
 * C++PrimerPlus_memoryModel.cpp
 *
 * Copyright (C) xxx CO.,LTD.
 * Author : Huangtao
 * Version: V1.0.0  2019-11-03 Create
 * Description: 
 * 
******************************************************************************/
#include <iostream>
using namespace std;

char buffer[512];

namespace HT
{
    void hello()
    {
        std::cout << "hello\n";
    }
} // namespace HT

namespace // 未命名的名称空间，提供了链接性为内部的静态变量替代品
{
    int a = 100;
}

int main()
{
    int *pi = new int (6); // new 运算符初始化
    int *pi2 = new int {7};
    int *ar = new int [4] {1, 2, 3, 4};
    int *p3 = new (buffer) int[20] {9,8,7}; // 定位 new 运算符
    cout << *pi << *pi2 << *(ar+3) << *p3 << endl;

    HT::hello();
    using HT::hello; // using声明
    hello();
    using namespace HT; // using编译指令
    cout << a << endl;

    return 0;
}

