/**
 * @file func_pointer.cpp
 * @brief 函数指针的使用！
 * @author 光城
 * @version v1
 * @date 2019-07-20
 */

#include <iostream>
using namespace std;

/**
 * @brief
 * 定义了一个变量pFun，这个变量是个指针，指向返回值为空和参数为int的函数的指针！
 */
void (*pFun)(int);

/**
 * @brief 代表一种新类型，不是变量！所以与上述的pFun不一样！
 */
typedef void (*func)(void);   //定义了一个名字为func的函数指针类型，它指向一个无参无返回值的函数

void myfunc(void) { cout << "asda" << endl; }

void glFun(int a) { cout << a << endl; }
int main() {
  //定义了一个函数指针类型为func，其函数原型为void(void)，然后将myfunc函数的地址赋值给pfun指针变量，
  //使其指向myfunc函数。这样pfun就可以被当成函数名使用，调用pfun时实际上就是调用myfunc函数。
  func pfun = myfunc; /*赋值*/
  pfun();             /*调用*/
  pFun = glFun;
  (*pFun)(2);
}

/*
asda
2
*/