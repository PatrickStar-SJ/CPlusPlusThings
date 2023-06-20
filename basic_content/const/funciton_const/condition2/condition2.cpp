#include <iostream>
using namespace std;
int main() {
  const int num = 1;
  // int *const ptr = &num; // error! const int* -> int*。 const在指针右边，所以指针本身是常量，不能修改，但是指向的值可以修改。而&num是指向常量的指针，指向的值不可以修改。
   const int *const ptr=&num; //ok
  cout << *ptr << endl;
}
