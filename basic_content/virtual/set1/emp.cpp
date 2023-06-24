#include <iostream>
using namespace std;

class Employee {
public:
  virtual void raiseSalary() { cout << 0 << endl; }

  virtual void promote() { /* common promote code */
  }
};

class Manager : public Employee {
  virtual void raiseSalary() { cout << 100 << endl; }

  virtual void promote() { /* Manager specific promote */
  }
};
class Engineer : public Employee {
  virtual void raiseSalary() { cout << 200 << endl; }

  virtual void promote() { /* Manager specific promote */
  }
};

//同样地，可能还有其他类型的员工。我们需要一个非常简单的函数来增加所有员工的薪水。
//注意，emp[] 是一个指针数组，指向的实际对象可以是任何类型的员工。
//这个函数理想情况下应该在一个类（如 Organization）中，但为了简单起见，我们将其设为全局函数。
void globalRaiseSalary(Employee *emp[], int n) {
  for (int i = 0; i < n; i++)
    emp[i]->raiseSalary(); //多态调用：调用raiseSalary()的实际对象，而不是指针类型。
}
int main() {
  //定义了一个包含两个元素的指针数组emp，第一个元素是Manager类型的对象指针，第二个元素是Engineer类型的对象指针。
  //这些对象都是从Employee类派生而来的，因此它们都可以被视为Employee类型的对象，从而可以存储在Employee类型的指针数组中。
  Employee *emp[] = {new Manager(), new Engineer};  
  globalRaiseSalary(emp, 2);
  return 0;
}


//100
//200