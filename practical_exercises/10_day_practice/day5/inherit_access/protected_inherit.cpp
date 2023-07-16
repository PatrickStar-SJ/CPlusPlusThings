/*
派生方式为protected的继承称为保护继承，在这种继承方式下，
基类的public成员在派生类中会变成protected成员，
基类的protected和private成员在派生类中保持原来的访问权限
*/
#include <iostream>
using namespace std;
class Base {
  int x;

protected:
  int getx() { return x; }

public:
  void setx(int n) { x = n; }
  void showx() { cout << x << endl; }
};
class Derived : protected Base {
  int y;

public:
  void sety(int n) { y = n; }
  void sety() { y = getx(); } //访问基类的保护成员
  void showy() { cout << y << endl; }
};
int main() {
  Derived obj;
  obj.setx(10); //错误
  obj.sety(20);
  obj.showx(); //错误，
  obj.showy();
  
}


/*
在给定的代码中，Derived类继承自Base类，并使用protected继承。这意味着Base类的公有成员在Derived类中变为保护成员，私有成员仍然是私有的，而保护成员在Derived类中可以直接访问。

在主函数中，创建了Derived类的对象obj。然后尝试调用obj的成员函数setx(10)，但是由于Base类的setx()函数是公有成员，而在Derived类中是保护成员，因此无法在"主函数"中直接访问。

接下来，调用obj的成员函数sety(20)，将参数20赋值给Derived类的私有成员y。

最后，调用obj的成员函数showy()，输出Derived类的私有成员y的值20。
因此，代码的执行结果是： 20

*/

/*
解释：
如最上面文字所示：保护继承会将基类的public变为protected，而对于protected成员，
外部去使用保护成员的时候，会报错，所以setx与showx访问错误，而对于派生类，则可直接访问基类的保护成员，
在派生类中，y=getx()可正常访问！
*/