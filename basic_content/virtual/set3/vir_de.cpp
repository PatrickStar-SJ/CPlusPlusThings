/**
 * @file vir_de.cpp
 * @brief 派生类的析构函数没有被调用!
 * 输出结果：
 *      Constructing base
 *      Constructing derived
 *      Destructing base
 * @author 光城
 * @version v1
 * @date 2019-07-24
 */

// CPP program without virtual destructor
// causing undefined behavior
#include <iostream>

using namespace std;

class base {
public:
  base() { cout << "Constructing base \n"; }
  ~base() { cout << "Destructing base \n"; }   //相比full_virde.cpp 这里的析构函数没有被声明为虚函数
};

class derived : public base {
public:
  derived() { cout << "Constructing derived \n"; }
  ~derived() { cout << "Destructing derived \n"; }
};

int main(void) {
  derived *d = new derived();
  base *b = d;
  delete b;
  return 0;
}

/*
为何执行过程没有调用派生类的析构函数？
因为基类的析构函数没有被声明为虚函数，所以在使用基类指针指向派生类对象时，delete只会调用基类的析构函数。
因此派生类的析构函数没有被自动调用。


执行结果：
Constructing base 
Constructing derived 
Destructing base 
*/