/* 重载[]运算符 */
// Eg8-9.cpp
#include <cstring>
#include <iostream>
using namespace std;

/*
这段代码定义了一个名为Person的结构体，用于存储职工的基本信息，包括薪水和姓名。

接下来定义了一个名为SalaryManaege的类，用于管理职工的薪水信息。
该类包含了一个指向Person结构体的指针employ，用于存放职工信息的数组；
一个整型变量max，表示数组的上界；一个整型变量n，表示数组中的实际职工人数。


重载了[]运算符，使得可以通过职工的姓名来访问其薪水信息。在重载函数中，首先遍历employ数组，查找是否存在姓名为Name的职工。
如果找到了，则返回该职工的薪水的引用；如果没有找到，则将该职工添加到数组中，并将其薪水初始化为0。
*/

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
};
int main() {
  SalaryManaege s(3);
  // 下面6行都会调用重载的[]
  s["张三"] = 2188.88;
  s["里斯"] = 1230.07;
  s["王无"] = 3200.97;
  cout << "张三\t" << s["张三"] << endl;
  cout << "里斯\t" << s["里斯"] << endl;
  cout << "王无\t" << s["王无"] << endl;

  cout << "-------下为display的输出--------\n\n";
  s.display();
  
}
