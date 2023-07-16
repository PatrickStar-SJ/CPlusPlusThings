/* 例1.cpp */
#include <iostream>
using namespace std;
/*
多继承下的二义性：在多继承方式下，派生类继承了多个基类的成员，当两个不同基类拥有同名成员时，容易产生名字冲突问题。
*/
class A {
public:
  void vf() { cout << "I come from class A" << endl; }
};
class B : public A {};
class C : public A {};
class D : public B, public C {};

int main() {
  D d;
  d.vf(); /* error
          // 错误的原因是类D从类B和类C中都继承了vf()函数，而编译器无法确定应该调用哪一个。
          // 为了解决这个问题，可以使用作用域解析运算符来显式调用类B或类C中的vf()函数：
          //    d.B::vf(); // 调用类B中的vf()函数
          //    d.C::vf(); // 调用类C中的vf()函数
          //
          // 或者，可以在类D中重写vf()函数来指定使用哪个实现：
                void vf() { B::vf(); } // 重写vf()函数，调用类B中的vf()函数
          */
  
  return 0;
}
