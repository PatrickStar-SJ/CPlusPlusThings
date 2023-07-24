#include <iostream>
using namespace std;
class BasicException {
public:
  virtual string Where() { return "BasicException..."; }
};
class FileSysException : public BasicException {
public:
  virtual string Where() { return "FileSysException..."; }
};
class FileNotFound : public FileSysException {
public:
  virtual string Where() { return "FileNotFound..."; }
};
class DiskNotFound : public FileSysException {
public:
  virtual string Where() { return "DiskNotFound..."; }
};
int main() {
  try {
    //        .....  //程序代码
    DiskNotFound err;
    throw &err;
  } catch (BasicException *p) {
    cout << p->Where() << endl;
  }
}
/*
这段代码定义了一个基类BasicException和其派生类FileSysException、FileNotFound、DiskNotFound。
每个派生类都重写了基类的Where()函数，返回不同的字符串。

在主函数中，try块内部创建了一个DiskNotFound类型的对象err，并通过throw语句将其抛出。
catch块使用BasicException的指针类型捕获异常，并调用Where()函数打印出异常对象所在的位置。

因为DiskNotFound是FileSysException的派生类，而FileSysException是BasicException的派生类，所以捕获并处理异常的catch块会匹配到DiskNotFound类型的异常对象，并打印出"DiskNotFound..."。
*/