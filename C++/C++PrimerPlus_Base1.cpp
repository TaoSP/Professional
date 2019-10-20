// 2019.10.18
// 读书笔记：基础部分学习
//
// 尽可能在首次使用变量前声明它
// cout 是一个 ostream 类对象，<< 运算符重载
// 使用库函数注意外部链接，如 -lm，编译器倾向于给函数名添加下划线前缀
// short 至少16位，long 至少32位且至少与 int 一样长
// char 'A'表示法优于0x65，更清晰且不需要知道编码方式，前缀加 L 指示宽字符常量
// C++11 使用 {} 初始化称为列表初始化
// 强制类型转换，C++推荐 typename (value)
// C++11 auto 关键字自动推断类型，如在 STL 中，auto pv = vector1.begin()
// 数组称为复合类型，只有定义时才能使用初始化（可省略=），如对一部分初始化，则编译器将其他设置为0
// 任何由空白（空格，制表符，换行）分隔的字符串常量都将自动拼接成一个
// 对数组名取地址，得到的是整个数组的地址
// 数组的替代品 模板类：vector（动态） array（定长,栈）
// 在 for 和括号中加空格 vs 函数
// 副作用，顺序点，逗号运算符 和 || 是一个顺序点
// C++11 基于范围的 for 循环
// 函数原型不要求提供变量名，变量名相当于占位符，也不必与函数定义中相同，不指定参数列表可使用省略号...
// 当且仅当函数头和原型中，int * arr 和 int arr[] 含义才相同
// const 和指针
// const 只能用于指向基本类型指针，不能用于指针的指针
// 引用 可解决 复制传参效率低 和 指针表示法复杂 两方面的问题
// 函数和二维数组，函数指针
// inline 函数不能递归
// 引用 更接近 const指针，必须创建时初始化；在函数调用中，使用实参初始化形参
// 1.实参与引用形参不匹配，2.实参类型正确但不是左值；则编译器将为引用参数生成临时变量
//     因此引用参数尽可能使用const，可以避免无意修改数据，使函数正确处理const和非const实参，
//     使用const引用使函数能够正确生成并使用临时变量
// 返回引用，避免返回指向临时变量的引用：1.返回一个作为参数传递给函数的引用，2.new分配空间
//     将const用于引用返回类型 const xx & fun(x), 可避免赋值操作 fun(x) = y


/******************************************************************************
 * C++PrimerPlus_Base1.cpp
 *
 * Copyright (C) xxx CO.,LTD.
 * Author : Huangtao
 * Version: V1.0.0  2018-10-20 Create
 * Description: 数组，指针，函数，引用
 * 
******************************************************************************/
#include <iostream>
using namespace std;

int sumArray(int [], int);
int sumArray(int * arr, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    
    return total;
}

int sum(int (*ar2)[4], int size);
int sum(int ar2[][4], int size);

int refCube(int &a)
{
    return a *= a * a; // a 可能被误修改
}
int refCubeOk(const int &a)
{
    return a * a * a;
}

typedef struct
{
    int price;
}Car;
// 返回不可修改的左值，避免 addCar(...) = y
const Car & addCar(Car & target, const Car & soucre)
{
    target.price += soucre.price;
    return target; // 返回一个作为参数传递给函数的引用
}

int main()
{
    //cout << "Hello World !" << endl;

    short array1[10];
    cout << array1 << endl;         // 0x61fe00
    cout << &array1 << endl;        // 0x61fe00
    cout << &array1[0] + 1 << endl; // 0x61fe02
    cout << &array1 + 1 << endl;    // 0x61fe14

    int age[4] {12, 22, 33, 40};
    for (int x : age)
        cout << x << " ";
    cout << endl;
    
    cout << sumArray(age, 4) << endl;

    int year = 2019;
    const int * pt = &year; // *pt 不能被修改
    int * const pp = &year; // pp  不能被修改

    //int *pf()             // 返回指针的函数
    int (*pf)(int [], int); // 函数指针
    pf = sumArray;
    cout << pf(age, 4) << endl; // 2种都正确
    cout << (*pf)(age, 4) << endl;

    int a = 3;
    cout << refCube(a) << endl;
    cout << a <<endl; // 27

    return 0;
}







