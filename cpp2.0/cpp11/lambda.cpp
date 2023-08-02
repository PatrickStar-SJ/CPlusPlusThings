//
// Created by light on 19-11-3.
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
//lambda表达式的语法形式为[捕获列表](参数列表) -> 返回类型 { 函数体 }。


// [introducer](optional)mutable throwSpec->retType {}
// mutable决定[]能够被改写  mutable throwSpec retType都是选择的,只要有一个存在就得写()
// retType 返回类型
// ()放参数
// []放外面变量 passed by value or reference


class UnNamedLocalFunction {
private:
    int localVar;
public:
    UnNamedLocalFunction(int var) : localVar(var) {}

    bool operator()(int val) {
        return val == localVar;
    }
};

class Person {
public:
    string firstname;
    string lastname;
};

class LambdaFunctor {
public:
    LambdaFunctor(int a, int b) : m_a(a), m_b(b) {}

    bool operator()(int n) const {
        return m_a < n && n < m_b;
    }

private:
    int m_a;
    int m_b;
};

/*
X 类：这是一个表示某种对象的类。它具有两个私有成员变量 __x 和 __y，通过构造函数进行初始化。
类中定义了一个重载的调用运算符 operator()，它接受一个整数参数 a，并返回该参数。类中还定义了两个成员函数 f() 和 ff()。

f() 函数中包含一个 lambda 表达式。该表达式使用捕获列表 [&]，表示它可以访问当前对象的所有成员变量和方法。
lambda 表达式返回调用 operator() 的结果，参数是 __x 和 __y 相加的值。

ff() 函数中包含一个 lambda 表达式。该表达式使用捕获列表 [this]，表示它只能访问当前对象的成员变量和方法。
lambda 表达式返回 __x 成员变量的值。
*/

class X {
private:
    int __x, __y;
public:
    X(int x, int y) : __x(x), __y(y) {}

    int operator()(int a) { return a; }

    int f() {
        // 下列 lambda 的语境是成员函数 X::f
        // 对于[=]或[&]的形式，lambda 表达式可以直接使用 this 指针
        return [&]() -> int {
            return operator()(this->__x + __y); // X::operator()(this->x + (*this).y)
            // 拥有类型 X*
        }();
    }


    int ff() {
        return [this]() {
            return this->__x;
        }();
    }
};

