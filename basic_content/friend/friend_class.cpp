#include <iostream>

using namespace std;

class A {
public:
  A(int _a) : a(_a){};
  friend class B;

private:
  int a;
};

class B {
public:
  int getb(A ca) { return ca.a; };
};

int main() {
  A a(3);
  B b;
  cout << b.getb(a) << endl;
  return 0;
}
/*
友元类：
1. 友元类的声明在该类的声明中，而实现在该类外。
2. 类B是类A的友元，那么类B可以直接访问A的私有成员。

注意点：
1. 友元关系没有继承性 假如类B是类A的友元，类C继承于类A，那么友元类B是没办法直接访问类C的私有或保护成员
2. 友元关系没有传递性 假如类B是类A的友元，类C是类B的友元，那么友元类C是没办法直接访问类A的私有或保护成员，也就是不存在“友元的友元”这种关系。
*/