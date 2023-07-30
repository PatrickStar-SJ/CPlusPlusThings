//
// Created by light on 19-11-4.
//

#include <iostream>

using namespace std;

// 参数type相同的max
int max(initializer_list<int> initializerList) {
    int res = *initializerList.begin();
    for (auto elem:initializerList)
        res = max(res, elem);
    return res;
}


// 参数type相同的maximum
int maximum(int n) {
    return n;
}

template<typename ...Args>
int maximum(int n, Args...args) {
    return std::max(n, maximum(args...));
}

int main() {
    cout << max({10, 8, 100, 1}) << endl;
    cout << maximum(57, 48, 60, 100, 20, 18) << endl;
}
/*


函数int max(initializer_list<int> initializerList)定义了一个接受initializer_list<int>类型参数的函数，
返回类型为int。该函数用于找出给定列表中的最大值。

函数内部首先使用*initializerList.begin()获取列表的第一个元素，并将其赋值给变量res作为初始值。
然后使用范围for循环遍历整个列表，对于每个元素，使用std::max()函数将其与res比较，将较大的值赋给res。
最后，函数返回res作为结果。



函数int maximum(int n)定义了一个接受一个整数参数的函数，返回类型为int。该函数用于返回传入的参数值。

函数模板template<typename ...Args> int maximum(int n, Args...args)定义了一个接受任意个数参数的函数，返回类型为int。
该函数使用递归的方式，将第一个参数与剩余的参数逐个比较，并将较大的值作为新的第一个参数，然后递归调用自身，直到没有剩余参数为止，最后返回最大值。


在main()函数中，首先调用max({10, 8, 100, 1})，传入一个初始化列表作为参数，该初始化列表包含四个整数值。该语句将输出列表中的最大值。
然后调用maximum(57, 48, 60, 100, 20, 18)，传入六个整数值作为参数。该语句将使用函数模板maximum()，递归调用自身，找出这些整数中的最大值，并将其输出。
*/