int main() {

    [] {
        cout << "hello" << endl;
    }();
    /*
    这是一个立即调用的lambda函数。[]表示此lambda函数没有捕获任何外部变量，{}内包含要执行的代码，
    这里是输出字符串"hello"并换行。()表示立即调用这个lambda函数，使其在定义后立即执行。
    因此，运行此代码会输出"hello"。
    */

    //=================================================================


    auto I = [] {
        cout << "hello" << endl;
    };
    I();
    /*
    这里首先将一个lambda函数赋值给了一个名为I的变量。[]表示此lambda函数同样没有捕获任何外部变量，
    {}内是要执行的代码，同样是输出字符串"hello"并换行。
    最后通过I()调用这个lambda函数。这段代码的结果也是输出"hello"。
    */

    //=================================================================

    int id = 0;
    // 先看前面的id 如果没有mutable error: increment of read-only variable ‘id’
    auto f = [id]()mutable {
        cout << "id=" << id << endl;
        ++id;
    };
    id = 42;
    f();    // 0
    f();    // 1
    f();    // 2
    cout << id << endl;
    /*
    创建了一个Lambda表达式，并使用了可变捕获（mutable capture）。
    连续调用Lambda表达式通过函数调用运算符来执行。每次调用时，都会打印当前id的值并将其递增。
    由于Lambda表达式中的id是通过值捕获的，而不是引用捕获，所以主函数中的id值没有受到Lambda表达式中的递增操作的影响，因此输出的是42。
    */

    // 上述lambda就相当于
//    class Functor {
//    private:
//        int id;
//    public:
//        void operator() {
//            cout << "id=" << id << endl;
//            ++id;
//        }
//    };
//    Functor f;


    //=================================================================

    int id1 = 0;
    // 加不加mutable没影响,且传引用只要后面id1被修改了,就会使用修改后的值进行操作
    auto f1 = [&id1]() {
        cout << "id1=" << id1 << endl;
        ++id1;
    };
    id1 = 42;
    f1();    // 42
    f1();    // 43
    f1();    // 44
    cout << id1 << endl;
    /*
    lambda表达式创建了一个可调用对象f1，并且通过传引用的方式捕获了id1变量。
    [&id1]表示以引用的方式捕获外部变量id1。这意味着在lambda表达式中可以访问并修改id1变量的值。
    在lambda表达式中对id1的修改也影响了外部的id1变量。
    */

    //=================================================================


    // 传参与返回
    int id2 = 0;
    auto f2 = [&id2](int &param) {
        cout << "id2=" << id2 << endl;
        ++id2;
        ++param;
        cout << "param=" << param << endl;
        static int x = 5;
        return id2;
    };
    int param = 1;
    f2(param);
    cout << "param=" << param << endl;
    /*
    lambda表达式内部使用了捕获列表[&id2]，表示通过引用方式捕获外部变量id2。
    调用函数对象f2，将param作为参数传递给f2。
    */
    //=================================================================

    // [=] =表示默认以by value传递外部所有变量
    // [&] &表示默认以by reference传递外部所有变量
    auto f3 = [&]() {
        cout << "id=" << id << endl;
        cout << "id1=" << id1 << endl;
        cout << "id2=" << id2 << endl;
        cout << "param=" << param << endl;
    };
    f3();
    //=================================================================
    // 一部分传引用,其余传值
    cout << "id=" << id << endl;
    auto f4 = [=, &id]() {       // =不可以放在&id后面
        cout << "id=" << id << endl;
        id++;
        cout << "id1=" << id1 << endl;
        cout << "id2=" << id2 << endl;
        cout << "param=" << param << endl;
    };
    f4();
    //=================================================================
    // 一部分传值,其余传引用
    cout << "id=" << id << endl;
    auto f5 = [&, id]() {       // &不可以放在id后面
        cout << "id=" << id << endl;
        cout << "id1=" << id1 << endl;
        cout << "id2=" << id2 << endl;
        cout << "param=" << param << endl;
    };
    f5();
    // this 指针
    X x_(1, 2);
    cout << "x_.f()=" << x_.f() << endl;   // 1+2=3
    cout << "x_.ff()=" << x_.ff() << endl; // 1

    //=================================================================

    // 下面lambda函数等价于上述的UnNamedLocalFunction
    int tobefound = 5;
    auto lambda1 = [tobefound](int val) {
        return val == tobefound;
    };
    bool b1 = lambda1(5);
    UnNamedLocalFunction lambda2(tobefound);
    bool b2 = lambda2(5);
    cout << b1 << " " << b2 << endl;



    auto ll1 = [](int x) -> int {
        return x + 10;
    };
    //lambda表达式的语法形式为[捕获列表](参数列表) -> 返回类型 { 函数体 }。
    //在这里，捕获列表为空，参数列表中有一个整数参数x，返回类型为int，函数体为return x + 10;。
    //这个lambda表达式的功能很简单，它将输入的整数参数x加上10，并将结果作为整数返回。
    //可以将ll1作为函数对象调用，传入一个整数参数来执行它的逻辑，并得到相应的返回值。


    // lambda 匿名函数
    function<int(int x)> ll = [](int x) -> float {
        return x + 10.0;
    };
    cout<<ll(1)<<endl;
    /*
    声明了一个名为 ll 的变量，类型为 function<int(int x)>。
    这意味着 ll 可以存储一个可调用对象（例如函数或 lambda），该对象接受一个 int 参数并返回一个 int 值。
    */




    // decltype+lambda
    // 比大小
    //声明了一个类型为function<bool(const Person&p1,const Person&p2)>的变量cmp，
    //它表示一个可以接受两个Person对象作为参数并返回布尔值的函数。这个函数用于比较两个Person对象的顺序。
    function<bool(const Person&p1,const Person&p2)> cmp = [](const Person &p1, const Person &p2) {
        return p1.lastname < p2.lastname;
    };
    //Lambda 表达式 [](const Person &p1, const Person &p2) { return p1.lastname < p2.lastname; } 定义了一个匿名函数，
    //用于比较两个 Person 对象的姓氏（lastname）。Lambda 表达式使用方括号 [] 表示捕获列表


    // 对于lambda,我们往往只有object,很少有人能够写出它的类型，而有时就需要知道它的类型,要获得其type,就要借助其decltype
    set<Person, decltype(cmp)> col(cmp); //这将使用上面定义的比较函数cmp来确定集合中元素的顺序。

    // 要申明lambda对象的类型，可以使用template或者auto进行自动推导。
    // 如果需要知道类型，可以使用decltype，比如，让lambda函数作为关联容器或者无序容器的排序函数或者哈希函数。
    // 上面代码给出了事例（decltype的第三种用法中的事例），定义了一个lambda函数用cmp表示，用来比较Person对象的大小，传入到Set容器中去，
    // 但根据右边的set容器的定义，我们传入的不仅是cmp（构造函数），还要传入模板的cmp类型（Set内部需要声明cmp类型），
    // 所以必须使用decltype来推导出类型。
    // （如果没有向构造函数传入cmp，调用的是默认的构造函数，也就是set() : t(Compare()), 这里会报错, 现在不会出问题了!
    // 因为Compare()指的是调用默认的lambda构造函数，而lambda函数没有默认构造函数和赋值函数）


    vector<int> vec{5, 28, 50, 83, 70, 590, 245, 59, 24};
    int x = 30, y = 100;
    // 函数对象是很强大的，封装代码和数据来自定义标准库的行为，但需要写出函数对象需要写出整个class，这是不方便的，而且是非本地的，
    // 用起来也麻烦，需要去看怎样使用，另外编译出错的信息也不友好，而且它们不是inline的，效率会低一些（算法效率还是最重要的）。
//    vec.erase(remove_if(vec.begin(), vec.end(), LambdaFunctor(x, y)), vec.end());
//    for(auto i:vec) cout<<i<<" ";
//    cout<<endl;
    // 而lambda函数的提出解决了这个问题，简短有效清晰，上面的事例很好的说明了这个问题，用lambda要简短许多，功能一样，很直观。
    vec.erase(remove_if(vec.begin(), vec.end(), [x, y](int n) { return x < n && n < y; }), vec.end());
    for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
    cout << endl;
    return 0;

}
