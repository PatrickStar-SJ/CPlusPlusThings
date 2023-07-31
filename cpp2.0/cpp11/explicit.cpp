//
// Created by light on 19-11-3.
//

#include <iostream>

using namespace std;

// non-explicit-one-argument ctor
class Fraction
{
public:
    // non-explicit-one-argument ctor 可以把别的东西转换为Fraction这种
    Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}

    Fraction operator+(const Fraction &f)
    {
        return Fraction(this->m_numerator + f.m_numerator);
    }

    void getNumAndDen()
    {
        cout << m_numerator << " " << m_denominator << endl;
    }

private:
    int m_numerator;   // 分子
    int m_denominator; // 分母
};

// explicit-one-argument ctor
class Fraction1
{
public:
    // explicit-one-argument ctor 可以把别的东西转换为Fraction这种
    explicit Fraction1(int num, int den = 1) : m_numerator(num), m_denominator(den) {}

    Fraction1 operator+(const Fraction1 &f)
    {
        return Fraction1(this->m_numerator + f.m_numerator);
    }

    void getNumAndDen()
    {
        cout << m_numerator << " " << m_denominator << endl;
    }

private:
    int m_numerator;   // 分子
    int m_denominator; // 分母
};

class P
{
public:
    P(int a, int b)
    {
        cout << "P(int a,int b)\n";
    }

    P(int a, int b, int c)
    {
        cout << "non-explicit P(int a,int b,int c)\n";
    }
    explicit P(int a, int b, int c, int d)
    {
        cout << "explicit P(int a,int b,int c,int d)\n";
    }
};

void fp(const P &)
{
}

int main()
{
    Fraction f(3, 5);
    Fraction ff = f + 3; // 会将3转换为(3,1)   隐式转换
    ff.getNumAndDen(); //====>  6 1

    // 如果不想编译器进行隐式转换,可以在前面添加explicit关键字

    // c++2.0之前explicit只禁止"存在单一实参"转换
    // c++2.0之后explicit可以进制"多个实参"转换
    //    Fraction1 f1(3,5);
    //    Fraction1 f2 = f1+3; // 会将3转换为(3,1)   不会隐式转换    执行会报错 ==> error: no match for ‘operator+’ (operand types are ‘Fraction1’ and ‘int’)
    //    f2.getNumAndDen();
    P p1 = {77, 5};
    P p2 = {77, 5, 89};
    //    P p3 = {77, 5, 89,99}; //显式构造函数使用关键字explicit修饰，表示禁止隐式类型转换。
                                 // 因此，无法像上述例子中那样直接使用花括号初始化语法来调用显式构造函数。
                                 //如果尝试使用花括号初始化语法进行显式构造函数的初始化，编译器将会报错。
    return 0;
}

/*
Fraction(int num, int den = 1)。
这是一个非显式的单参数构造函数，允许将整数转换为Fraction对象。参数num表示分子，参数den表示分母，默认为1。
构造函数的第二个参数有一个默认值为1，所以可以只传递一个参数来创建一个整数分数。


运算符重载：operator+。
这个函数重载了"+"运算符，用于将两个Fraction对象相加。它返回一个新的Fraction对象，
其分子等于原始Fraction对象的分子与另一个Fraction对象的分子之和，分母保持不变。

在主函数main()中，首先创建了一个Fraction对象f，其分子为3，分母为5。
然后，通过将整数3与Fraction对象f相加，创建了一个新的Fraction对象ff。
由于构造函数的非显式特性，整数3被隐式转换为Fraction对象(3, 1)，其中3为分子，1为分母。



为什么执行  P p1 = {77, 5};会显示的调用
    P(int a, int b){cout << "P(int a,int b)\n";}
    
会调用 P(int a, int b) 构造函数是因为这是使用初始化列表语法创建对象时的行为。
P p1 = {77, 5}; 使用大括号初始化器创建了一个名为 p1 的对象，并将值 77 和 5 分别传递给构造函数的参数 a 和 b。这被称为聚合初始化，它通过初始化列表语法来进行。
*/
