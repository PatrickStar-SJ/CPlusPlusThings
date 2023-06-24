#include <stdio.h>

struct Base
{ // public
    int v1;
    //    public:      //error
    int v2;
    // private:
    int v3;
    // void print(){       // c中不能在结构体中嵌入函数
    //     printf("%s\n","hello world");
    // };    //error!
};

void Base()
{
    printf("%s\n", "I am Base func");
}
// struct Base base1;  //ok
// Base base2; //error

int main()
{
    struct Base base;
    base.v1 = 1;
    // base.print();
    printf("%d\n", base.v1);
    Base();
    return 0;
}
/*
本文件后缀是".c"

c中的结构体：
1. 结构体声明中只能将数据成员放在里面，而不能将函数放在里面
2. 不能使用C++访问修饰符，如：public、protected、private
3. 结构体的名字与函数名相同，可以正常运行且正常的调用

*/