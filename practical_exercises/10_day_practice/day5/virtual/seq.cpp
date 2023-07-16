/* 虚基类调用次序(重要).cpp */
//重要!!!
#include <iostream>
using namespace std;
class A {
  int a;

public:
  A() { cout << "Constructing A" << endl; }
};
class B {
public:
  B() { cout << "Constructing B" << endl; }
};
class B1 : virtual public B, virtual public A {
public:
  B1(int i) { cout << "Constructing B1" << endl; }
};
class B2 : public A, virtual public B {
public:
  B2(int j) { cout << "Constructing B2" << endl; }
};
class D : public B1, public B2 {
public:
  D(int m, int n) : B1(m), B2(n) { cout << "Constructing D" << endl; }
  A a;
};

int main() {
  D d(1, 2);
  
  return 0;
}
/*

调用构造函数顺序：
先调用虚基类的构造函数，再调用非虚基类的构造函数。
若同一层次中包含多个虚基类,这些虚基类的构造函数按它们的说明的次序调用
若虚基类由非基类派生而来,则仍然先调用基类构造函数,再调用派生类构造函数

B1   虚->   B  以及   虚->    A
B2   虚->   B  以及     ->    A
D     ->   B1和B2



执行结果：
Constructing B
Constructing A
Constructing B1
Constructing A        为何下面不在构造B?  看不懂！！！！
Constructing B2
Constructing A
Constructing D





*/