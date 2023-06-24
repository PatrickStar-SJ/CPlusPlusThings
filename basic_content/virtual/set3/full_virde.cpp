/**
 * @file full_virde.cpp
 * @brief 将基类的析构函数声明为虚函数
 * 输出结果：
 *      Constructing base
 *      Constructing derived
 *      Destructing derived
 *      Destructing base
 * @author 光城
 * @version v1
 * @date 2019-07-24
 */
#include <iostream>

using namespace std;

class base {
public:
  base() { cout << "Constructing base \n"; }
  virtual ~base() { cout << "Destructing base \n"; }  //析构函数被声明为虚函数
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
析构函数可以被声明为虚函数。
如果我们需要删除一个指向派生类的基类指针时，应该把析构函数声明为虚函数。 
事实上，只要一个类有可能会被其它类所继承， 就应该声明虚析构函数(哪怕该析构函数不执行任何操作)。

执行结果：
Constructing base 
Constructing derived 
Destructing derived 
Destructing base 
*/