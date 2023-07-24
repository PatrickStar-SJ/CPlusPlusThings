// Eg10-12.cpp
#include <iostream>
using namespace std;
class BasicException {
public:
  char *Where() { return "BasicException..."; }
};
class FileSysException : public BasicException {
public:
  char *Where() { return "FileSysException..."; }
};
class FileNotFound : public FileSysException {
public:
  char *Where() { return "FileNotFound..."; }
};
class DiskNotFound : public FileSysException {
public:
  char *Where() { return "DiskNotFound..."; }
};
int main() {
  try {
    //         .....  //程序代码
    throw FileSysException();
  } catch (DiskNotFound p) {
    cout << p.Where() << endl;
  } catch (FileNotFound p) {
    cout << p.Where() << endl;
  } catch (FileSysException p) {
    cout << p.Where() << endl;
  } catch (BasicException p) {
    cout << p.Where() << endl;
  }
  try {
    //        .....  //程序代码
    throw DiskNotFound();
  } catch (BasicException p) {
    cout << p.Where() << endl;
  } catch (FileSysException p) {
    cout << p.Where() << endl;
  } catch (DiskNotFound p) {
    cout << p.Where() << endl;
  } catch (FileNotFound p) {
    cout << p.Where() << endl;
  }
}
/*
在main()函数中，首先使用throw关键字抛出一个FileSysException异常。
然后使用try-catch语句捕获异常，按照从上到下的顺序依次匹配catch块，如果匹配到对应的异常类型，则执行相应的代码块。

由于抛出的异常是FileSysException类型，所以会匹配到第一个catch块，输出"FileSysException..."。
接着又使用throw关键字抛出一个DiskNotFound异常。同样使用try-catch语句捕获异常，按照从上到下的顺序依次匹配catch块。
由于DiskNotFound是BasicException的子类，所以输出"BasicException..."。

*/