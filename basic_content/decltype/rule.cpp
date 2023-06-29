/*
什么是左值和右值：

在C++中，左值（lvalue）和右值（rvalue）是与表达式的值评估和使用相关的概念。

左值指的是可寻址（addressable）的表达式，即可以获得其在内存中存储的位置。左值可以出现在赋值语句的左侧，也可以取地址或绑定到引用。例如，变量、数组元素、表达式的结果等都是左值。

右值指的是不可寻址的临时值，即不能获得其在内存中存储的位置。右值可以出现在赋值语句的右侧，但不能取地址或绑定到非常量引用。例如，常量、字面量、临时对象等都是右值。

可以通过使用引用来区分左值和右值。如果一个表达式可以绑定到非常量引用，则该表达式是左值；如果一个表达式只能绑定到常量引用或临时对象，则该表达式是右值。

在C++11之后，引入了右值引用（rvalue reference）的概念，它允许我们绑定到右值并对其进行修改。右值引用的语法为&&，可以在函数和模板中使用，用于实现移动语义和完美转发等高效的操作。右值引用的引入使得对右值的使用更加灵活和高效。

总结起来，左值表示一个可以标识的内存位置，右值表示一个临时值或无法引用的值。通过引用和右值引用的机制，可以对左值和右值进行不同的操作和使用。
*/




/*
对于decltype(e)而言，其判别结果受以下条件的影响：

如果e是一个没有带括号的标记符表达式或者类成员访问表达式，那么的decltype（e）就是e所命名的实体的类型。此外，如果e是一个被重载的函数，则会导致编译错误。 否则 ，假设e的类型是T，如果e是一个将亡值，那么decltype（e）为T&& 否则，假设e的类型是T，如果e是一个左值，那么decltype（e）为T&。 否则，假设e的类型是T，则decltype（e）为T。
*/

int i = 4;
int arr[5] = { 0 };
int *ptr = arr;
struct S{ double d; }s ;
void Overloaded(int);
void Overloaded(char);//重载的函数
int && RvalRef();
const bool Func(int);


//规则一：推导为其类型
decltype (arr) var1; //int[] 标记符表达式

decltype (ptr) var2;//int *  标记符表达式

decltype(s.d) var3;//doubel 成员访问表达式

//decltype(Overloaded) var4;//重载函数。编译错误。
//规则二：将亡值。推导为类型的右值引用。

decltype (RvalRef()) var5 = 1; //这里的decltype(RvalRef())表示RvalRef()函数的返回类型，即int &&。所以var5的类型是int &&，并且初始化为1。

//规则三：左值，推导为类型的引用。

decltype ((i))var6 = i;     //int&   这里的decltype((i))表示i的类型，即int &。因为(i)是一个左值引用，所以var6的类型是int &。并且初始化为i的值。

decltype (true ? i : i) var7 = i; //int&  条件表达式返回左值。 这里的decltype(true ? i : i)表示条件表达式的结果类型。因为true ? i : i是一个左值引用，所以var7的类型是int &。并且初始化为i的值。

decltype (++i) var8 = i; //int&  ++i返回i的左值。  这里的decltype(++i)表示++i的类型，即int &。因为++i是一个左值引用，所以var8的类型是int &。并且初始化为i的值。

decltype(arr[5]) var9 = i;//int&. []操作返回左值  这里的decltype(arr[5])表示arr[5]的类型，即int &。因为arr[5]是一个左值引用，所以var9的类型是int &。并且初始化为i的值。

decltype(*ptr)var10 = i;//int& *操作返回左值  这里的decltype(*ptr)表示*ptr的类型，即int &。因为*ptr是一个左值引用，所以var10的类型是int &。并且初始化为i的值。

decltype("hello")var11 = "hello"; //const char(&)[9]  字符串字面常量为左值，且为const左值。 这里的decltype("hello")表示字符串字面量的类型，即const char[6]。所以var11的类型是const char[6]，并且初始化为"hello"。


//规则四：以上都不是，则推导为本类型

decltype(1) var12;//const int  这里的decltype(1)表示整数字面量的类型，即const int。所以var12的类型是const int。

decltype(Func(1)) var13=true;//const bool 这里的decltype(Func(1))表示Func(1)的返回类型，即const bool。所以var13的类型是const bool，并且初始化为true。

decltype(i++) var14 = i;//int i++返回右值 这里的decltype(i++)表示i++的类型，即int。因为i++是一个右值，所以var14的类型是int，并且初始化为i的值。
