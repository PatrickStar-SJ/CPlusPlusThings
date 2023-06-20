#include <iostream>
using namespace std;

int main() {
  const int p = 10;
  const void *vp = &p;
  void *vp = &p; // error，将一个const对象的地址转换为void*类型的指针，
}
