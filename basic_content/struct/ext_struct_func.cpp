#include <iostream>
#include <stdio.h>
using namespace std;
struct Base {
  int v1;
  //    private:   //error!
  int v3;

public: // 显示声明public
  int v2;
  virtual void print() { printf("%s\n", "Base"); };
  Base() { cout << "Base construct" << endl; };
  virtual ~Base() { cout << "Base deconstruct" << endl; };
};

struct Derived : Base {

  Derived() { cout << "Derived construct" << endl; };
  virtual ~Derived() { cout << "Derived deconstruct" << endl; };

public:
  int v2;
  void print() { printf("%s\n", "Derived"); };
};

int main() {
  Base *b = new Derived();
  b->print();
  delete b;
  return 0;
}
/*
本文件后缀是".cpp"

c++中的结构体：
1. C++结构体中不仅可以定义数据，还可以定义函数
2. C++结构体中可以使用访问修饰符，如：public、protected、private 。
3. 结构体使用可以直接使用, 不带struct。
4. 若结构体的名字与函数名相同，可以正常运行且正常的调用！
5. 定义结构体变量时需要显式地在其前面加上struct关键字，因为C++中既支持结构体又支持类，加上struct关键字，以区分是使用结构体类型还是类类型。

*/