/* 计数器前后自增.cpp */
//设计一个计数器counter，用类成员重载自增运算符实现计数器的自增，用友元重载实现计数器的自减。
#include <iostream>
using namespace std;
class Counter {
private:
  int n;

public:
  Counter(int i = 0) : n(i){};
  Counter operator++();    //需要使用Counter作为返回类型或参数类型，是因为递增和递减操作是针对Counter类的对象进行的。
  Counter operator++(int);
  friend Counter operator--(Counter &c);
  friend Counter operator--(Counter &c, int);
  void display();
};
Counter Counter::operator++() {   //使用两个Counter对象的原因是因为递增和递减操作涉及到两个对象之间的运算。
                                  // 前置递增运算符operator++()用于将计数器的值加1，并返回递增后的计数器对象。
  ++n;
  return *this;
}
Counter Counter::operator++(int) {  //后置递增运算符operator++(int)也是将计数器的值加1，但返回的是递增前的计数器对象。
  Counter t = *this;
  n++;
  return t;
}
Counter operator--(Counter &c) {  // 前置递减运算符operator--(Counter &c)用于将计数器的值减1，并返回递减后的计数器对象。
  --c.n;
  return c;
}
Counter operator--(Counter& c, int) {  //后置递减运算符operator--(Counter &c, int)也是将计数器的值减1，但返回的是递减前的计数器对象。
    Counter t(c.n);
    c.n--;
    return t;
}
void Counter::display() { cout << "counter number=" << n << endl; }
int main(int argc, char const *argv[]) {
  Counter a;
  ++a;
  a.display();
  a++;
  a.display();
  --a;
  a.display();
  a--;
  a.display();
  
  return 0;
}
