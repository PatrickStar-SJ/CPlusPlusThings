/* =运算符重载.cpp */
//例题ch.cppi
#include <iostream>
using namespace std;
class X {
public:
  X &operator=(const X &x) {  //返回类型为X的引用，参数为一个常量引用x，表示函数重载了赋值运算符。
                              // 如果是 X operator...  返回一个新的X对象，表示赋值后的结果。这种情况下，赋值操作会创建一个新的X对象，并将x的值复制给新对象。
                              // 如果是 X &operator... 返回当前对象的引用，即*this。这种情况下，赋值操作会创建一个新的X对象，并将x的值复制给新对象。
    cout << "a:";
    return *this;   //返回当前对象的引用。
  };
};
int main() {
  X obj1, obj2, obj3;
  obj1 = obj2;          //调用重载“=”
  obj1.operator=(obj2); //调用重载“=”
  obj1 = obj2 = obj3;   //调用重载“=”
  
}
