/* 派生类初始化.cpp */
#include <iostream>
using namespace std;
class A {
  int a;

public:
  A(int x) {
    a = x;
    cout << "Virtual Bass A..." << endl;
  }
};
class B : virtual public A {
public:
  B(int i) : A(i) { cout << "Virtual Bass B..." << endl; }
};
class C : virtual public A {
  int x;

public:
  C(int i) : A(i) {
    cout << "Constructing C..." << endl;
    x = i;
  }
};
class ABC : public C, public B {
public:
  //虚基类由最终派生类初始化
  ABC(int i, int j, int k)
      : C(i), B(j), A(i) // L1，这里必须对A进行初始化。
                         // 在虚拟继承方式下，虚基类则由最终派生类的构造函数负责初始化。
  {
    cout << "Constructing ABC..." << endl;
  }
};
int main() {
  ABC obj(1, 2, 3);
  
  return 0;
}

/*
B     虚->   A
C     虚->   A
ABC    ->   B和C


由于类C和类B都通过虚继承继承自类A，所以在类ABC的构造函数中，必须指定要使用虚基类A的哪个实例。通过在构造函数的初始化列表中使用A(i)，可以指定使用虚基类A的实例来初始化。

如果在类ABC的构造函数中不显式地对类A进行初始化，编译器在编译时会报错。这是因为在多继承中，编译器需要确定恰当的顺序来初始化虚基类，以避免二义性。在这种情况下，由于类A是虚基类，所以必须由类ABC来完成对类A、类B和类C的初始化，以确保只有一个类A的实例被创建。






*/
