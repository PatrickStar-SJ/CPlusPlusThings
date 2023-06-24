/**
 * @file virtual_inline.cpp
 * @brief 通常类成员函数都会被编译器考虑是否进行内联。
 * 但通过基类指针或者引用调用的虚函数必定不能被内联。
 * 当然，实体对象调用虚函数或者静态调用时可以被内联，虚析构函数的静态调用也一定会被内联展开。
 * @author 光城
 * @version v1
 * @date 2019-07-24
 */

#include <iostream>
using namespace std;
class Base {
public:
  virtual void who() { cout << "I am Base\n"; }   //虚函数
};
class Derived : public Base {
public:
  void who() { cout << "I am Derived\n"; }  // 不写inline时隐式内联
};

int main() {
// 这里的虚函数 who() 是通过类的对象调用的（它会在编译时解析），因此可以进行内联
  Base b;
  b.who();

// 但是，在这里，虚函数是通过指针调用的，所以无法进行内联。
  Base *ptr = new Derived();
  ptr->who();

  return 0;
}

/*
并没看懂最上面解说，与代码关系，没有内联函数啊！
chatgpt:
在 main 函数中，首先是通过一个实体对象 b 调用了虚函数 who()，此时可以进行内联展开。
但是在通过基类指针 ptr 调用虚函数 who() 时，由于编译器不知道实际所指向的对象，
因此无法进行内联展开。因此，基类指针或者引用调用的虚函数必定不能被内联。

上面解说知识点，实际是配合  inline_virtual.cpp来看。

执行结果：
I am Base
I am Derived

*/
