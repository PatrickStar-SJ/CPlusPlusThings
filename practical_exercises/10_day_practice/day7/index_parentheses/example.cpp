/* []与() 运算符重载 */
#include <iostream>
using namespace std;
class X {
public: 
  int operator()(int i = 0) {  //定义了一个重载了函数调用运算符的成员函数，接受一个整型参数i，默认值为0。
    cout << "X::operator(" << i << ")" << endl;
    return i;
  };
  int operator()(int i, int j) { //定义了另一个重载了函数调用运算符的成员函数，接受两个整型参数i和j。
    cout << "X::operator(" << i << "," << j << ")" << endl;
    return i;
  };
  int operator[](int i) {  //定义了一个重载了下标运算符的成员函数，接受一个整型参数i。
    cout << "X::operator[" << i << "]" << endl;
    return i;
  };
  int operator[](char *cp) { //定义了另一个重载了下标运算符的成员函数，接受一个字符指针参数cp。
    cout << "X::operator[" << cp << "]" << endl;
    return 0;
  };
};
int main(void) {
  X obj;
  int i = obj(obj(1), 2);
  int a = obj[i];
  int b = obj["abcd"];
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;
}
/*
int b = obj["abcd"]; 和 int b = obj[]("abcd"); 是不等价的。
在这个代码中，obj["abcd"] 调用了成员函数 operator[](char *cp)，并传递了一个字符指针参数"abcd"。这个成员函数内部输出了一段字符串，并返回0。
而 obj[]("abcd") 则是先调用了成员函数 operator[]，并传递了一个空参数。然后再调用返回的结果，即 operator()("abcd")，传递了一个字符指针参数"abcd"。这个成员函数内部输出了一段字符串，并返回参数i的值。
因此，这两个语句调用的是不同的成员函数，执行的操作也不同，所以它们是不等价的。



*/