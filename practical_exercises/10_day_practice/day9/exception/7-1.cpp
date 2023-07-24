// Eg10-9.cpp
#include <iostream>
using namespace std;
class A {
  int a;

public:
  A(int i = 0) : a(i) {cout<<"A constructor..."<<endl;}
  ~A() { cout << "in A destructor..." << endl; }
};
class B {
  A obj[3];
  double *pb[10];

public:
  B(int k) {
    cout << "int B constructor..." << endl;
    for (int i = 0; i < 10; i++) {
      pb[i] = new double[20000000];
      if (pb[i] == 0)
        throw i;
      else
        cout << "Allocated 20000000 doubles in pb[" << i << "]" << endl;
    }
  }
};
int main() {
  try {
    B b(2);
  } catch (int e) {
    cout << "catch an exception when allocated pb[" << e << "]" << endl;
  }
  
}
/*
这段代码定义了两个类：A和B。类A有一个整型成员变量a和一个构造函数和析构函数，构造函数接受一个整型参数并将其赋值给成员变量a，默认值为0。析构函数打印一条消息。

类B有一个A类型的数组obj和一个指向双精度浮点数指针的数组pb。类B的构造函数接受一个整型参数k。
在构造函数中，它首先打印一条消息，然后使用循环分配10个长度为20000000的双精度浮点数数组，并将它们的地址存储在pb数组中。
如果分配失败，它会抛出一个整型异常，并打印一条消息。

在主函数中，它尝试创建一个B类型的对象b，并传递参数2给构造函数。如果构造函数抛出异常，它会捕获并打印一条消息。



C++使用一个类名创建一个数组对象，长度为n，那么就会n次调用默认构造函数吗？
是的，当使用一个类名创建一个数组对象时，长度为n，将会调用n次默认构造函数。每次调用默认构造函数都会创建一个数组中的元素，初始化为默认值。
*/