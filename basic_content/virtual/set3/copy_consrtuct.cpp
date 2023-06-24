#include <iostream>
using namespace std;

class Base {
public:
};

class Derived : public Base {
public:
  Derived() { cout << "Derived created" << endl; }

  Derived(const Derived &rhs) {
    cout << "Derived created by deep copy" << endl;
  }

  ~Derived() { cout << "Derived destroyed" << endl; }
};

int main() {
  Derived s1;

  // 编译器会调用Derived类 "拷贝构造函数"，将s1的值"深拷贝"到s2中。

  // 如果Derived类没有自定义的拷贝构造函数，那么编译器会提供一个默认的拷贝构造函数，
  // 实现浅拷贝，只会将s1中的值复制给s2，导致两个变量指向同一内存地址。
  Derived s2 = s1; 

  return 0;
}

//当创建一个类的对象时，立即调用构造函数来初始化对象。


/*
Derived created
Derived created by deep copy
Derived destroyed
Derived destroyed
*/