#include "apple.h"
#include <iostream>
using namespace std;
int main() {
  Apple a(2);
  cout << a.getCount() << endl;
  a.add(10);
  const Apple b(3); //const对象只能访问const成员函数,而非const对象可以访问任意的成员函数,包括const成员函数.
  b.add(100);
  return 0;
}


/*
take func 1
10
take func 10
take func 100
*/