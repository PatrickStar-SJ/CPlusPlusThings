/* 重载圆括号的时钟.cpp */
#include <iostream>
using namespace std;
class Time {
private:
  int hh, mm, ss;

public:
  Time(int h = 0, int m = 0, int s = 0) : hh(h), mm(m), ss(s) {}
  void operator()(int h, int m, int s) {
    hh = h;
    mm = m;
    ss = s;
  }
  void ShowTime() { cout << hh << ":" << mm << ":" << ss << endl; }
};
int main() {
  Time t1(12, 10, 11);
  t1.ShowTime();
  t1.operator()(23, 20, 34);
  t1.ShowTime();
  t1(10, 10, 10);
  t1.ShowTime();
  
}
/*
通过重载函数调用运算符，我们可以将Time对象使用函数调用的方式来修改其成员变量的值。

通过显示地调用t1的成员函数operator()，分别传递了新的时间值，这样就将t1对象的时间修改为了(23, 20, 34)。

通过重载函数调用运算符，我们可以使对象的行为更加灵活和方便，可以将对象当作函数来使用，这种语法糖在一些情况下会提高代码的可读性和简洁性。
*/