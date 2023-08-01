//
// Created by light on 19-11-3.
//

#include <iostream>
#include <complex>

using namespace std;

class Zoo {

public:
    Zoo(int a, int b) : a(a), b(b) {
        cout << "with param ctor \n";
    }

    Zoo() = default;

    Zoo(const Zoo &) = delete;  // copy ctor

    Zoo(Zoo &&) = default;      // move ctor

    Zoo &operator=(const Zoo &) = default;  // copy assignment

    Zoo &operator=(const Zoo &&) = delete;  // move assignment

    // 一般函数可以使用=default或=delete?
//    void fun1()= default; // error: ‘void Zoo::fun1()’ cannot be defaulted
    void fun1() = delete; // compile ok
    // 析构函数可以使用=default或=delete?
//    ~Zoo()= delete;   // ok,但是造成使用Zoo object出错
    ~Zoo() = default;

    // 上述得出=delete可以使用在任何函数身上,而=default不可以使用在普通函数上
    // 上述会联想到=0,=0只能用在virtual funciton上

private:
    int a, b;
};

class Empty {
};

// 等价于  编译器给出的默认版本函数都是public且inline
class Empty1 {
public:
    Empty1() {}

    Empty1(const Empty1 &rhs) {}

    ~Empty1() {}
};

// no-copy
// copy ctor与copy assignment都delete掉
struct NoCopy {
    NoCopy() = default;

    NoCopy(const NoCopy &) = delete;

    NoCopy &operator=(const NoCopy &) = delete;

    ~NoCopy() = default;
};

// no-dtor
struct NoDtor {
    NoDtor() = default;

    ~NoDtor() = delete;
};

// 对no-copy的改进 将copy ctor与copy assignment 放到private ,但是可以对member与friend调用
// boost::noncopyable 就用到了PrivateCopy
class PrivateCopy {
private:
    PrivateCopy(const PrivateCopy &) {};

    PrivateCopy &operator=(const PrivateCopy &) {};

public:
    PrivateCopy() = default;

    ~PrivateCopy() {};
};

// 继承了的都拥有PrivateCopy性质
class Foo : public PrivateCopy {

};

int main() {
    Zoo z;
    Zoo z1(1, 2);
//    Zoo z2=z;   // 禁止使用复制构造函数来创建Zoo对象的副本。
    z = z1;
    complex<int> a;     // 内部不带指针的可以不用写 big three 没有析构 有copy ctor与copy assignmetn 都是使用=default,没有自己写
    string s;       // 内部带指针的有big five

//    NoDtor n;  //error no-dtor 不能够自动delete
//    NoDtor *p=new NoDtor;   // ok
//    delete p;   // error no-dtor 不能够delete
    Foo foo;
    Foo foo1;
//    foo = foo1;   // 继承了的都拥有PrivateCopy性质
    return 0;
}

/*
class Zoo:
    上述代码定义了一个名为Zoo的类。该类有两个私有成员变量a和b，表示动物园的某些属性。

    Zoo(int a, int b) : a(a), b(b)是一个带有参数的构造函数。当创建Zoo对象时，可以传入两个整数参数a和b来初始化成员变量a和b。构造函数中的cout语句用于输出一条带有参数的构造函数的信息。

    Zoo() = default;是一个默认构造函数。当创建Zoo对象时，如果没有传入任何参数，则会调用该默认构造函数进行初始化。

    Zoo(const Zoo &) = delete;是一个删除的复制构造函数。这意味着在代码中禁止使用复制构造函数来创建Zoo对象的副本。

    Zoo(Zoo &&) = default;是一个移动构造函数。它允许使用移动语义来创建Zoo对象的副本。

    Zoo &operator=(const Zoo &) = default;是一个默认的复制赋值运算符。它允许将一个Zoo对象的值复制给另一个Zoo对象。

    Zoo &operator=(const Zoo &&) = delete;是一个删除的移动赋值运算符。这意味着在代码中禁止使用移动赋值运算符来将一个Zoo对象的值移动给另一个Zoo对象。

    void fun1() = delete;是一个被删除的成员函数。这意味着在代码中禁止使用名为fun1的函数。

    ~Zoo() = default;是一个默认析构函数。它用于在Zoo对象被销毁时执行清理操作。

    总结：
    = default可以用于构造函数（包括默认构造函数、复制构造函数和移动构造函数）、析构函数和复制赋值运算符，表示使用编译器生成的默认实现。
    = delete可以用于复制构造函数、移动赋值运算符和成员函数，表示禁用对应的函数或者操作。


class PrivateCopy：
    PrivateCopy(const PrivateCopy &) {};：这是一个私有的拷贝构造函数（Copy Constructor），
    它通过将其参数声明为对PrivateCopy类的引用来禁止对象的拷贝构造。这意味着无法使用拷贝构造函数创建该类的新对象。

    PrivateCopy &operator=(const PrivateCopy &) {};：这是一个私有的赋值运算符重载函数，
    它通过将其参数声明为对PrivateCopy类的引用来禁止对象之间的赋值操作。这意味着无法使用赋值运算符将一个PrivateCopy对象的值复制到另一个PrivateCopy对象中。

    该类的目的是禁止对象的拷贝和赋值操作。通过将拷贝构造函数和赋值运算符重载函数声明为私有，并且不提供实现，
    可以防止其他代码对该类进行拷贝或赋值操作。只允许通过默认构造函数创建对象，并在对象销毁时执行一些清理操作。
*/