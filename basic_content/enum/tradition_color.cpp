#include <iostream>
using namespace std;

enum Color { RED, BLUE };
enum Feeling { EXCITED, BLUE };

int main() {
  Color a = BLUE; // error 。Color和Feeling都定义了BLUE值，导致编译器无法确定BLUE指的是哪个枚举类型的成员。
  Feeling b = EXCITED;
  std::cout << a << ":" << b << std::endl;
  return 0;
}
