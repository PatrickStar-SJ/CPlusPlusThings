/**
 * @file union.cpp
 * @brief UNION
 * @author 光城
 * @version v1
 * @date 2019-08-06
 */

#include <iostream>
/**
 * 默认访问控制符为public
 */
union UnionTest {
  /**
   * 可以含有构造函数、析构函数
   */
  UnionTest() : i(10) { print(i); };
  ~UnionTest(){};
  int i;

private:
  void print(int i) { std::cout << i << std::endl; };
};
/**
 * 全局匿名联合必须是静态的
 */
static union {
  int i;
  double d;
};

int main() {
  UnionTest u;

  union {
    int i;
    double d;
  };

  std::cout << u.i << std::endl; // 输出 UnionTest 联合的 10

  ::i = 20;
  std::cout << ::i << std::endl; // 输出全局静态匿名联合的 20
  /**
   * 匿名union在定义所在作用域可直接访问union成员
   */
  i = 30;
  std::cout << i << std::endl; // 输出局部匿名联合的 30

  return 0;
}
/*
联合（union）是一种节省空间的特殊的类.
一个 union 可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值。当某个成员被赋值后其他成员变为未定义状态。

联合有如下特点：
1. 默认访问控制符为 public
2. 可以含有构造函数、析构函数
3. 不能含有引用类型的成员
4. 不能继承自其他类，不能作为基类
5. 不能含有虚函数
6. 匿名 union 在定义所在作用域可直接访问 union 成员
7. 匿名 union 不能包含 protected 成员或 private 成员
8. 全局匿名联合必须是静态（static）的

执行结果：
10
10
20
30
*/