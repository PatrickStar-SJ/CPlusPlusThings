#pragma once

class Apple {
public:
  Apple(int i);
  // 使用c++11标准编译
  static const int apple_number = 10;
  // const int apple_number=10;
  void take(int num) const;  //const在后面表示该成员函数是一个常量成员函数，该函数不能修改成员变量的值，只能读取成员变量的值。即该函数对对象是只读的，无法改变对象的状态。
  int add(int num);
  int add();
  int add(int num) const;
  int getCount() const;
};
