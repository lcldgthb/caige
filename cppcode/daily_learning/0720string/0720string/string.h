#define _CRT_SECURE_NO_WARNINGS
// #pragma once
//#include<iostream>
//#include<assert.h>
//namespace caige
//{
//	class string
//	{
//
//    public:
//		string()
//            :_str(new char[1])
//            ,_size(0)
//            ,_capacity(0)
//		{}
//		string(const char* str)
//		{
//            if (str == nullptr)
//                str = "";
//			_size = strlen(str);//strlen不包括/0
//			_str = new char[_size+1];//开空间要多开一个放/0
//            strcpy(_str,str);
//			_capacity = _size;
//		}
//        string(const char* str="")
//        {
//            _size = strlen(str);//strlen不包括/0
//            _str = new char[_size + 1];//开空间要多开一个放/0
//            strcpy(_str, str);
//            _capacity = _size;
//        }
//        ~string()
//        {
//            delete[] _str;
//            _size = 0;
//            _capacity = 0;
//        }
//        size_t size()
//        {
//            return _size;
//        }
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//}
#pragma once

#include <iostream>
#include <string>
#include <assert.h>
#include<string.h>

using namespace std;

namespace bit
{
    class string
    {
    public:
        typedef char* iterator;
        typedef const char* const_iterator;

        iterator begin()//名字必须是这个才能用范围for遍历，范围for只是简单的替换！
        {
            return _str;
        }
        iterator end()//名字必须是这个才能用范围for遍历
        {
            return _str + _size;//刚好就是最后一个元素的后一个
        }

        const_iterator begin() const
        {
            return _str ;
        }
        const_iterator end() const
        {
            return _str + _size;
        }

        string(const char* str = "")
        {
            _size = strlen(str);//strlen不包括/0
            _str = new char[_size + 1];//开空间要多开一个放/0
            strcpy(_str, str);
            _capacity = _size;
        }

        ~string()
        {
            delete[] _str;
            _size = 0;
            _capacity = 0;
        }
       /* string string(string str)拷贝构造不用写返回值
        {

        }*/
        string(const string& str)
        {
            char* tmp = new char[str.capacity()+1];
            strcpy(tmp, str.c_str());
            _str = tmp;
            _size = str.size();
            _capacity = str.capacity();
           /* delete[] tmp;不要delete！！！*/
        }
        const char* c_str() const
        {
            return _str;
        }

        void clear()
        {
            _size = 0;
            _str[0] = '\0';//如果没有，则调用s.c_str()还是会输出原字符串
        }

        size_t size() const
        {
            return _size;
        }
        size_t capacity() const
        {
            return _capacity;
        }

        char& operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }
        const char& operator[](size_t pos) const 
        {
            assert(pos < _size);
            return _str[pos];
        }
        void reserve(size_t n);
        void push_back(char ch);
        void append(const char* str);
        string& operator+=(char ch);
        string& operator+=(const char* str);
        void insert(size_t pos, char ch);
        void insert(size_t pos, const char* str);
        //默认参数必须写在声明，并且声明定义分开写，只能写在声明
        void erase(size_t pos, size_t len =npos);
        size_t find(char ch, size_t pos = 0);
        size_t find(const char* str, size_t pos=0 );
        string substr(size_t pos=0 , size_t len=npos);
    private:
        char* _str = nullptr;
        size_t _size = 0;//有效字符的数量，不包括\0
        size_t _capacity = 0;//用户可用的空间大小而不是申请的空间大小！
        static const size_t npos=-1;
       // static const int n=1;可以
       //    static const double d;可以
       // static const double d = 0.1;不行
       
    };
    //全局函数放到类外
    bool operator<(const string& s1, const string& s2);
    bool operator<=(const string& s1, const string& s2);
    bool operator>(const string& s1, const string& s2);
    bool operator>=(const string& s1, const string& s2);
    bool operator==(const string& s1, const string& s2);
    bool operator!=(const string& s1, const string& s2);

    ostream& operator<<(ostream& out, const string& s);
    istream& operator>>(istream& in, string& s);
}