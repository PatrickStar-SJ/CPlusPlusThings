/**
 * @file using_typedef.cpp
 * @brief bazel run basic_content/using:using_typedef
 * 取代typedef，使用using来定义别名
 * @author 光城
 * @version v1
 * @date 2019-08-07
 */

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> V1;
using V2 = vector<int>;

int main() {
  int nums1[] = {1, 2, 3, 4, 5, 6};
  V1 vec1(nums1, nums1 + sizeof(nums1) / sizeof(int));
  int nums2[] = {5, 7, 6};
  V2 vec2(nums2, nums2 + sizeof(nums2) / sizeof(int));

  for (auto i : vec1)
    std::cout << i << " ";
  cout << endl;

  for (auto i : vec2)
    std::cout << i << " ";
  cout << endl;

  return 0;
}

/*
编译： g++ using_typedef.cpp --std=c++11

对应typedef A B，使用using B=A可以进行同样的操作。

typedef vector<int> V1; 
using V2 = vector<int>;

执行结果：
1 2 3 4 5 6 
5 7 6 
*/