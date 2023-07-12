#include "clock.h"
#include <iostream>
using namespace std;
Clock::Clock(int NewH, int NewM, int NewS) {
  this->Hour = NewH;
  this->Minute = NewM;
  this->Second = NewS;
}
// 拷贝构造函数,如果不加，编译器会自动生成一个拷贝构造函数，因此加不加都可以直接使用。
// 这里实验注释，验证生效：
// Clock::Clock(Clock &c) {
//   this->Hour = c.Hour;
//   this->Minute = c.Minute;
//   this->Second = c.Second;
// }

/*
C++ 编译器会默认生成一个浅拷贝的拷贝构造函数。其函数原型为：

```
类名(const 类名& other);
```

该拷贝构造函数会按照成员变量的定义顺序，将 `other` 对象的每个成员变量的值赋到新对象的对应成员变量上。
需要注意的是，如果对象中有指针等动态分配的内存，浅拷贝可能会导致问题。此时应该手动编写深拷贝的拷贝构造函数来避免问题。
*/


void Clock::SetTime(int NewH, int NewM, int NewS) {
  //加不加this指针都一样
  this->Hour = NewH;
  this->Minute = NewM;
  this->Second = NewS;
}
void Clock::ShowTime() {
  cout << this->Hour << endl;
  cout << this->Minute << endl;
  cout << this->Second << endl;
}
//析构函数
Clock::~Clock() {}
int main(int argc, char const *argv[]) {
  Clock c(0, 0, 0);

  c.SetTime(10, 20, 30);
  c.ShowTime();
  //拷贝构造函数调用
  Clock c1(c);  // 这种用法很值得学习！！！
  c1.ShowTime();
  c1.SetTime(90, 98, 99);
  c1.ShowTime();
  return 0;
}
