/* 模板特化.cpp 

模板的特化是指在模板基础上对特定类型或特定情况进行额外定义或实现的过程。
当使用模板时，有时需要对特定类型或特定情况进行特殊处理，而不是使用模板的默认实现。


*/
// Eg9-6.cpp
#include <cstring>
#include <iostream>
using namespace std;
template <class T> T Max(T a, T b) { return (a > b) ? a : b; }
//特化
// template <> 返回类型 函数名<特化的数据类型>(参数表) {}
template <> const char *Max<const char *>(const char *a, const char *b) {
  return (strcmp(a, b) >= 0) ? a : b;
}
template <> char *Max<char *>(char *a, char *b) {
  return (strcmp(a, b) >= 0) ? a : b;
}
int main() {
  float c = 5.1, d = 3.2;
  char s1[] = "xyce", s2[] = "xbv";
  cout << "2,3的最大值是：" << Max(3, 2) << endl;
  cout << "c,d的最大值是：" << Max(c, d) << endl;
  cout << Max("xbv", "xyce") << endl;
  cout << Max(s1, s2) << endl;
  
}
/*
① 当程序中同时存在模板和它的特化时，特化将被优先调用；
② 在同一个程序中，除了函数模板和它的特化外，还可以有同名的普通函数。其区别在于C++会对普通函数的调用实参进行隐式的类型转换，
但不会对模板函数及特化函数的参数进行任何形式的类型转换。

上面代码，对于const char*类型和char*类型的参数，分别提供了特化的定义。
通过在函数名后面添加<特化的数据类型>来指定特化的类型。

对于const char*类型的特化，函数返回类型为const char*，并且函数名为Max<const char*>。
对于char*类型的特化，函数返回类型为char*，并且函数名为Max<char*>。

*/