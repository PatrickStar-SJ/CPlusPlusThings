/* 运算符重载之强制转换.cpp */
/*
有一个类Circle，设计该类的类型转换函数，当将Circle对象转换成int型时，返回圆的半径；
当将它转换成double型时，就返回圆的周长；当将它转换成float型时，就返回圆的面积。
*/

/*

类型转换函数没有参数。
类型转换函数没有返回类型。
类型转换函数必须返回将要转换成的type类型数据。

*/

#include <iostream>
using namespace std;
class Circle {
private:
  double x, y, r;

public:
  Circle(double x1, double y1, double r1) {
    x = x1;
    y = y1;
    r = r1;
  }
  operator int() { return int(r); }
  operator double() { return 2 * 3.14 * r; }
  operator float() { return (float)3.14 * r * r; }
};
int main() {
  Circle c(2.3, 3.4, 2.5);
  int r = c;         //调用operator int()，将Circle类型转换成int
  double length = c; //调用operator double()，转换成double
  float area = c;    //调用operator float()，将Circle类型转换成float
  double len = (double)c; //将Cirlce类型对象强制转换成double
  cout << r << endl;
  cout << length << endl;
  cout << len << endl;
  cout << area << endl;
  
}
/*
上面定义的三个类型转换函数 operator xxx 是通过重载类型转换运算符来实现的。
在C++中，可以通过重载类型转换运算符来定义自定义类型到其他类型的转换规则。

当我们使用Circle对象进行赋值操作时，编译器会自动调用对应的类型转换函数来进行转换。

当我们将Circle对象赋值给int类型的变量r时，编译器会自动调用operator int()函数来将Circle对象转换为int类型，返回圆的半径。

类似地，当我们将Circle对象赋值给double类型的变量length时，编译器会自动调用operator double()函数来将Circle对象转换为double类型，返回圆的周长。

同样地，当我们将Circle对象赋值给float类型的变量area时，编译器会自动调用operator float()函数来将Circle对象转换为float类型，返回圆的面积。
*/