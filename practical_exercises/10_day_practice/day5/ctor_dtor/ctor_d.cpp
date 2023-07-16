#include <iostream>
using namespace std;
class A {
public:
  A() { cout << "Constructing A" << endl; }
  ~A() { cout << "Destructing A" << endl; }
};
class B {
public:
  B() { cout << "Constructing B" << endl; }
  ~B() { cout << "Destructing B" << endl; }
};
class C {
public:
  C() { cout << "Constructing C" << endl; }
  ~C() { cout << "Destructing C" << endl; }
};
class D : public C {
public:
  D() { cout << "Constructing D" << endl; }
  ~D() { cout << "Destructing D" << endl; }
  B b;
  A a;
  C c;
};

int main() {
  D d;
  
}


/*
调用构造函数的顺序：
先调用基类的构造函数，（最远的基类，最先构造）
再调用成员的构造函数， （成员构造顺序，与定义顺序相符）
最后调用自身的构造函数。

调用析构函数的顺序相反。
*/

/*
执行结果：
Constructing C
Constructing B
Constructing A
Constructing C
Constructing D
Destructing D
Destructing C
Destructing A
Destructing B
Destructing C
*/