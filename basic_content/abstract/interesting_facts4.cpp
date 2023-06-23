/**
 * @file interesting_facts4.cpp
 * @brief 抽象类可以有构造函数
 * @author 光城
 * @version v1
 * @date 2019-07-20
 */

#include <iostream>
using namespace std;

// An abstract class with constructor
class Base {
protected:
  int x;

public:
  virtual void fun() = 0;
  Base(int i) { x = i; }  //抽象类可以有构造函数
};

class Derived : public Base {
  int y;

public:
  //构造函数Derived(int i, int j)，先调用了Base类的构造函数，
  //初始化了Base类中的数据成员x，同时在Derived类中新增了一个数据成员y，并通过y=j进行初始化。 
  //通过这种方式，Derived类中既继承了Base类中的数据成员x，又新增了自己的数据成员y，从而达到了扩展基类的目的。
  Derived(int i, int j) : Base(i) { y = j; } 
  void fun() { cout << "x = " << x << ", y = " << y; }
};

int main(void) {
  Derived d(4, 5);
  d.fun();
  return 0;
}

//x = 4, y = 5