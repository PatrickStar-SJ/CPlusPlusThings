/* 基类与派生类(重要).cpp */
#include <iostream>
using namespace std;
class A {
  int a;

public:
  void setA(int x) { a = x; }
  int getA() { return a; }
};
class B : public A {
  int b;

public:
  void setB(int x) { b = x; }
  int getB() { return b; }
};
void f1(A a, int x) { a.setA(x); }
void f2(A *pA, int x) { pA->setA(x); }
void f3(A &rA, int x) { rA.setA(x); }

int main() {
  A a1, *pA;
  B b1;
  a1.setA(1);
  b1.setA(2);
  //把派生类对象赋值给基类对象。
  a1 = b1;
  cout << a1.getA() << endl;
  cout << b1.getA() << endl;
  a1.setA(10);
  cout << a1.getA() << endl;
  cout << b1.getA() << endl;
  //把派生类对象的地址赋值给基类指针。
  pA = &b1;
  pA->setA(20);
  cout << pA->getA() << endl; //通过指针修改b1的成员变量a的值为20
  cout << b1.getA() << endl;  //由于b1与pA指向同一块内存地址，所以b1.getA()为20
  //用派生类对象初始化基类对象的引用。
  A &ra = b1;
  ra.setA(30);
  cout << pA->getA() << endl;  //理由同上
  cout << b1.getA() << endl;
  b1.setA(7);
  cout << b1.getA() << endl;
  f1(b1, 100);
  cout << "1111111111" << endl;
  cout << b1.getA() << endl; // 7  调用f1(b1, 100)函数，传递的是b1对象的副本，
                             // 所以在函数中修改的是副本的成员变量a的值，不影响原对象b1的成员变量a的值。
                             // 因此，b1.getA()的值仍为7。

  f2(&b1, 200);              // f2通过指针修改了b1成员变量a的值
  cout << b1.getA() << endl;
  f3(b1, 300);               // f2通过引用修改了b1成员变量a的值
  cout << b1.getA() << endl;
  
  return 0;
}