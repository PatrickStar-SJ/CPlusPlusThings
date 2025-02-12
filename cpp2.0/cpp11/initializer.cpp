//
// Created by light on 19-11-3.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int i;
    int j();        // 0
    int *p;
    int *q();       // nullptr


//    int x1{5.0};    //  error:narrowing conversion
    // 编译器调用initializer_list私有构造之前,编译器准备好array(array头)与len,传递给该构造,并没有内含这个array,
    // 指针指向array,copy只是浅copy.
    // 如今所有容器都接受任意数量的值  insert()或assign() max() min()

    cout<<max({1,2,3})<<endl;   // algorithm里面的max/min
    return 0;
}
/*
int j(); 定义了一个函数 j，该函数没有参数，并返回一个整数值。由于没有提供函数的具体实现，编译器会将其默认为返回值为 0 的函数。
int *p; 定义了一个指向整数的指针变量 p。
int *q(); 定义了一个函数 q，该函数没有参数，并返回一个指向整数的指针。同样地，由于没有提供函数的具体实现，编译器会将其默认为返回一个空指针的函数。
*/