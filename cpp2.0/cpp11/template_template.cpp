//
// Created by light on 19-11-3.
//
#include <iostream>
#include <list>

using namespace std;
// template template parameter 模板模板参数
template<typename T,template<typename U> class Container>
class XCls {
private:
    Container<T> c;
};

// alias template
template<typename T>
using Lst = list<T>;

int main() {
//    XCls<string, list> mylist1;   // error
    XCls<string, Lst> mylist2;

    return 0;
}
/*
以上代码是一个使用模板的C++类定义和使用示例。

首先，template<typename T, template<typename U> class Container> 表示定义一个模板类 XCls，它有两个模板参数：T 和 Container。

T 是一个通用类型参数，表示 XCls 中要存储的元素的类型。
Container 是一个模板模板参数，表示 XCls 中使用的容器类型。这里的容器类型是一个模板，它接受一个类型参数 U。
在 XCls 类中，私有成员变量 c 的类型是 Container<T>，即根据模板参数确定的具体容器类型 Container，其中元素类型为 T。这样，每个 XCls 对象都会包含一个特定类型的容器。

接下来，通过别名模板 using Lst = list<T>; 定义了一个 Lst，它是 list 类型的别名，其中元素类型为 T。

在 main 函数中，注释掉的 XCls<string, list> mylist1; 会导致编译错误，
原因是list是一个类模板，而XCls的第二个模板参数要求是一个模板模板参数，它需要接受一个类型参数，因此list不能直接作为XCls的模板参数。

然而，XCls<string, Lst> mylist2; 使用了别名模板 Lst，将 list 作为模板参数传递给 XCls 类模板，创建了一个 XCls 对象 mylist2，其中的容器类型为 list<string>。

最后，return 0; 结束 main 函数，并返回 0 表示程序成功执行完毕。
*/
