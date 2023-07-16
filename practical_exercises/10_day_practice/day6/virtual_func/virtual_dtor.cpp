/* 虚析构函数.cpp */
/*
基类析构函数几乎总是为虚析构函数:
假定使用delete和一个指向派生类的基类指针来销毁派生类对象，如果基类析构函数不为虚,就如一个普通成员函数，delete函数调用的就是基类析构函数。
在通过基类对象的引用或指针调用派生类对象时，将致使对象析构不彻底！
*/
#include <iostream>
using namespace std;
class A {
public:
  // 虚析构函数
  virtual ~A() { cout << "call A::~A()" << endl; }
};
class B : public A {
  char *buf;

public:
  B(int i) { buf = new char[i]; }
  ~B() {
    delete[] buf;
    cout << "call B::~()" << endl;
  }
};
int main() {
  A *a = new B(10);
  delete a;
  
  return 0;
}
