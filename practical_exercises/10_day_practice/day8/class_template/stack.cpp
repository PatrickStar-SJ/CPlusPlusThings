/* 模拟栈.cpp */
/*
设计一个堆栈的类模板Stack，在模板中用类型参数T表示栈中存放的数据，用非类型参数MAXSIZE代表栈的大小。
*/
#include <iostream>
using namespace std;

template <class T, int MAXSIZE> class Stack {
private:
  T elem[MAXSIZE];
  int top;

public:
  Stack() { top = 0; };
  void push(T e);
  T pop();
  bool empty() {
    if (top <= -1)
      return 1;
    else
      return 0;
  }
  void setEmpty() { top = -1; }
  bool full() {
    if (top >= MAXSIZE - 1) {
      return 1;
    } else
      return 0;
  }
};
/*
原型：
template <模板参数列表>
返回值类型 类模板名<模板参数名表>::成员函数名 (参数列表){};
*/
template <class T, int MAXSIZE> void Stack<T, MAXSIZE>::push(T e) {
  if (full()) {
    cout << "栈已满，不能再添加元素了！";
    return;
  }
  elem[++top] = e;
}

template <class T, int MAXSIZE> T Stack<T, MAXSIZE>::pop() {
  if (empty()) {
    cout << "栈已空，不能再弹出元素了！" << endl;
    return 0;
  }
  return elem[top--];
}

int main(int argc, char const *argv[]) {
  //类模板实例化
  Stack<int, 10> iStack;
  Stack<char, 10> cStack;
  iStack.setEmpty();
  cStack.setEmpty();
  cout << "-------intStack----\n";
  int i;
  for (i = 1; i < 11; i++)
    iStack.push(i);
  for (i = 1; i < 11; i++)
    cout << iStack.pop() << "\t";
  cout << "\n\n-------charStack----\n";
  cStack.push('A');
  cStack.push('B');
  cStack.push('C');
  cStack.push('D');
  cStack.push('E');
  for (i = 1; i < 6; i++)
    cout << cStack.pop() << "\t";
  cout << endl;
  
  return 0;
}
/*
上面的代码定义了一个模板类 Stack，用于实现栈的功能。该类有以下成员函数和成员变量：

成员变量：
    elem[MAXSIZE]：一个大小为 MAXSIZE 的数组，用于存储栈的元素。
    top：一个整数，表示栈顶元素的索引。
构造函数：
    Stack()：构造函数，初始化栈为空栈，即将 top 设置为 0。
成员函数：
    push(T e)：将元素 e 入栈。如果栈已满，输出提示信息。
    pop()：弹出栈顶元素，并返回该元素的值。如果栈为空，输出提示信息。
辅助函数：
    empty()：判断栈是否为空。如果 top 小于等于 -1，返回 true，否则返回 false。
    setEmpty()：将栈置为空栈，即将 top 设置为 -1。
    full()：判断栈是否已满。如果 top 大于等于 MAXSIZE - 1，返回 true，否则返回 false。
其中，template <class T, int MAXSIZE> void Stack<T, MAXSIZE>::push(T e) 和 
     template <class T, int MAXSIZE> T Stack<T, MAXSIZE>::pop() 是成员函数的定义。
     这些成员函数的定义在类模板外部进行时需要指明模板参数的类型和值。
     例如，Stack<T, MAXSIZE> 表示使用模板参数 T 和 MAXSIZE 实例化的 Stack 类。

*/