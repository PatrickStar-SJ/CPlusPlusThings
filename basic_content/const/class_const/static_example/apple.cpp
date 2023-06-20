#include "apple.h"
#include <iostream>

const int Apple::apple_number = 10;  //static静态成员变量不能在类的内部初始化。在类的内部只是声明，定义必须在类定义体的外部
int Apple::ap = 666;  //static静态成员变量不能在类的内部初始化。在类的内部只是声明，定义必须在类定义体的外部
Apple::Apple(int i) {}
int Apple::add(int num) {
  take(num);
  return 0;
}
int Apple::add(int num) const {
  take(num);
  return 0;
}
void Apple::take(int num) const {
  std::cout << "take func " << num << std::endl;
}
int Apple::getCount() const {
  take(1);
  //    add(); //error
  return apple_number;
}