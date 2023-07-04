/* 联合体学习.cpp */
#include <iostream>
using namespace std;
//相同的内存地址
union myun {
  struct {
    int x;
    int y;
    int z;
  } u;
  int k;
} a;
int main() {
  a.u.x = 4;
  a.u.y = 5;
  a.u.z = 6;
  a.k = 0; //会覆盖掉第一个int空间值
  printf("%d %d %d %d\n", a.u.x, a.u.y, a.u.z, a.k);
  //a.u.x最终变成了0的原因是因为联合体中的所有成员共享同一块内存空间。
  //当你执行a.k = 0;时，它会覆盖掉联合体中第一个整型成员的值，也就是a.u.x。
  //如果要修改y,z则需要使用对a.u.y和a.u.z重新赋值。
  
  return 0;
}