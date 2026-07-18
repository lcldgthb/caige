#include<iostream>
using namespace std;
int func1()
{
    return 10;
}
// 不能做参数
void func2(auto a)
{}
// 可以做返回值，但是建议谨慎使用
auto func3()
{
    return 3;
}
int main()
{
    int a = 10;
    auto b = a;
    auto c = 'a';
    auto d = func1();
    // 编译报错:rror C3531: “e”: 类型包含“auto”的符号必须具有初始值设定项
    //auto e;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    cout << typeid(d).name() << endl;
    int x = 10;
    auto y = &x;
    auto* z = &x;
    auto& m = x;
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    cout << typeid(z).name() << endl;
    auto aa = 1, bb = 2;
    // 编译报错：error C3538: 在声明符列表中，“auto”必须始终推导为同一类型
  //  auto cc = 3, dd = 4.0;
    // 编译报错：error C3318: “auto []”: 数组不能具有其中包含“auto”的元素类型
   // auto array[] = { 4, 5, 6 };
    return 0;
}
#include<iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    std::map<std::string, std::string> dict = { { "apple", "苹果" },{ "orange", 
"橙子" }, {"pear","梨"} };
    // auto的用武之地
    //std::map<std::string, std::string>::iterator it = dict.begin();
    auto it = dict.begin();
    while (it != dict.end())
    {
        cout << it->first << ":" << it->second << endl;
        ++it;
    }
      return 0;
}
#include<iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    int array[] = { 1, 2, 3, 4, 5 };
    // C++98的遍历
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
    {
        array[i] *= 2;
    }
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
    {
        cout << array[i] << endl;
    }
    // C++11的遍历
    for (auto& e : array)
        e *= 2;
    for (auto e : array)
        cout << e << " " << endl;
    string str("hello world");
    for (auto ch : str)
    {
        cout << ch << " ";
    }
    cout << endl;
    return 0;
}
