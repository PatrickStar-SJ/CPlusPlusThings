/* 重载++的时钟.cpp */
/*
设计一个时钟类，能够记录时、分、秒，重载它的++运算符，每执行一次++运算，加时1秒，但要使计时过程能够自动进位。
*/


/*
前置自增操作符表示先执行自增操作，然后再取得该对象的值；
后置自增操作符则表示先取得该对象的值，然后再执行自增操作

重载++或者--，前置后置是不同的写法：
    operator++()是前置，也就是++i，前置的，返回的是左值
    operator++(int)是后置，也就是i++，后置的，返回的是右值。

*/
#include <iostream>
using namespace std;
class Time {
public:
  Time(int h = 0, int m = 0, int s = 0) {
    hour = h;
    minute = m;
    second = s;
  }
  Time operator++();
  Time operator++(int);
  void showTime() {
    cout << "当前时间为：" << hour << ":" << minute << ":" << second << endl;
  }

private:
  int hour, minute, second;
};
//重载后置自增：注意这里的 int 参数 n 是后置自增操作符的特殊要求，因为后置自增操作符需要在函数返回之前保存原来的值，所以需要一个额外的参数来区分前置和后置自增操作。
Time Time::operator++(int n) {
  Time tmp = *this;  //*this代表当前对象本身
  ++(*this);    //注意，这里的++是调用的下面实现的 前置自增运算符函数，而不是传统意义上的++。
  return tmp; //为何这里返回tmp，因为这个函数的功能是后置自增，即先取值，再自增，所以应该返回未自增的tmp ！！！！
}
//重载前置自增
Time Time::operator++() {
  ++second;
  if (second == 60) {
    second = 0;
    ++minute;
    if (minute == 60) {
      minute = 0;
      hour++;
      if (hour == 24) {
        hour = 0;
      }
    }
  }
  return *this;  //*this代表当前对象本身，在这个类成员函数中指代类的对象本身。
}

int main(int argc, char const *argv[]) {
  Time t(23, 59, 59);
  ++t;  //这里是对类的对象进行自增，所以需要重载实现自增运算符。
  t.showTime();
  (t++).showTime();
  t.showTime();
  
  return 0;
}

/*
如果要对类的对象执行自增操作，需要在类中重载自增运算符。自增运算符有两种形式：前缀自增和后缀自增。前缀自增返回自增后的值，后缀自增返回自增前的值。以下是示例代码：

```c++
class MyClass{
public:
    int value;
    
    MyClass(int v):value(v){}  //使用初始化列表将v的值赋给value变量，以初始化这个类对象的value成员。
    
    // 前缀自增
    MyClass& operator ++(){
        ++value;
        return *this;
    }
    
    // 后缀自增
    MyClass operator ++(int){
        MyClass tmp(*this);
        ++value;
        return tmp;
    }
};

int main(){
    MyClass obj(10);
    
    // 前缀自增
    ++obj;
    std::cout << obj.value << std::endl; // 输出11
    
    // 后缀自增
    obj++;
    std::cout << obj.value << std::endl; // 输出12
    
    return 0;
}
```

在上面的代码中，通过重载 `operator++` 函数来实现自增操作。其中，前缀自增返回当前对象的引用，后缀自增返回自增前的值的拷贝。在主函数中，可以执行前缀自增和后缀自增操作，并且输出结果。
*/

