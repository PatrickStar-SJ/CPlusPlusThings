#include <iostream>
using namespace std;

/*

**派生类只能采用构造函数初始化列表的方式向基类或成员对象的构造函数传递参数**，形式如下：

派生类构造函数名(参数表):基类构造函数名(参数表),成员对象名1(参数表),…{
    //……
}
*/

class Base {
private:
  int x;

public:
  Base(int a) {
    x = a;
    cout << "Base constructor x=" << x << endl;
  }
  ~Base() { cout << "Base destructor..." << endl; }
};
class Derived : public Base {
private:
  int y;

public:
  Derived(int a, int b) : Base(a) { //派生类构造函数的初始化列表
    y = b;
    cout << "Derived constructor y=" << y << endl;
  }
  ~Derived() { cout << "Derived destructor..." << endl; }
};
int main() {
  Derived d(1, 2);
  
  return 0;
}