/* 类模板特化.cpp */
//设计一通用数组类，它能够直接存取数组元素，并能够对数组进行从大到小的排序。

#include <cstring>
#include <iostream>
using namespace std;
const int Size = 5;
template <class T> class Array {
private:
  T a[Size];

public:
  Array() {
    for (int i = 0; i < Size; i++) {
      a[i] = 0;
    }
  }
  T &operator[](int i);
  void Sort();
};

template <class T> T &Array<T>::operator[](int i) {
  if (i < 0 || i > Size - 1) {
    cout << "\n数组下标越界！" << endl;
    exit(1);
  }
  return a[i];
}

template <class T> void Array<T>::Sort() {
  int p;
  for (int i = 0; i < Size - 1; i++) {
    p = i;
    for (int j = i; j < Size; j++) {
      if (a[p] < a[j])
        p = j;
    }
    T t = a[p];
    a[p] = a[i];
    a[i] = t;
  }
}
// template <> 返回类型 类模板名<特化的数据类型>::特化成员函数名(参数表){}
template <> void Array<char *>::Sort() {
  int p;
  for (int i = 0; i < Size - 1; i++) {
    p = i;
    for (int j = i + 1; j < Size; j++)
      if (strcmp(a[p], a[j]) < 0)
        p = j;
    char *t = a[p];
    a[p] = a[i];
    a[i] = t;
  }
}

int main() {
  Array<int> a1;
  Array<char *> b1;
  a1[0] = 1;
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
  
}
/*
上述代码定义了一个模板类Array，用于表示一个固定大小的数组。
首先，定义了一个私有成员变量a，它是一个大小为Size的数组，类型为模板参数T。
然后，定义了一个默认构造函数Array()，在构造函数中使用循环将数组a的所有元素初始化为0。
接下来，定义了一个成员函数operator[]，用于重载数组下标操作符[]。
该函数接受一个整数参数i，并返回数组a中索引为i的元素的引用。
在函数内部，首先判断索引是否越界，如果越界则输出错误信息并终止程序，否则返回对应元素的引用。

最后，通过特化的方式对Array类的Sort()函数进行了特殊情况的定义。
特化的定义使用了template <>关键字，表示这是一个特化的定义。
然后，通过在类模板名后面添加<特化的数据类型>来指定特化的类型。

对于char*类型的特化，函数返回类型为void，并且函数名为Array<char*>::Sort()。
*/