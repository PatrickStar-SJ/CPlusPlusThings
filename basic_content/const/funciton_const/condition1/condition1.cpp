#include <iostream>
using namespace std;

int main() {
  const int *ptr;
  *ptr = 10; // error ，const 在* 的左侧，指针修饰的变量是常量，因此不能修改
}
