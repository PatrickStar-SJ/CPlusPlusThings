/**
 * @file copy_construct.cpp
 * @brief g++ -o copy_construct copy_construct.cpp -fno-elide-constructors
 * -fno-elide-constructors选项(关闭返回值优化)
 * @author 光城
 * @version v1
 * @date 2019-08-09
 */

#include <iostream>
using namespace std;

class Copyable {
public:
  Copyable() {}
  Copyable(const Copyable &o) { cout << "Copied" << endl; }
};
Copyable ReturnRvalue() {  //表示该函数返回一个 Copyable 类型的临时对象。
  return Copyable(); // 返回一个临时对象
}
void AcceptVal(Copyable a) {}
void AcceptRef(const Copyable &a) {}

int main() {
  cout << "pass by value: " << endl;
  //AcceptVal(ReturnRvalue())调用两次拷贝构造函数的原因是，返回的临时对象会被拷贝到AcceptVal函数的参数a中，这就是第一次拷贝构造函数的调用。然后，参数a会被拷贝到AcceptVal函数内部的局部变量中，这就是第二次拷贝构造函数的调用。
  AcceptVal(ReturnRvalue()); // 应该调用两次拷贝构造函数

  cout << "pass by reference: " << endl;
  //AcceptRef(ReturnRvalue())只调用一次拷贝构造函数的原因是，返回的临时对象直接被AcceptRef函数的参数a引用，没有发生拷贝操作。因此，只有一次拷贝构造函数的调用。
  AcceptRef(ReturnRvalue()); // 应该只调用一次拷贝构造函数
}
