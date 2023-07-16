/* 抽象类.cpp */
#include <iostream>
using namespace std;

/*

抽象类：
包含一个或多个纯虚函数的类
*/
class Figure {
protected:
  double x, y;

public:
  void set(double i, double j) {
    x = i;
    y = j;
  }
  virtual void area() = 0;
};

class Trianle : public Figure {
public:
  void area() { cout << "三角形面积：" << x * y * 0.5 << endl; }
};
class Rectangle : public Figure {
public:
  void area() { cout << "这是矩形，它的面积是：" << x * y << endl; }
};

int main(int argc, char const *argv[]) {
  //定义抽象类指针
  Figure *pF = NULL;
  // Figure f1; 抽象类不能被实例化  
  //==>  抽象类中含有纯虚函数，由于纯虚函数没有实现代码，所以不能建立抽象类的对象。
  /*
  只是声明了一个指向Figure类的指针变量pF，并将其初始化为NULL。
  这并不会创建Figure类的对象，而只是创建了一个指针变量，可以在后续的代码中用于指向Figure类的派生类的对象。
  */

  Rectangle r;
  Trianle t;
  t.set(10, 20);
  pF = &t;
  pF->area();
  r.set(10, 20);
  pF = &r;
  pF->area();
  
  //定义抽象类引用
  Figure &rF = t;
  rF.set(20, 20);
  rF.area();
  
  return 0;
}
