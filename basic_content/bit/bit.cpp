#include <iostream>

using namespace std;
struct stuff {
  unsigned int field1 : 30;
  unsigned int : 2;
  unsigned int field2 : 4;
  unsigned int : 0;
  unsigned int field3 : 3;
};
int main() {
  struct stuff s = {1, 3, 5};
  cout << s.field1 << endl;
  cout << s.field2 << endl;
  cout << s.field3 << endl;
  cout << sizeof(s) << endl;
  return 0;
}

/*
这段代码定义了一个包含三个成员变量的结构体 "stuff"，每个变量都是无符号整型。下面是每个成员变量的含义：

- field1：占用 30 个位，范围为 0 到 1 073 741 823（2 的 30 次方减 1），代表结构体的第一个字段。
- 未命名的 2 位：被用作填充，不包含任何信息。
- field2：占用 4 个位，范围为 0 到 15，代表结构体的第二个字段。
- 未命名的 0 位：被用作对齐，不包含任何信息。
- field3：占用 3 个位，范围为 0 到 7，代表结构体的第三个字段。

在主函数中，首先创建一个名为 "s" 的结构体变量并将其初始化为 {1, 3, 5}。
然后打印出 "s.field1"、"s.field2" 和 "s.field3" 的值以及整个结构体的大小，最后函数返回 0。
因为 "field1" 和 "field2" 之间有两个无名位，所以 "field2" 的偏移量是 32 位，而 "field3" 的偏移量是 36 位。
因此，"field1" 占用了 30 个位，"field2" 占用了 4 个位，而 "field3" 只占用了 3 个位（用了 1 个填充位）。
整个结构体需要对齐，所以实际大小为 8 个字节（32 位）。




执行结果：
1
3
5
12
*/