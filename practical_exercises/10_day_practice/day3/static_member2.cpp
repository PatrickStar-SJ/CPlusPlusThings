/* 静态成员函数2.cpp */
#include <iostream>
using namespace std;
class A {
public:
  static void f(A a);

private:
  int x;
};
void A::f(A a) {

  //静态成员函数只能引用属于该类的静态数据成员或静态成员函数。
  // cout<<x; //对x的引用是错误的

  //正确，静态成员函数只能访问静态成员变量和静态成员函数，不能访问非静态成员变量和非静态成员函数
  // 在静态成员函数中引用非静态成员变量时，需要通过对象名或者对象指针来进行访问。
  cout << a.x; 
}

int main(int argc, char const *argv[]) {
  A a;
  a.f(A());
  
  return 0;
}
