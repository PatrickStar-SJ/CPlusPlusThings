#include "apple.h"
#include <iostream>

using namespace std;
Apple::Apple(int i) {}
int Apple::add(int num) {
  take(num);
  return 0;
}
int Apple::add(int num) const {
  take(num);
  return 0;
}
void Apple::take(int num) const { cout << "take func " << num << endl; }
int Apple::getCount() const {
  take(1);
  //    add(); //error    const成员函数只能访问const成员函数。
  return apple_number;
}