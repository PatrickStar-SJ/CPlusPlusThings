//
// Created by light on 19-11-2.
//

// variadic template(c++11) 数量不定的模板参数
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
// 参数个数  参数个数逐一递减
// 参数类型  参数类型也逐一递减

// (3)
// 需要重载一个终止函数
template<typename T>
void _hash(size_t &seed, const T &val) {
    cout << "hash over " << val << endl;
}

// (2)
// 展开函数, 把参数分为一个普通参数和一个参数包，调用一次，参数包大小就减一
template<typename T,typename... Args>
void _hash(size_t &seed, const T& val,const Args &... args) {
    cout << "parameter " << val<< endl;
    // 递归调用自己
    _hash(seed, args...);       // 上面如果不给T参数,会自己调用自己成死循环
}


// 泛化版 (1)
template<typename ...Args>
size_t _hash(const Args &... args) {
    cout << "hash start " << endl;
    size_t seed = 10;
    // 递归调用自己
    _hash(seed, args...);
    return seed;
}


template<typename ...Args>
class A {
private:
    int size = 0;    // c++11 支持类内初始化
public:
    A() {
        size = sizeof...(Args);
        cout << size << endl;
    }
};

int main(void) {
    size_t f = 10;
    _hash("asdas", 2, 3, 4);
    A<int, string, vector<int>> a;    // 类型任意

    // Tuple就是利用这个特性(变长参数模板)
    tuple<int, string> t = make_tuple(1, "hha");
    int firstArg = get<0>(t);
    string secondArg = get<1>(t);
    cout << firstArg << " " << secondArg << endl;
    return 0;
}
/*

template<typename T> 
void _hash(size_t &seed, const T &val): 
定义了一个函数模板_hash，接受一个引用参数seed和一个常量引用参数val。该函数用于输出"hash over "和val的值。

template<typename T, typename... Args> 
void _hash(size_t &seed, const T& val, const Args &... args): 
定义了一个函数模板_hash，接受一个引用参数seed，一个常量引用参数val和一个可变参数模板args。
该函数用于输出"parameter "和val的值，并递归调用自己，传递剩余的args。

template<typename ...Args> 
size_t _hash(const Args &... args): 
定义了一个函数模板_hash，接受一个可变参数模板args。该函数用于输出"hash start "，创建一个变量seed并初始化为10，然后递归调用_hash函数，传递seed和args，最后返回seed的值。

template<typename ...Args> class A: 
定义了一个类模板A，接受可变参数模板Args。该类有一个私有成员变量size，并在构造函数中初始化为sizeof...(Args)，即模板参数的数量。构造函数中输出size的值。


输出：
hash start 
parameter asdas
parameter 2
parameter 3
hash over 4   除了seed，就仅剩一个参数了，调用终止函数
3     来自A的构造函数
1 hha
*/

