#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <utility>
using namespace std;
namespace caige
{
    template<class T>
    class MyUniquePtr
    {
    public:
        // 1. 构造函数
        explicit MyUniquePtr(T* ptr = nullptr)
            : _ptr( )
        {
        }

        // 2. 析构函数
        ~MyUniquePtr()
        {
            
        }

        // 3. 解引用
        T& operator*()
        {
           
        }

        // 4. -> 运算符
        T* operator->()
        {
           
        }

        // 5. 禁止拷贝构造
        MyUniquePtr(const MyUniquePtr& other) = delete;

        // 6. 禁止拷贝赋值
        MyUniquePtr& operator=(const MyUniquePtr& other) = delete;

        // 7. 移动构造
        MyUniquePtr(MyUniquePtr&& other) noexcept
            : _ptr( )
        {
           
        }

        // 8. get()
        T* get() const
        {
            
        }

        // 9. reset()
        void reset(T* ptr = nullptr)
        {
            
        }

    private:
        T* _ptr;
    };
    template<class T>
    class MySharedPtr
    {
    public:
        // 1. 构造函数
        explicit MySharedPtr(T* ptr = nullptr)
            : _ptr(ptr)
            , _pcount(new size_t(1) )
        {
        }

        // 2. 析构函数
        ~MySharedPtr()
        {
            if ((*_pcount) == 1)
            {
                delete _ptr;
                delete _pcount;
            }
            else
            (*_pcount)--;
        }

        // 3. 拷贝构造
        MySharedPtr(const MySharedPtr& sp)
            : _ptr(sp._ptr )
            , _pcount(sp._pcount )
        {
            (*_pcount)++;
        }

        // 4. 拷贝赋值
        MySharedPtr& operator=(const MySharedPtr& sp)
        {
            if (this != &sp)
            {
                // 先释放原来的资源
                if ((*_pcount) == 1)
                {
                    delete _ptr;
                    delete _pcount;
                }
                else
                    (*_pcount)--;
                    // 再共享 sp 的资源
                _ptr = sp._ptr;
                _pcount = sp._pcount;
                (*sp._pcount)++;
            }

            return *this;
        }

        // 5. 解引用
        T& operator*() const
        {
            return *_ptr;
        }

        // 6. ->
        T* operator->() const
        {
            //return->_ptr;
            return ptr;
        }

        // 7. 获取引用计数
        size_t use_count() const
        {
            return *_pcount;
        }

    private:
        T* _ptr;          // 管理的资源
        size_t* _pcount;  // 引用计数
    };
}
//template<class T>
//class shared_ptr
//{
//public :
//    shared_ptr(T* ptr)
//        ;_ptr(ptr)
//        ,_pcount(new int(1))
//    { }
//    shared_ptr(const shared_ptr& p)
//        :_ptr(p._ptr)
//        , _pcount(p._pcount)
//    {
//        ++(*_pcount);
//    }
//    ~shared_ptr()
//    {
//        if (--(*_pcount) == 0)
//        {
//            delete _ptr;
//            delete _pcount;
//        }
//    }
//private:
//    T* _ptr;
//    int* _pcount;
//}
int main()
{

	return 0;
}

