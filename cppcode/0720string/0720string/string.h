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

        void reserve(size_t n)
        {
            if (n <= _capacity)
                return;//小于等于不能扩啊！！
            char* tmp = new char[n+1];//记得多申请一个
            strcpy(tmp, _str);
            delete[] _str;//释放原来的内存！！！
            _str = tmp;
            _capacity = n;
        }

        void push_back(char ch)
        {
            if (_size == _capacity)
            {
                int newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
                char* tmp = new char[newcapacity];
                strcpy(tmp, _str);
                _str = tmp;
                _capacity = newcapacity;
            }
            _str[_size++] = ch;
            _str[_size] = '\0';//与数组不同，他必须要以\0结尾！！
        }

        void append(const char* str)
        {
            //不一定要重新申请空间
            //if (_size + strlen(str) > _capacity)
            //{

            //}
            //char* tmp = new char[_size + strlen(str) + 1];
            //strcpy(tmp, _str);
            //strcpy(tmp + _size, str);//tmp+数就是地址
            //delete[] _str;
            //_str = tmp;
            //_size = strlen(tmp);
            //_capacity = _size;
            // 
           // strcpy(tmp + _size, str);有个这样的用法，所以，直接在原数组增加
            if (_size + strlen(str) > _capacity)
            {
                reserve(_size + strlen(str));
            }
            strcpy(_str + _size, str);
            _size = strlen(_str);
           // _capacity = _size + strlen(str);reserve已经改了
        }

        string& operator+=(char ch)
        {
            this->push_back(ch);
            return *this;//this是地址，要得到string要解引用符号
        }
        string& operator+=(const char* str)
        {
            this->append(str);
            return *this;
        }

        void insert(size_t pos, char ch)
        {
            assert(pos <=_size);//注意是<=，因为=的时候就是尾插！
            if (_size == _capacity)
            {
                //reserve(_capacity + 1);扩容就要扩两倍！
                reserve(_capacity == 0 ? 4 : _capacity * 2);
            }
            char tmp = ch;
            for (int i = pos; i < _size; i++)
            {
                swap(tmp, _str[i]);
            }
            _str[_size++] = tmp;
            _str[_size] = '\0';
        }
        void insert(size_t pos, const char* str)
        {
            assert(pos <= _size);
            int len = strlen(str);
            while(_size + len > _capacity)
            {
                reserve(_capacity == 0 ? 4 : 2 * _capacity);
            }
           /* strcpy(_str + pos+len, _str + pos);//可以用memcpy吗？
            strcpy(_str + pos, str);*///不能用strcpy，因为有重叠部分
            memmove(_str + pos + len, _str + pos, _size - pos + 1);
           // strcpy(_str + pos, str);//可以用memmove吗？可以但是也不能用strcpy，因为会把\0复制过去！
            memcpy(_str + pos, str,len);
            _size += len;
        }

        void erase(size_t pos, size_t len = npos)
        {
            assert(pos < _size);
            /*for (int i = pos + len; i < _size; i++)
            {
                _str[i - len] = _str[i];
           }
            _size -= len;
            _str[_size] = '\0';*///没考虑npos很大的情况会越界
            if (pos + len >= _size)
            {
                _size = pos;
                _str[_size] = '\0';
                return;
            }
            for (int i = pos + len; i <= _size; i++)//小于等于，把\0也移动过来
            {
                _str[i - len] = _str[i];
            }
            _size -= len;
        }

    private:
        char* _str = nullptr;
        size_t _size = 0;
        size_t _capacity = 0;

        static const size_t npos;
    };
}