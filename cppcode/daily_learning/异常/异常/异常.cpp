#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//int main()
//{
//	
//	return 0;
//}
//
//void Func()
//{
//    try
//    {
//        throw 10;
//    }
//    catch (int e)
//    {
//        cout << "Func捕获异常：" << e << endl;
//
//        throw;
//    }
//}
//
//int main()
//{
//    try
//    {
//        Func();
//        cout << "你好！" << endl;
//    }
//    catch (int e)
//    {
//        cout << "main再次捕获：" << e << endl;
//    }
//}
class Exception
{
public:
    virtual const char* what() const
    {
        return "Exception";
    }
};
class FileException : public Exception//继承
{
public:
    const char* what() const override
    {
        return "FileException";
    }
};
//int main()
//{
//
//    try
//    {
//        throw FileException();//抛出派生类异常
//    }
//    catch (const Exception& e)//基类接收
//    {
//        cout << e.what() << endl;
//        throw;//抛出的还是派生类而不是基类！！！
//    }
//    return 0;
//}
class Base
{
public:
    virtual void Print() const
    {
        cout << "Base" << endl;
    }
};

class Derive : public Base
{
public:
    void Print() const override
    {
        cout << "Derive" << endl;
    }
};

void test01()
{
    try
    {
        throw Derive();
    }
    catch (const Base& e)
    {
        e.Print();
        throw;
    }
}
int main()
{
    try
    {
        test01();
    }
    catch (Derive& e)
    {
        cout << "Derive最终处理！" << endl;
   }
    catch (Base& e)
    {
        cout << "Base最终处理！" << endl;
    }
    catch (...)
    {
        cout << "未知异常！" << endl;
    }
    return 0;
}


