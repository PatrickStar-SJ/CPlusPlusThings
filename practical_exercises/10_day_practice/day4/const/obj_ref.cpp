
#include <iostream>
using namespace std;
void display(const double &r);

class A {
public:
  A(int i, int j) {
    x = i;
    y = j;
  }
  void print() const;
private:
  int x, y;
};

//实例化也需要带上 const
void A::print() const {
    cout << "常 对象调用" << endl;
    cout << x << ";" << y << endl;
}
int main() {
    double d(9.5);
    display(d);
    A const a(3, 4); // a是常对象，不能被更新
    a.print();  //调用常成员函数。这里不能直接a.x  a.y，因为 x和y都是私有成员变量。

    //如果x y都是公有成员，就可以这样打印了。
    //cout<<a.x<<"  "<<a.y<<endl;
    return 0;
}
void display(const double &r)
//常引用做形参，在函数中不能更新 r所引用的对象。
{
  cout << r << endl;
}
