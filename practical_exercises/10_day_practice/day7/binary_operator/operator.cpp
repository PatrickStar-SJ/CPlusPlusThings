/* 1.类运算符重载.cpp */
//有复数类Complex，利用运算符重载实现复数的加、减、乘、除等复数运算。
#include <iostream>
using namespace std;
class Complex {
private:
  double r, i;

public:
  Complex(double R = 0, double I = 0) : r(R), i(I){};
  Complex operator+(Complex b);
  Complex operator-(Complex b);
  Complex operator*(Complex b);
  Complex operator/(Complex b);
  void display();
};

Complex Complex::operator+(Complex b) { return Complex(r + b.r, i + b.i); }
Complex Complex::operator-(Complex b) { return Complex(r - b.r, i - b.i); }
//求复数相乘的算法
Complex Complex::operator*(Complex b) {
  Complex t;
  t.r = r * b.r - i * b.i;
  t.i = r * b.i + i * b.r;
  return t;
}
//求复数相除的算法
Complex Complex::operator/(Complex b) {
  Complex t;
  double x;
  x = 1 / (b.r * b.r + b.i * b.i);
  t.r = x * (r * b.r + i * b.i);
  t.i = x * (i * b.r - r * b.i);
  return t;
}
void Complex::display() {
  cout << r;
  if (i > 0)
    cout << "+";
  if (i != 0)
    cout << i << "i" << endl;
  //}display();
};

int main(void) {
  Complex c1(1, 2), c2(3, 4), c3, c4, c5, c6;
  Complex a, b(2, 3);
  a = b + 2; //正确
  // a=2+b;       			//错误,编译器无法自动将整数转换为 Complex 类型。
  a.display();
  c3 = c1 + c2;
  c4 = c1 - c2;
  c5 = c1 * c2;
  c6 = c1 / c2;
  c1.display();
  c2.display();
  c3.display();
  c4.display();
  c5.display();
  c6.display();
  
  return 0;
}

/*
可以添加一个构造函数，该构造函数接受一个整数参数，使其能够处理整数与复数对象之间的相加操作。

类中添加定义：
Complex(int real) : r(real), i(0) {}; // 新增的构造函数

main函数中：
a = Complex(2) + b; // 修改为使用复数对象进行相加

*/
