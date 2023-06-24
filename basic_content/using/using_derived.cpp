/**
 * @file using_derived.cpp
 * @brief 函数重装
 * @author 光城
 * @version v1
 * @date 2019-08-07
 */

#include <iostream>
using namespace std;

class Base {
public:
  void f() { cout << "f()" << endl; }
  void f(int n) { cout << "Base::f(int)" << endl; }
};

class Derived : private Base {
public:
  using Base::f;
  void f(int n) { cout << "Derived::f(int)" << endl; }
};

int main() {
  Derived d;
  d.f();
  d.f(1);
  return 0;
}
/*
如果对于基类的重载函数，我们需要在派生类中修改一个，又要让其他的保持可见，必须要重载所有版本，这样十分的繁琐。
使用using关键字可以将基类的函数或变量在派生类作用域内重新声明，方便派生类使用基类的成员。
基类成员函数的using声明语句就可以把该函数的所有重载实例添加到派生类的作用域中。
此时，派生类只需要定义其特有的函数就行了，而无需为继承而来的其他函数重新定义。




执行结果：
f()
Derived::f(int)
*/