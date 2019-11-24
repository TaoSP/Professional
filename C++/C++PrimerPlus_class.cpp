// 2019.11.03
// 第10,11章 OOP, 使用类，运算符重载
//
// 公共接口，将编写程序的人视为公共用户
// 内联方法：类声明中定义的函数都将自动成为内联函数
// 每个对象有自己的存储空间（内部变量、类成员），但共享同一组类方法
// 类的所有对象共享同一个静态成员，如果静态成员是整形或枚举型const，则可以在类声明中初始化
// 定义默认构造函数（2选1）：1.给构造函数参数提供默认值，2.函数重载一个没有参数的构造函数
// 成员初始化列表，MyClass::Myclass(int n,int m) :mem1(n), mem2(0), mem3(n*m)
//      此时还未执行括号中代码，只能用于构造函数，必须用于：非静态const数据成员、引用数据成员
//      使用成员初始化列表的构造函数将覆盖相应的类内初始化
// 只有类方法不修改调用对象，就应当将其声明为 const
// 创建对象前，没有用于存储值的空间，作用域为类的常量有2中方法：枚举、static
// this 指针指向用来调用成员函数的对象（它作为隐藏参数传递给方法）
// C++11新枚举 enum class xx, 作用域内枚举不能隐式转换为整形
// 运算符重载，sum() = operator+, 也可以像函数一样调用，X->operator+(xx)
// 何时会调用复制构造函数，深度复制和检查自我赋值情况（见继承）
//      将新对象初始化为一个同类对象
//      按值将对象传递给函数
//      函数按值返回对象
//      编译器生成临时对象
// 如果方法通过计算得到一个新的类对象，应考虑是否可以使用类构造函数来完成这种工作
// 只有接受一个参数的构造函数才能隐式转换，如 classA a = 2 // use classA(2) to convert
// 构造函数只用与从某种类型到类类型的转换，要进行相反的转换必须使用特殊的运算符——转换函数
// 转换函数: operator typeName(); 转换函数必须是类方法，不能指定返回类型，不能有参数
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

class Stock
{
private: // 默认访问控制
    string m_company = "company1"; // 使用 m_前缀
    double total_val = 0;
    enum {Months = 12};
    static const int year = 2019;
    void set_tot() // = inline void Stock::set_tot()
    {}
public:
    Stock();
    Stock(const string &co);
    void update(double total);
    void show() const; // const
    Stock operator+(const Stock & s) const;
    operator int() const;
};

Stock::Stock() :m_company("company2019 CO.,LTD"), total_val(998)
{
    std::cout << m_company << endl;
}

Stock::Stock(const string &co)
{
    m_company = co;
    std::cout << m_company << endl;
}

void Stock::update(double total)
{
    total_val = total;
}

void Stock::show() const
{
}

Stock Stock::operator+(const Stock & s) const
{
    Stock sum;
    sum.total_val = this->total_val + s.total_val;
    std::cout << "sum: " << sum.total_val << endl;
    return sum;
}

Stock::operator int() const
{
    return int (total_val + 0.5);
}

int main()
{
    Stock stock1("co1"); // 隐式调用构造函数
    Stock stock2 = Stock("co2"); // 显式调用构造函数
    Stock stock3;
    Stock stock4 {"co3"}; // 列表初始化
    Stock stock(); // 无构造打印，其实声明了一个函数
    Stock *pStock = new Stock("coP"); // 匿名对象

    stock1.update(100);
    stock4 = stock1 + stock2; // = 100
    stock4.operator+(stock3); // = 1098

    cout << int (stock1) << endl;

    return 0;
}





