/**
 * @file vir_con.cpp
 * @brief
 * 构造函数不可以声明为虚函数。同时除了inline之外，构造函数不允许使用其它任何关键字。
 *
 * 为什么构造函数不可以为虚函数？
 *
 * 尽管虚函数表vtable是在编译阶段就已经建立的，但指向虚函数表的指针vptr是在运行阶段实例化对象时才产生的。
 * 如果类含有虚函数，编译器会在构造函数中添加代码来创建vptr。
 * 问题来了，如果构造函数是虚的，那么它需要vptr来访问vtable，可这个时候vptr还没产生。
 * 因此，构造函数不可以为虚函数。
 * 我们之所以使用虚函数，是因为需要在信息不全的情况下进行多态运行。而构造函数是用来初始化实例的，实例的类型必须是明确的。
 * 因此，构造函数没有必要被声明为虚函数。
 * 尽管构造函数不可以为虚函数，但是有些场景下我们确实需要 “Virtual Copy
 * Constructor”。
 * “虚复制构造函数”的说法并不严谨，其只是一个实现了对象复制的功能的类内函数。
 * 举一个应用场景，比如剪切板功能。
 * 复制内容作为基类，但派生类可能包含文字、图片、视频等等。
 * 我们只有在程序运行的时候才知道我们需要复制的具体是什么类型的数据。
 *
 * @author 光城
 * @version v1
 * @date 2019-07-24
 */

#include <iostream>
using namespace std;

//// LIBRARY SRART
class Base {
public:
  Base() {}

  virtual //  确保调用实际对象的析构函数
      ~Base() {}

  virtual void ChangeAttributes() = 0;

  // The "Virtual Constructor"，定义函数，下面有实现
  static Base *Create(int id);

  // The "Virtual Copy Constructor"
  virtual Base *Clone() = 0;
};

class Derived1 : public Base {
public:
  Derived1() { cout << "Derived1 created" << endl; }

  Derived1(const Derived1 &rhs) {
    cout << "Derived1 created by deep copy" << endl;
  }

  ~Derived1() { cout << "~Derived1 destroyed" << endl; }

  void ChangeAttributes() { cout << "Derived1 Attributes Changed" << endl; }

  Base *Clone() { return new Derived1(*this); }
};

class Derived2 : public Base {
public:
  Derived2() { cout << "Derived2 created" << endl; }

  Derived2(const Derived2 &rhs) {
    cout << "Derived2 created by deep copy" << endl;
  }

  ~Derived2() { cout << "~Derived2 destroyed" << endl; }

  void ChangeAttributes() { cout << "Derived2 Attributes Changed" << endl; }

  Base *Clone() { return new Derived2(*this); }
};

class Derived3 : public Base {
public:
  Derived3() { cout << "Derived3 created" << endl; }

  Derived3(const Derived3 &rhs) {
    cout << "Derived3 created by deep copy" << endl;
  }

  ~Derived3() { cout << "~Derived3 destroyed" << endl; }

  void ChangeAttributes() { cout << "Derived3 Attributes Changed" << endl; }

  Base *Clone() { return new Derived3(*this); }
};

// 实现Base类的creat()函数。我们还可以在 Base 外部声明 "Create"
// 但将其范围限制在 Base 中更为相关
Base *Base::Create(int id) {
  // 如果创建了新的 Derived 类，只需扩展 if-else 阶梯即可
  // 用户不需要重新编译就可以创建新添加的类对象

  if (id == 1) {
    return new Derived1;
  } else if (id == 2) {
    return new Derived2;
  } else {
    return new Derived3;
  }
}
//// LIBRARY END

//// UTILITY SRART
class User {
public:
  User() : pBase(0) {  //成员初始化列表, 0被赋值给了pBase，即初始化为一个空指针
    //  在运行时创建 Base 继承结构中的任何对象

    int input;

    cout << "Enter ID (1, 2 or 3): ";
    cin >> input;

    while ((input != 1) && (input != 2) && (input != 3)) {
      cout << "Enter ID (1, 2 or 3 only): ";
      cin >> input;
    }

    // 通过 "虚拟构造函数" 创建对象
    pBase = Base::Create(input);
  }

  ~User() {
    if (pBase) {
      delete pBase;
      pBase = 0;
    }
  }

  void Action() {
    // 复制当前对象
    Base *pNewBase = pBase->Clone();

    // Change its attributes
    pNewBase->ChangeAttributes();

    // 释放创建的对象
    delete pNewBase;
  }

private:
  Base *pBase;
};

//// UTILITY END

//// Consumer of User (UTILITY) class
int main() {
  User *user = new User();

  user->Action();

  delete user;
}


/*
该程序定义类可一个抽象基类Base，包括一个纯虚函数ChangeAttributes(),它必须在所有派生类中实现。
同时，还定义了两个函数：`Create()`和`Clone()`。其中，`Create()`函数作为静态函数，实现了 "虚拟构造函数"的功能
它返回一个指向基类对象的指针。根据不同的 `id` 值，`Create()` 函数可以实例化三个不同的派生类对象。
`Clone()` 函数作为虚函数，实现了"虚拟复制构造函数"的功能，使用该函数可以创建当前对象的克隆。在所有派生类中都必须实现 `Clone()` 函数。

拷贝构造函数：
Derived1(const Derived1 &rhs)
Derived2(const Derived2 &rhs)
Derived3(const Derived3 &rhs)

代码执行逻辑如下：
1. 用户类 `User` 创建了一个 `Base` 对象的指针 `pBase`
2. 调用user类的构造函数，使用初始化列表，将 0赋值给pBase指针(即为空指针)
3. 通过输入对应的id，对应创建派生类的对象，并将其地址赋值给pBase。（由此，Base类的对象指针pBase指向派生类对象）
4. 执行Action()函数，创建了一个指针pNewBase,它指向 pBase->Clone();然后调用pNewBase的成员函数ChangeAttributes().再释放pNewBase指向的对象。
5. 最后调用 User类的析构函数，包括释放Base指向的对象，并将pBase置为0；


为何Base类的对象指针pBase可以指向派生类对象？
因为继承机制，允许派生类继承基类的公有成员，于是基类类型的指针，可以指向派生类类型的对象。

为何删除指针后，要赋值0？
如果不对其赋值0，会使他成为野指针，即指向一个无效的内存地址。当指针被赋值0之后，表示该指针不指向任何有效内存地址，类似空指针。
空指针，是指向nullptr（空地址），通常被用作指针未初始化的默认值，或者表示指针不指向有效的内存地址。在实际编程中，使用空指针会更加安全和规范。


指向结果：
Enter ID (1, 2 or 3): 1
Derived1 created
Derived1 created by deep copy
Derived1 Attributes Changed
~Derived1 destroyed
~Derived1 destroyed
*/