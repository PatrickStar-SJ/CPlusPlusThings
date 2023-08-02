//
// Created by light on 19-11-3.
//

#include <iostream>
#include <vector>

using namespace std;

// noexcepte ()中可以加条件
// 异常可传递  a调用b b抛出异常,a没处理,就会抛出异常
// 1.异常的回传机制:调用foo如果抛出异常，foo会接着往上层抛出异常，
// 如果最上层没有处理，则会调用terminate函数，terminate函数内部调用abort，使程序退出


// 2.在使用vector deque等容器的移动构造和移动赋值的时候，如果移动构造和移动赋值没有加上noexcept，
// 则容器增长的时候不会调用move constructor，效率就会偏低，所以后面需要加上noexcept，安心使用。

void foo() noexcept(true) {   
}

int main() {
    foo();
    vector<int> vec;
    return 0;
}
//函数定义中的noexcept(true)表示该函数不会抛出异常。也就是说，如果在foo()函数内部发生异常，它将不会引发异常，而是将异常处理控制权传递给上层调用者。