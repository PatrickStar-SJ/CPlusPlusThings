// Eg6-12.cpp
#include <iostream>
using namespace std;
class A {
  int x;

public:
  A(int i = 0) {
    x = i;
    cout << "A-----" << x << endl;
  }
};
class B {
  int y;

public:
  B(int i) {
    y = i;
    cout << "B-----" << y << endl;
  }
};
class C {
  int z;

public:
  C(int i) {
    z = i;
    cout << "C-----" << z << endl;
  }
};
class D : public B {
public:
  C c1, c2;
  A *a1 = new A(10);
  A a0, a4;
  D() : a4(4), c2(2), c1(1), B(1) { cout << "D-----5" << endl; }
};
int main() {
  D d;
  
}


/*

代码的执行顺序如下：

创建对象d，调用D的构造函数。

在D的构造函数中，先调用B的构造函数，输出"B-----1"。

在D的构造函数中，再调用C的构造函数，输出"C-----1"。

在D的构造函数中，再调用C的构造函数，输出"C-----2"。

在D的构造函数中，创建A对象a1，调用A的构造函数，输出"A-----10"。

在D的构造函数中，创建A对象a0，调用A的构造函数，输出"A-----0"。

在D的构造函数中，创建A对象a4，调用A的构造函数，输出"A-----4"。

输出"D-----5"。


因此，代码的执行顺序是：
B-----1
C-----1
C-----2
A-----10
A-----0    这个很容易忘记！！！！！
A-----4
D-----5

!!!! 并不是按照列表初始化顺序，而是按照定义顺序，调用构造函数。
*/