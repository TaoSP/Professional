// 2019.11.03
// 第10,11章 OOP, 使用类
//
// 类的所有对象共享同一个静态成员，如果静态成员是整形或枚举型const，则可以在类声明中初始化
// 
// 何时会调用复制构造函数，深度复制，检查自我赋值情况
// 成员初始化列表，MyClass::Myclass(int n,int m) :mem1(n), mem2(0), mem3(n*m)
//      只能用于构造函数，必须用于：非静态const数据成员、引用数据成员
//      使用成员初始化列表的构造函数将覆盖相应的类内初始化
// 

/******************************************************************************
 * C++PrimerPlus_class.cpp
 *
 * Copyright (C) xxx CO.,LTD.
 * Author : Huangtao
 * Version: V1.0.0  2019-11-03 Create
 * Description: 
 * 
******************************************************************************/
#include <iostream>
using namespace std;


int main()
{

    return 0;
}





