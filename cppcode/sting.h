# pragma once
#include<iostream>
#include<assert>
namespace caige
{
    class string
    {
        public:
        string()
        :_str(nullptr)
        ,_size=0
        ,_capacity(0)
        {

        }
        string(const char* str)
        {
            _size=strlen()
            _str=new char[]
        }
        char* _str;
        size_t _size;
        size_t _capacity;
    }
}