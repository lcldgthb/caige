#define _CRT_SECURE_NO_WARNINGS
#include"string.h"
namespace bit
{
  void string::reserve(size_t n)
    {
        if (n <= _capacity)
            return;//小于等于不能扩啊！！
        char* tmp = new char[n + 1];//记得多申请一个
        strcpy(tmp, _str);
        delete[] _str;//释放原来的内存！！！
        _str = tmp;
        _capacity = n;
    }

    void string::push_back(char ch)
    {
        if (_size == _capacity)
        {
            int newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
            char* tmp = new char[newcapacity+1];
            strcpy(tmp, _str);
            _str = tmp;
            _capacity = newcapacity;
        }
        _str[_size++] = ch;
        _str[_size] = '\0';//与数组不同，他必须要以\0结尾！！
    }

    void string::append(const char* str)
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

    string& string::operator+=(char ch)
    {
        this->push_back(ch);
        return *this;//this是地址，要得到string要解引用符号
    }
    string& string::operator+=(const char* str)
    {
        this->append(str);
        return *this;
    }

    void string::insert(size_t pos, char ch)
    {
        assert(pos <= _size);//注意是<=，因为=的时候就是尾插！
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
    void string::insert(size_t pos, const char* str)
    {
        assert(pos <= _size);
        int len = strlen(str);
        while (_size + len > _capacity)
        {
            reserve(_capacity == 0 ? 4 : 2 * _capacity);
        }
        /* strcpy(_str + pos+len, _str + pos);//可以用memcpy吗？
         strcpy(_str + pos, str);*///不能用strcpy，因为有重叠部分
        memmove(_str + pos + len, _str + pos, _size - pos + 1);
        // strcpy(_str + pos, str);//可以用memmove吗？可以但是也不能用strcpy，因为会把\0复制过去！
        memcpy(_str + pos, str, len);
        _size += len;
    }

    void string::erase(size_t pos, size_t len  )
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
    size_t string::find(char ch, size_t pos )
    {
        assert(pos <= _size);//STL允许取等
        for (size_t i = pos; i < _size; i++)
        {
            if (_str[i] == ch)
                return i;
        }
        return npos;
    }
    size_t string::find(const char* str, size_t pos )
    {
        char tmp = str[0];
        int n = strlen(str);
        string s1(str);
        while (pos + n <= _size)//要取等！！
        {
            size_t index = find(tmp, pos);
            if ( index!= npos)
            {
              string s2=  substr(index, n);
              if (s1 == s2)return index;
           }
            if (index == npos)
                return npos;
            pos = index + 1;
        }
        return npos;
    }
    string string::substr(size_t pos , size_t len  )
    {
        assert(pos <= _size);
        //if (pos + len > _size)会溢出
       // len = _size - pos;
        if (len > _size - pos)
        {
            len = _size - pos;
        }
           
        char* tmp = new char[len+1];
        memcpy(tmp, _str + pos,len);
        tmp[len] = '\0';
        /*string ret;
        ret += tmp;可以优化成string ret(tmp);*/
        string ret(tmp);
        delete[] tmp;//记得释放内存
        return ret;
        //STL的写法
       /* string ret;

        ret.reserve(len);

        for (size_t i = 0; i < len; i++)
        {
            ret.push_back(_str[pos + i]);
        }

        return ret;*/
    }
    bool operator<(const string& s1, const string& s2)
    {
        size_t i = 0, j = 0;
        while (i < s1.size() && j < s2.size())
        {
            if (s1[i] == s2[j])
            {
                i++; j++;
            }else
            return s1[i] < s2[j];
        }
        return s1.size() < s2.size();
       // return strcmp(s1.c_str(), s2.c_str()) < 0;可以
    }
    bool operator<=(const string& s1, const string& s2)
    {
        return s1 < s2 || s1 == s2;
    }
    bool operator>(const string& s1, const string& s2)
    {
        return !(s1 <= s2);
    }
    bool operator>=(const string& s1, const string& s2)
    {
        return !(s1 < s2);
    }
    bool operator==(const string& s1, const string& s2)
    {
        return strcmp(s1.c_str(), s2.c_str()) == 0;
    }
    bool operator!=(const string& s1, const string& s2)
    {
        return !(s1 == s2);
    }

    ostream& operator<<(ostream& out, const string& s)
    {
        return out << s.c_str();
    }
    istream& operator>>(istream& in, string& s)
    {
        s.clear();//首先要清空
        char ch = 0;
        /*in >> ch;不能用cin，cin会自动跳过空格！！*/
        in.get(ch);
        while (ch != ' '
            && ch != '\n'
            && ch != '\t')//这些空白字符都要退出
        {
            s.push_back(ch);//要想到利用已经实现好的函数！
            in.get(ch);//同理
        }
        //由于频繁push_back(),频繁开空间，所以，可以优化一下
       // char buff[128] = { 0 };
       // int i = 0;
       // in.get(ch);
       // while (ch != ' '
       //     && ch != '\n'
       //     && ch != '\t')//这些空白字符都要退出
       // {
       //     字符串数组不以\0结尾，他会一直加，知直到\0
       //     if (i == 128)
       //     {
       //         /*s += buff;
       //         i = 0;*/
       //      
       //     }
       //     if (i == 127)
       //     {
       //         buff[i] = '\0';
       //         s += buff;
       //         i = 0;
       //     }
       //     buff[i++] = ch;
       //     in.get(ch);//同理
       // }
       // /*s += buff;不能这样写，因为buff[i]位置不一定是\0*/
       // if (i > 0)
       // {
       //     buff[i] = '\0';
       //     s += buff;
       //}
        return in;
    }
}