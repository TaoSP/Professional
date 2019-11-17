// 2019.11.17
// 友元
//
// P391.
// 另一种形式的访问权限：友元函数、友元类、友元成员函数
//      类的友元函数是非成员函数，访问权限与成员函数相同
// 常用的友元：重载 << 运算符
// Time 类使用 cout, 必须使用友元，因为 operator<<() 直接访问Time对象私有成员
// cout << x << y; 等同于 (cout << x) << y; 返回一个指向调用对象(cout)的引用
// 

/******************************************************************************
 * C++PrimerPlus_friend.cpp
 *
 * Copyright (C) xxx CO.,LTD.
 * Author : Huangtao
 * Version: V1.0.0  2019-11-17 Create
 * Description: 
 * 
******************************************************************************/
#include <iostream>
//using namespace std;

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void show() const;
    Time operator+(const Time & t) const;
    Time operator*(double n) const;
    friend Time operator*(double n, const Time & t); // 此运算符函数的参数太多，故声明为友元
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

Time::Time() :hours(12), minutes(10)
{}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::show() const
{
    std::cout << hours << ':' << minutes << std::endl;
}

Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator*(double n) const
{
    Time res;
    long total = hours * n * 60 + minutes * n;
    res.hours = total / 60;
    res.minutes = total % 60;
    return res;
}

Time operator*(double n, const Time & t)
{
    Time res;
    long total = t.hours * n * 60 + t.minutes * n;
    res.hours = total / 60;
    res.minutes = total % 60;
    return res;
    //return t * n; // 可以用友元函数反转操作数
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << ":" << t.minutes;
    return os;
}

int main()
{
    Time t1;
    t1.show();

    Time t2 = t1 * 2;
    t2.show();
    t2 = t2 + t1;
    t2.show();

    Time t3 = 4 * t1;
    std::cout << t3 << std::endl;

    return 0;
}

