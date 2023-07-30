//
// Created by light on 19-11-4.
//

#include <iostream>
#include <bitset>

using namespace std;

// example 1
void printX() {

}

// 特化
template<typename T, typename... Type>
void printX(const T &firstArg, const Type &...args) {
    cout << firstArg << endl;       // 先减少一个做操作
    printX(args...);    // 其余的继续分为一个+一包进行递归知道没有了 调用printX()
}

// 如果写了下面接收任意参数,下面这个跟上面可以共存 泛化版  永远不会被调用,前面特化把它取代了
template<typename T, typename... Type>
void printX(const Type &...args) {
    printX(args...);
}


int main() {
    printX(1, "hello", bitset<16>(377), 42);
    return 0;
}
/*
上面的代码定义了一个递归的可变参数函数模板printX，用于打印任意数量和类型的参数。

void printX() {}: 定义了一个不接收任何参数的空函数。

template<typename T, typename... Type> 
void printX(const T &firstArg, const Type &...args): 
模板函数printX的特化版本，接收一个参数firstArg和可变数量的参数args。首先输出firstArg的值，
然后递归调用printX(args...)，将剩余的参数传递给下一次递归调用。这样就能逐个输出所有的参数。

template<typename T, typename... Type> 
void printX(const Type &...args): 
模板函数printX的泛化版本，接收可变数量的参数args。这个版本的函数实际上是被特化版本取代的，永远不会被调用。
因为在特化版本中可以处理任意类型的参数，所以这个泛化版本没有实际的用途。


在main函数中，调用printX函数，并传递参数1, "hello", bitset<16>(377), 42。根据参数的类型，将会调用特化版本的printX函数。首先输出1，然后递归调用printX("hello", bitset<16>(377), 42)，再次输出"hello"，然后递归调用printX(bitset<16>(377), 42)，再次输出bitset<16>(377)的值，最后输出42。整个过程会逐个打印出所有的参数。
*/