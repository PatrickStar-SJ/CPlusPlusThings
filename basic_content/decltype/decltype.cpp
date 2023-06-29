#include <iostream>
#include <vector>
using namespace std;
/**
 * 泛型编程中结合auto，用于追踪函数的返回值类型
 */
template <typename T>
//函数的返回类型用 `decltype(x * y)` 推断。
auto multiply(T x, T y) -> decltype(x * y) {
  return x * y;
}

int main() {
  int nums[] = {1, 2, 3, 4};
  vector<int> vec(nums, nums + 4);
  vector<int>::iterator it;

  for (it = vec.begin(); it != vec.end(); it++)
    cout << *it << " ";
  cout << endl;
  //使用 `using` 关键字将 `nullptr_t` 定义为 `decltype(nullptr)` 的别名。C++11 引入了 `nullptr` 关键字，它表示一个空指针常量，可以用来替代传统的 `NULL` 值。
  using nullptr_t = decltype(nullptr); 
  nullptr_t nu;
  int *p = NULL;
  if (p == nu)
    cout << "NULL" << endl;
  //使用 `typedef` 将 `vec.begin()` 的类型定义为 `vectype`.
  typedef decltype(vec.begin()) vectype;
  // 这里使用 auto更好啊
  for (vectype i = vec.begin(); i != vec.end(); i++)
    cout << *i << " ";
  cout << endl;

  /**
   * 匿名结构体
   */
  struct {
    int d;
    double b;
  } anon_s;
  //使用 `decltype(anon_s)` 来定义一个匿名结构体实例 `as`，并使用初始化列表初始化它的成员。
  decltype(anon_s) as{1, 2.0}; // 定义了一个上面匿名的结构体

  cout << multiply(11, 2) << ":" << as.b << endl;

  return 0;
}
