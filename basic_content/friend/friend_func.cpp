#include <iostream>

using namespace std;

class A {
public:
  A(int _a) : a(_a){};
  friend int geta(A &ca); ///< 友元函数
private:
  int a;
};

int geta(A &ca) { return ca.a; }

int main() {
  A a(3);
  cout << geta(a) << endl;

  return 0;
}
/*
友元函数：
友元函数只是一个普通函数，不是类的成员函数，友元函数可以在任何地方调用。
友元函数中通过对象名来访问该类的私有或保护成员。

*/