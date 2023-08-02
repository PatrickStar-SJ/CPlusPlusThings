//
// Created by light on 19-11-3.
//

#include <iostream>
#include <map>
#include <set>

using namespace std;

// 1.used to declare return tyoes  返回类型

// c++2.0之前编译不出来
// template<typename T1, typename T2>
// decltype(x + y) add(T1 x, T2 y);

// 编译器编不出来在2.0之后变成下面这个,先用auto暂定,后面返回类型为decltype(x+y)
template <typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y)
{ // -> 也用在lambda
    return x + y;
}

class Person
{
public:
    string firstname;
    string lastname;
};
int main()
{

    // 1.used to declare return tyoes
    cout << add(1, 2) << endl;

    // 2.模板元编程 例如在一个模板函数或类获取容器的value_type,这里就不封装了,直接写在main函数里面
    // 获得表达式的type 有点像typeof()特点
    map<string, float> coll;
    // 获取上述类型
    decltype(coll)::value_type m{"as", 1}; // value_type为pair<string,int> m
    /*
    decltype(coll)::value_type用于获取coll容器中元素的类型。在这里，coll的类型是map<string, float>，
    因此decltype(coll)::value_type表示pair<string, float>类型。
    */



    cout << m.first << " " << m.second << endl;
    pair<string, int> p{"a", 2};
    cout << p.first << " " << p.second << endl;
    // 3.used to pass the type of a lambda

    // 比大小
    //定义了一个lambda表达式cmp，用于比较Person对象的lastname成员变量。decltype(cmp)用于获取cmp的类型。
    auto cmp = [](const Person &p1, const Person &p2)
    {
        return p1.lastname < p2.lastname;
    };

    // 对于lambda,我们往往只有object,很少有人能够写出它的类型，而有时就需要知道它的类型,要获得其type,就要借助其decltype
    //在定义set容器时，指定了Person的类型和cmp的类型作为模板参数。使用decltype(cmp)来获取cmp的类型。
    set<Person, decltype(cmp)> col(cmp);

    return 0;
}
/*
这段代码展示了decltype关键字的三种用法。
1. 在函数模板add中，使用decltype来声明函数的返回类型。decltype(x + y)表示返回类型与表达式x + y的类型相同。

2. 在main函数中，使用decltype来获取表达式的类型。

2. 在main函数中，使用decltype来传递lambda表达式的类型。
*/