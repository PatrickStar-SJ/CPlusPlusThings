#include <iostream>
using namespace std;
/*
若一个类为另一个类的友元，则此类的所有成员都能访问对方类的私有成员。
声明语法：将友元类名在另一个类中使用friend修饰说明。
*/

/*
如果声明B类是A类的友元，B类的成员函数就可以访问A类的私有和保护数据，
但A类的成员函数却不能访问B类的私有、保护数据。
*/
class A {
  friend class B;

public:
  void Display() { cout << x << endl; }

private:
  int x;
};
class B {
public:
  void Set(int i);
  void Display();

private:
  A a;
};
void B::Set(int i) { a.x = i; }
void B::Display() { a.Display(); } // 使用 A类的Display函数来定义 B类的Display函数

int main(int argc, char const *argv[]) {
  B b;
  b.Set(10);
  b.Display();

  
  return 0;
}

/*
如果声明B类是A类的友元，B类的成员函数就可以访问A类的私有和保护数据，但A类的成员函数却不能访问B类的私有、保护数据
*/

/*
类B中有一个私有成员变量a，其类型为类A。在类B的成员函数Set()中，通过 a.x = i; 对a中的私有成员变量x进行了赋值。在类B的成员函数Display()中，通过 a.Display(); 调用了a中的成员函数Display()，输出了a中的私有成员变量x的值。因为类B是类A的友元类，所以在类B的成员函数中可以直接访问类A的私有成员变量和成员函数。在main函数中，首先创建了一个类B的对象b，然后调用b的成员函数Set()给a中的私有成员变量x赋值为10，最后调用b的成员函数Display()输出a中的私有成员变量x的值。
*/