#include <iostream>
using namespace std;

int main() {
  const int *ptr;
  int val = 3;
  ptr = &val; // ok  允许将非const对象的地址赋值给指向const对象的指针
  int *ptr1 = &val;
  *ptr1 = 4;
  cout << *ptr << endl;
}
