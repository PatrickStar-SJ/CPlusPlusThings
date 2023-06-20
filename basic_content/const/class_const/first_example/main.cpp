#include "apple.h"
#include <iostream>
using namespace std;

int main() {
  Apple a(2);
  cout << a.getCount() << endl;
  a.add(10);
  const Apple b(3);
  b.add(100);
  return 0;
}

/*
take func 1
2
take func 10
take func 100
*/