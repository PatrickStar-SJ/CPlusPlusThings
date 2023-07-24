// Eg10-10.cpp
#include <iostream>
using namespace std;
const int MAX = 3;
class Full {};  // L1  堆栈满时抛出的异常类
class Empty {}; // L2  堆栈空时抛出的异常类
class Stack {
private:
  int s[MAX];
  int top;

public:
  void push(int a);
  int pop();
  Stack() { top = -1; }
};
void Stack::push(int a) {
  if (top >= MAX - 1)
    throw Full();
  s[++top] = a;
}
int Stack::pop() {
  if (top < 0)
    throw Empty();
  return s[top--];
}
int main() {
  Stack s;
  try {
    s.push(10);
    s.push(20);
    s.push(30);
    // s.push(40);	//L5  将产生栈满异常
    cout << "stack(0)= " << s.pop() << endl;
    cout << "stack(1)= " << s.pop() << endl;
    cout << "stack(2)= " << s.pop() << endl;
    cout << "stack(3)= " << s.pop() << endl; // L6
  } catch (Full) {
    cout << "Exception: Stack Full" << endl;
  } catch (Empty) {
    cout << "Exception: Stack Empty" << endl;
  }
  
  return 0;
}
/*
这段代码使用了一个名为Stack的类来实现一个简单的堆栈数据结构。主要包含以下几个部分：

定义了两个异常类Full和Empty，分别用于表示堆栈满和堆栈空的异常情况。
Stack类中包含一个私有成员变量s[MAX]，用于存储堆栈元素，以及一个top变量表示栈顶位置。
Stack类中定义了push()和pop()两个成员函数，分别用于将元素压入堆栈和弹出堆栈顶部的元素。
在构造函数Stack()中，将top初始化为-1，表示堆栈为空。
在主函数main()中，创建了一个Stack对象s。
在try块中，调用s.push()将三个元素压入堆栈，并依次调用s.pop()弹出堆栈中的元素。
当堆栈满时，将抛出Full异常，当堆栈空时，将抛出Empty异常。
在catch块中，根据捕获到的异常类型输出相应的异常信息。
代码的执行流程如下：

创建一个Stack对象s。
调用s.push(10)，将10压入堆栈。
调用s.push(20)，将20压入堆栈。
调用s.push(30)，将30压入堆栈。
调用s.pop()弹出堆栈顶部的元素，输出"stack(0)= 30"。
调用s.pop()弹出堆栈顶部的元素，输出"stack(1)= 20"。
调用s.pop()弹出堆栈顶部的元素，输出"stack(2)= 10"。
调用s.pop()弹出堆栈顶部的元素，由于堆栈已空，抛出Empty异常，捕获并输出"Exception: Stack Empty"。
注意：

在L5处，如果取消注释s.push(40)，将会导致栈满，抛出Full异常，捕获并输出"Exception: Stack Full"。
在L6处，调用s.pop()时，由于堆栈已空，抛出Empty异常，捕获并输出"Exception: Stack Empty"。




在这段代码中，Full和Empty类被用作异常类型，用于catch块来捕获相应的异常。尽管在代码中并没有显式定义这两个类，但它们是可以使用的。
在C++中，可以使用任何类型作为异常类型，包括自定义的类类型。当抛出异常时，可以将异常对象抛出并被捕获，而不需要事先定义该异常类型。



*/