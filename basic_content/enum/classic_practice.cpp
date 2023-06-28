#include <iostream>
using namespace std;
/**
 * @brief namespace解决作用域不受限
 */
namespace Color {
enum Type { RED = 15, YELLOW, BLUE };
};

/**
 * @brief 上述如果 using namespace Color 后，前缀还可以省去，使得代码简化。
 * 不过，因为命名空间是可以随后被扩充内容的，所以它提供的作用域封闭性不高。
 * 在大项目中，还是有可能不同人给不同的东西起同样的枚举类型名。
 * 更“有效”的办法是用一个类或结构体来限定其作用域。
 *
 * 定义新变量的方法和上面命名空间的相同。
 * 不过这样就不用担心类在别处被修改内容。
 * 这里用结构体而非类，一是因为本身希望这些常量可以公开访问，
 * 二是因为它只包含数据没有成员函数。
 */
struct Color1 {
  enum Type { RED = 102, YELLOW, BLUE };
};

/**
 * @brief C++11的枚举类
 * 下面等价于enum class Color2:int
 */
enum class Color2 { RED = 2, YELLOW, BLUE };

enum class Color3 : char; // 前向声明

// 定义
enum class Color3 : char { RED = 'r', BLUE };

int main() {
  // 定义新的枚举变量
  Color::Type c = Color::RED;
  cout << c << endl;
  /**
   * 上述的另一种方法：
   * using namespace Color; // 定义新的枚举变量
   * Type c = RED;
   */
  Color1 c1;
  cout << c1.RED << endl;

  Color1::Type c11 = Color1::BLUE;
  cout << c11 << endl;

  Color2 c2 = Color2::RED;
  //枚举类的枚举值是以类型为`Color2`的枚举成员进行存储的，所以需要使用`static_cast<int>`进行类型转换，并将其输出，得到2。
  //`c2` 是一个 `enum class` 类型的枚举变量，它不能直接输出到 `cout` 流。为了输出 `c2` 的值，需要将其转换为整数类型
  cout << static_cast<int>(c2) << endl;  
//   cout << c2 << endl; //error

  //定义字符类型的变量`c3`，并将`Color3::RED`进行类型转换，并将其输出，得到'r'。注意，这里枚举值被存储为字符类型。
  //`Color3::RED` 是一个 `enum class Color3` 类型的枚举值，它不能直接赋给 `char` 类型的变量。需要进行类型转换
  char c3 = static_cast<char>(Color3::RED);
  cout << c3 << endl;
  return 0;
}

/*
首先，在命名空间`Color`中定义了一个枚举`Type`，其中`RED`的值是15，`YELLOW`的值是16，`BLUE`的值是17。注意，这些枚举值是以默认的整数类型进行存储的。

接下来，定义了一个结构体`Color1`，内部也有一个枚举`Type`，但是`RED`的值被重新定义为102，`YELLOW`的值是103，`BLUE`的值是104。同样地，这些枚举值也是以默认的整数类型进行存储的。

然后，定义了一个名为`Color2`的枚举类(enum class)，其中`RED`的值是2，`YELLOW`的值是3，`BLUE`的值是4。
**不同于前面的两个枚举，枚举类中的枚举值是以类型为`Color2`的枚举成员进行存储的!!!!**

紧接着，使用前向声明声明了一个名为`Color3`的枚举类(enum class)。前向声明只告诉编译器该枚举类型的存在，并不给出具体的定义。在后续代码中，对`Color3`进行了再次定义，其中`RED`的值被定义为字符'r'，`BLUE`的值按照默认递增规则进行存储。


执行结果：
15
102
104
2
r
*/
