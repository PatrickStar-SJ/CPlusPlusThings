//设计一个字符串类String，通过运算符重载实现字符串的输入、输出以及+=、==、!=、<、>、>=、[
//]等运算。
#include <cstring>
#include <iostream>
using namespace std;
class String {
private:
  int length; //字符串长度
  char *sPtr; //存放字符串的指针
  void setString(const char *s2);
  friend ostream &operator<<(ostream &os, const String &s) {
    return os << s.sPtr;
  };
  friend istream &operator>>(istream &is, String &s) {
    return is >> s.sPtr;
  }; //重载输入运算符
public:
  String(const char * = "");   //申明构造函数，定义在类外。一般情况下，构造函数都放在类外定义，是为了避免重复定义的问题
  const String &operator=(const String &R) {
    length = R.length;
    strcpy(sPtr, R.sPtr);
    return *this;
  };                                         //重载赋值运算符 =
  const String &operator+=(const String &R); //字符串的连接 +=
  bool operator==(const String &R);          //字符串的相等比较 ==
  bool operator!=(const String &R);          //字符串的不等比较 !=
  bool operator!();                          //判定字符串是否为空
  bool operator<(const String &R) const;     //字符串的小于比较 <
  bool operator>(const String &R);           //字符串的大于比较 >
  bool operator>=(const String &R);          //字符串的大于等于比较

  char &operator[](int);                     //字符串的下标运算   
                                             /*
                                             加上 & 的目的是为了实现对元素的引用访问而不是复制。
                                             因为当你使用 [] 运算符来访问容器类（如数组、向量等）中的元素时，通常希望能够直接修改该元素的值，而不是创建一个副本并对副本进行操作。
                                             */
                                             
  ~String(){};
};
const String &String::operator+=(const String &R) {
  char *temp = sPtr;
  length += R.length;
  sPtr = new char[length + 1];
  strcpy(sPtr, temp);
  strcat(sPtr, R.sPtr);
  delete[] temp;
  return *this;
}
String::String(const char *str) {
  sPtr = new char[strlen(str) + 1];
  strcpy(sPtr, str);
  length = strlen(str);
};
bool String::operator==(const String &R) { return strcmp(sPtr, R.sPtr) == 0; }
bool String::operator!=(const String &R) { return !(*this == R); }
bool String::operator!() { return length == 0; }
bool String::operator<(const String &R) const {
  return strcmp(sPtr, R.sPtr) < 0;
}
bool String::operator>(const String &R) { return R < *this; }
bool String::operator>=(const String &R) { return !(*this < R); }
char &String::operator[](int subscript) { return sPtr[subscript]; }
int main() {
  String s1("happy"), s2("new year"), s3;
  cout << "s1 is " << s1 << "\ns2 is " << s2 << "\ns3 is " << s3
       << "\n比较s2和s1:"
       << "\ns2 ==s1结果是 " << (s2 == s1 ? "true" : "false")
       << "\ns2 != s1结果是 " << (s2 != s1 ? "true" : "false")
       << "\ns2 >  s1结果是 " << (s2 > s1 ? "true" : "false")
       << "\ns2 <  s1结果是 " << (s2 < s1 ? "true" : "false")
       << "\ns2 >= s1结果是 " << (s2 >= s1 ? "true" : "false");
  cout << "\n\n测试s3是否为空: ";
  if (!s3) {
    cout << "s3是空串" << endl; // L3
    cout << "把s1赋给s3的结果是：";
    s3 = s1;
    cout << "s3=" << s3 << "\n"; // L5
  }
  cout << "s1 += s2 的结果是：s1="; // L6
  s1 += s2;
  cout << s1; // L7

  cout << "\ns1 +=  to you 的结果是："; // L8
  s1 += " to you";
  cout << "s1 = " << s1 << endl; // L9
  s1[0] = 'H';
  s1[6] = 'N';
  s1[10] = 'Y';
  cout << "s1 = " << s1 << "\n"; // L10
  
  return 0;
}


/*
在重载 [] 运算符时，加上 & 的目的是为了实现对元素的引用访问而不是复制。
eg:
    class MyArray {
    private:
        int data[5];

    public:
        int& operator[](int index) {
            return data[index];
        }
    };

    int main() {
        MyArray arr;
        arr[0] = 10; // 修改第一个元素的值

        return 0;
    }


*/