//
// Created by light on 19-11-2.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int value[]{1, 2, 3};       // initializer_list<T> 会关联一个array<T,n> 里面元素被编译器逐一分解传给函数
    vector<int> v{2, 3, 5};
    return 0;
}
/*
这段代码使用初始化列表(initializer_list)来初始化数组和向量。
初始化列表关联一个数组(array)对象并将其逐一分解传递给函数。
*/