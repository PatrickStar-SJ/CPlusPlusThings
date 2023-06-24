/**
 * @file rtti.cpp
 * @brief
 * 在面向对象程序设计中，有时我们需要在运行时查询一个对象是否能作为某种多态类型使用。与Java的instanceof，以及C#的as、is运算符类似，C++提供了dynamic_cast函数用于动态转型。相比C风格的强制类型转换和C++
 * reinterpret_cast，dynamic_cast提供了类型安全检查，是一种基于能力查询(Capability
 * Query)的转换，所以在多态类型间进行转换更提倡采用dynamic_cast
 * @author 光城
 * @version v1
 * @date 2019-07-24
 */

// CPP program to illustrate
// Run Time Type Identification
#include <iostream>
#include <typeinfo>
using namespace std;
class B {
  virtual void fun() {}
};
class D : public B {};

int main() {
  B *b = new D; // 向上转型
  B &obj = *b;
  D *d = dynamic_cast<D *>(b); // 向下转型
  if (d != NULL)
    cout << "works" << endl;
  else
    cout << "cannot cast B* to D*";

  try {
    D &dobj = dynamic_cast<D &>(obj);
    cout << "works" << endl;
  } catch (bad_cast bc) { // ERROR
    cout << bc.what() << endl;
  }
  return 0;
}

/*

有时我们需要在运行时查询一个对象是否能作为某种多态类型使用，C++的dynamic_cast函数提供了类型安全检查，用于动态转型。

在使用dynamic_cast()时需要注意：被转换对象obj的类型T1必须是多态类型，即T1必须公有继承自其它类，或者T1拥有虚函数（继承或自定义）。
若T1为非多态类型，使用dynamic_cast会报编译错误。见warn_rtti.cpp

这段代码实现了向上转型和向下转型，并使用了 dynamic_cast 运算符进行类型转换。具体含义如下：
1. 定义了类 B 和类 D，其中 D 从 B 继承。
2. 在 main 函数中先进行了向上转型，即把一个 D 类型的对象指针赋值给一个 B 类型的指针变量。
3. 在进行向下转型前，先使用 dynamic_cast 对指针变量进行类型转换，并将结果赋值给一个 D* 类型的指针变量。
4. 在转换后检查 D* 指针变量是否为 NULL，如果不为 NULL 则表示类型转换成功，输出 "works"。
5. 对同一个指针变量进行另一种类型转换，这次是使用 dynamic_cast 对一个指向 B 类型的引用进行类型转换，使其指向一个 D 类型的对象。
6. 如果转换成功，则输出 "works"。
7. 如果转换失败，则会抛出 bad_cast 异常。
8. 最后返回 0，表示程序正常结束。

执行结果：
works
works
*/