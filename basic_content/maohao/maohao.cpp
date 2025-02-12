#include <iostream>
using namespace std;

int count = 0; // 全局(::)的count

class A {
public:
  static int count; // 类A的count (A::count)
};
// 静态变量必须在此处定义
int A::count;
int main() {
  ::count = 1;  // 设置全局的count为1
  A::count = 5; // 设置类A的count为2
  cout << A::count << endl;
  //    int count=3; // 局部count
  //    count=4;     // 设置局部的count为4
  return 0;
}


/*
全局作用域符（::name）：用于类型名称（类、类成员、成员函数、变量等）前，表示作用域为全局命名空间
类作用域符（class::name）：用于表示指定类型的作用域范围是具体某个类的
命名空间作用域符（namespace::name）:用于表示指定类型的作用域范围是具体某个命名空间的
*/