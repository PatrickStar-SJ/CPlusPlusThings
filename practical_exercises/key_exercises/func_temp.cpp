/* 函数模板.cpp */

/*

函数模板以及特化版本的使用
*/
#include <cstring>
#include <iostream>
using namespace std;

template <class T> T compareMax(T t1, T t2) { return t1 > t2 ? t1 : t2; }

template <>
const char *compareMax<const char *>(const char *s1, const char *s2) {
  cout << "[for debug]"
       << " call compareMax template" << endl;
  return strcmp(s1, s2) >= 0 ? s1 : s2;
}
int main(int argc, char const *argv[]) {
  cout << compareMax(1, 2) << endl;
  cout << compareMax("asda", "qweq") << endl;
  
  return 0;
}
/*
定义了一个名为compareMax的函数模板，用于比较两个值的大小并返回较大的值。该函数模板使用了模板参数T，表示待比较的值的类型。

代码中特化了compareMax函数模板的一个版本，用于比较两个const char类型的字符串，并返回较大的字符串。
特化版本使用了模板参数T为const char，并在函数体内部使用了strcmp函数来比较两个字符串的大小。

在main函数中，首先调用了compareMax函数模板，并传递了两个整数1和2作为参数，输出了较大的值。
然后，调用了特化版本的函数模板.

*/