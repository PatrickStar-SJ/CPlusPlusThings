/* 类模板特化之数组.cpp */
#include <cstring>
#include <iostream>
using namespace std;
#define MAXSIZE 5
template <class T> class Array {  // 定义模板类 Array
public:
  Array() {
    for (int i = 0; i < MAXSIZE; i++) {
      array[i] = 0;
    }
  }
  T &operator[](int i);   // 重载 [] 操作符，申明，以便通过索引访问数组元素。
  void Sort();
private:
  T array[MAXSIZE];
};
// 重载 [] 操作符，定义，以便通过索引访问数组元素。
template <class T> T &Array<T>::operator[](int i) { 
  if (i < 0 || i > MAXSIZE - 1) {
    cout << "数组下标越界！" << endl;
    exit(0);
  }
  return array[i];
}

template <class T> void Array<T>::Sort() {
  int p, j;
  for (int i = 0; i < MAXSIZE - 1; i++) {
    p = i;
    for (j = i + 1; j < MAXSIZE; j++) {
      if (array[p] < array[j])
        p = j;
    }
    T t;
    t = array[i];
    array[i] = array[p];
    array[p] = t;
  }
}
template <> void Array<char *>::Sort() {  //Array 类特化版本 Sort 函数的定义，用于对字符指针数组进行排序。
  int p, j;
  for (int i = 0; i < MAXSIZE - 1; i++) {
    p = i;
    for (j = i + 1; j < MAXSIZE; j++) {
      if (strcmp(array[p], array[j]) < 0)
        p = j;
    }
    char *t = array[i];
    array[i] = array[p];
    array[p] = t;
  }
}

int main(int argc, char const *argv[]) {
  Array<int> a1;
  Array<char *> b1;
  a1[0] = 1;   //相当于 array[0] = 1
  a1[1] = 23;
  a1[2] = 6;
  a1[3] = 3;
  a1[4] = 9;
  a1.Sort();
  for (int i = 0; i < 5; i++)
    cout << a1[i] << "\t";
  cout << endl;
  b1[0] = "x1";
  b1[1] = "ya";
  b1[2] = "ad";
  b1[3] = "be";
  b1[4] = "bc";
  b1.Sort();
  for (int i = 0; i < 5; i++)
    cout << b1[i] << "\t";
  cout << endl;
  
  return 0;
}
/*
在类定义中，有一个默认构造函数Array()，用于初始化数组中的所有元素为0。


类中还定义了一个重载的[]运算符，用于访问数组中的元素。该运算符返回一个引用，可以用于读取或修改数组中的元素。在运算符重载函数中，先检查传入的索引是否越界，如果越界则输出错误信息并终止程序，否则返回对应索引处的元素的引用。


类中还定义了一个Sort()函数，用于对数组进行排序。排序算法使用的是选择排序。在排序过程中，如果元素类型是char*，则使用特定的排序方式，即按照字符串的字典序进行比较。

在类定义后面，有一个特化的Sort()函数模板，用于处理元素类型为char*的情况。该函数模板与前面的Sort()函数模板的实现基本相同，只是在比较元素大小时使用了strcmp()函数来比较字符串的字典序。
*/