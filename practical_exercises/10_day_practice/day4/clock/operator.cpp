/* 重载()的时钟.cpp */
#include <iostream>
using namespace std;
class Time {
private:
  int hh, mm, ss;

public:
  Time(int h = 0, int m = 0, int s = 0) : hh(h), mm(m), ss(s) {} //列表初始化多个变量
   
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
  t1.operator()(23, 20, 34); //通过对象t1调用重载运算符()，可以修改t1的时间属性
  t1.ShowTime();
  t1(10, 10, 10);
  t1.ShowTime();
  
}
/*
重载了函数调用运算符(),通过这个运算符重载，可以将对象像函数一样调用，并且可以传递参数来修改对象的属性。
在这个例子中，Time类重载了()运算符，使得可以通过对象名称后跟括号和参数列表来改变对象的状态，即修改hh，mm，ss属性的值。
*/
