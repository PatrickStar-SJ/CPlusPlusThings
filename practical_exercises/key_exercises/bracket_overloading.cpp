/* 中括号重载.cpp */
#include <cstring>
#include <iostream>
using namespace std;
struct Person { //职工基本信息的结构
  double salary;
  char *name;
};
class SalaryManaege {
  Person *employ; //存放职工信息的数组
  int max;        //数组下标上界
  int n;          //数组中的实际职工人数
public:
  SalaryManaege(int Max = 0) {
    max = Max;
    n = 0;
    employ = new Person[max];
  }
  //返回引用特性是可以直接在放在左值，直接使用
  double &operator[](char *Name) { //重载[]，返回引用
    Person *p;
    for (p = employ; p < employ + n; p++)
      //如果存在处理
      if (strcmp(p->name, Name) == 0)
        return p->salary;
    //不存在情况处理
    p = employ + n++;
    p->name = new char[strlen(Name) + 1];
    strcpy(p->name, Name);
    p->salary = 0;
    return p->salary;
  }
  void display() {
    for (int i = 0; i < n; i++)
      cout << employ[i].name << "   " << employ[i].salary << endl;
  }
  ~SalaryManaege() { delete[] employ; }
};
int main() {
  SalaryManaege s(3);
  s["张三"] = 2188.88;
  s["里斯"] = 1230.07;
  s["王无"] = 3200.97;
  cout << "张三\t" << s["张三"] << endl;
  cout << "里斯\t" << s["里斯"] << endl;
  cout << "王无\t" << s["王无"] << endl;

  cout << "-------下为display的输出--------\n\n";
  s.display();
}
/*
在类的构造函数中，将max赋值为传入的参数Max，并初始化n为0。
然后使用new运算符动态分配了一个大小为max的Person结构数组，并将其地址赋给employ指针。


在类中重载了[]运算符，返回引用类型的变量。在重载函数中，首先定义了一个Person类型的指针p，用于遍历数组employ。
然后通过循环判断数组中是否存在与传入的Name相等的姓名，如果存在，则返回该职工的工资。
如果不存在，则将新的职工信息添加到数组中，即将其姓名和工资赋值给p，并进行相应的内存动态分配、字符串复制和成员变量赋值。最后返回该职工的工资。


*/