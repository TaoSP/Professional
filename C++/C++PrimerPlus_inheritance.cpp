// 2019.11.24
// 第13章 类继承
//
// 公有派生类，只能通过基类的公有和保护方法 protected 访问基类私有部分
// 派生类构造函数：创建基类对象， 通过成员初始化列表将信息传递给基类构造函数，初始化派生类新增的数据成员
// 派生类和基类关系：
//      基类指针和引用可以在不显示类型转换下指向或引用派生类对象
//      也可将派生类对象赋值给基类对象（基类部分复制）
// is-a 派生类对象也是一个基类对象
// 多态公有继承，同一个方法的行为随上下文而异
//      在派生类中重新定义基类方法；使用虚方法
// 虚方法 virtual, 只用于类声明的方法原型
// 惯例：虚析构函数，确保释放派生类对象时，按正确顺序调用析构函数（将自动调用基类析构函数）
// 如果没有 virtual, 程序将根据引用或指针类型选择方法，
// 如果使用 virtual, 程序将根据引用或指针指向的对象类型选择方法
// 1.静态联编（早期联编），如函数重载，编译器查看参数和函数名后可在编译时完成联编
//      编译器对非虚方法使用静态联编
// 2.动态联编（晚期联编），运行时选择正确的虚方法
//      向上强制类型转换（将派生类引用或指针转换为基类的引用或指针）
//      编译器处理虚函数：给对象添加一个隐藏成员，指向函数地址数组指针
//      编译器为每个类创建一个虚函数地址表（数组）
// 构造函数不能被继承（创建对象），不能是虚函数（无意义），友元不是成员函数不能是虚函数
// 重新定义将隐藏方法（不同于重载），隐藏同名的基类方法，不管参数特征标如何，因此如果基类声明有重载，
//      应在派生类重写定义所有的基类版本
// 抽象基类（结尾处=0），至少包含一个纯虚函数， virtual void fun() = 0
// 当基类和派生类都采用动态内存分配时，重载 = 和 << 实现深度复制，
//      派生类的析构函数、复制构造函数、赋值运算符必须使用相应的基类方法来处理基类元素，必须显式定义
//

/******************************************************************************
 * C++PrimerPlus_inheritance.cpp
 *
 * Copyright (C) xxx CO.,LTD.
 * Author : Huangtao
 * Version: V1.0.0  2019-11-24 Create
 * Description: 
 * 
******************************************************************************/
#include <iostream>
#include <cstring>
using std::string;

class Car
{
private:
    string name;
    double price;
public:
    Car(string n) :name(n)
    {}
    virtual ~Car()
    {
        static int i;
        std::cout << "Freeing Car" << i++ << std::endl;
    }
    string getName() const
    {
        return name;
    }
    void show()
    {
        std::cout << "I'am Base Car" << std::endl;
    }
    virtual void newShow()
    {
        std::cout << "I'am Base Car" << std::endl;
    }
};

class VW: public Car
{
private:
    string factory;
public:
     // 如果没有在成员初始化列表指定，派生类将自动调用基类默认构造函数
    VW(string n) :Car(n), factory("FAW") // 这里显式调用
    {}
    virtual ~VW()
    {
        std::cout << "Freeing VW" << std::endl;
    }
    void show()
    {
        std::cout << "I'am Derived VW" << std::endl;
    }
    virtual void newShow()
    {
        std::cout << "I'am Derived VW" << std::endl;
    }
};

void showName(Car &c) // 形参是基类引用
{
    std::cout << c.getName() << std::endl;
}

// 继承与动态内存分配
class Base
{
private:
    char *lable;
public:
    Base(char *l = "test");
    ~Base();
    Base & operator=(const Base & rs); // 实现连续赋值
    friend std::ostream & operator<<(std::ostream & os, Base & rs);
};
Base::Base(char *l)
{
    lable = new char[strlen(l) + 1];
    strcpy(lable, l);
}
Base::~Base()
{
    delete [] lable;
}
Base & Base::operator=(const Base & rs)
{
    if(this == &rs) // 同一对象直接返回，否则会将该对象内容delete
        return *this;
    delete [] lable;
    lable = new char[strlen(rs.lable) + 1];
    strcpy(lable, rs.lable);
    return *this;
}
std::ostream & operator<<(std::ostream & os, Base & rs)
{
    os << "Base: " << rs.lable << std::endl;
    return os;
}

class MyBase :public Base
{
private:
    char *style;
public:
    MyBase(char *l, const Base & rs);
    ~MyBase();
    MyBase & operator=(const MyBase & rs);
    friend std::ostream & operator<<(std::ostream & os, MyBase & rs);
};
MyBase::MyBase(char *l, const Base & rs) :Base(rs)
{
    style = new char[strlen(l) + 1];
    strcpy(style, l);
}
MyBase::~MyBase()
{
    delete [] style;
}
MyBase & MyBase::operator=(const MyBase & rs)
{
    if(this == &rs)
        return *this;
    Base::operator=(rs); // 显式调用基类赋值运算符
    delete [] style;
    style = new char[strlen(rs.style) + 1];
    strcpy(style, rs.style);
    return *this;
}
std::ostream & operator<<(std::ostream & os, MyBase & rs)
{
    os << "MyBase: " << (Base &) rs; // 向上强制类型转换，调用基类友元
    os << "MyBase: " << rs.style << std::endl;
    return os;
}

int main()
{
    Car c1("CAR-2019");
    VW v1("VW-2019");
    showName(c1);
    showName(v1);

    Car & carRef1 = c1;
    carRef1.show();
    carRef1.newShow();
    Car & carRef2 = v1;
    carRef2.show();
    carRef2.newShow(); // VW
    //delete &carRef1;
    //delete &carRef2;
    //v1.~VW();

    Base base1("Tao");
    Base base2("222");
    std::cout << base1;
    MyBase my1("My1", base2);
    std::cout << my1;
    base1 = my1;
    base1 = base1;
    std::cout << base1; // Base: 222

    return 0;
}

