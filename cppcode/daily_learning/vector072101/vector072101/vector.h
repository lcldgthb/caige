#pragma once
#pragma once
#include <assert.h>

namespace caige
{
    template<class T>//涉及模版，所以，声明和定义必须放到同一个文件里
    class vector
    {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;

        // 迭代器
        iterator begin()
        {
            return _start;
        }
        iterator end()
        {
            return _finish;
        }
        const_iterator begin() const
        {
            return _start;
        }
        const_iterator end() const
        {
            return _finish;
        }
        //类成员函数可以访问类的私有变量！！！，不需要接口
       /* iterator _capacity()
        {
            return _end_of_storage;
        }
        void swap(vector<T>&v)
        {
            std::swap(_start , v.begin());
            std::swap(_finish , v.end());
            std::swap(_end_of_storage , v._capacity());
        }*/
        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }
        // 构造/析构
        vector()
            : _start(nullptr)
            , _finish(nullptr)
            , _end_of_storage(nullptr)
        {

        }
        vector(size_t n, const T& value = T())
        {
            T* tmp = new T[n];
            for (int i = 0; i < n; i++)
            {
                tmp[i] = value;
            }
            _start = tmp;
            _finish = _start + n;
            _end_of_storage = _finish;
        }
        template<class InputIterator>
        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*first);
                first++;
            }
        }

        vector(const vector<T>& v)//注意这里是const，不能用swap
        {
            T* tmp = new T[v.capacity()];
            for (size_t i = 0; i < v.size(); i++)
            {
                tmp[i] = v[i];
            }
            _start = tmp;
            _finish = tmp + v.size();
            _end_of_storage = tmp + v.capacity();
        }
        //注意这里是拷贝构造，所以，不能用
       /* vector(vector<T> v) 
        {
            swap(v);
        }*/
        vector<T>& operator=(const vector<T>& v)
        {
            vector<T> tmp(v);
            swap(tmp);
            return *this;
        }
        ~vector()
        {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }
      
        // 容量
        size_t size() const
        {
            return _finish - _start;
        }
        size_t capacity() const
        {
            return _end_of_storage - _start;
        }
        bool empty() const
        {
            return _start == _finish;
        }

        void reserve(size_t n)
        {
            if (n >capacity())
            {
                size_t old_size = size();
             //   T tmp = new T[n];,注意new出来的要用指针接收
                T* tmp = new T[n];
              //  memcpy(tmp, _start,old_size);注意第三个参数是字节数而不是大小！！
               // memcpy(tmp, _start, old_size*sizeof(T));不能用memcpy，因为如果是string等类就会发生浅拷贝，拷贝地址！！
                for (size_t i = 0; i < old_size; i++)
                {
                    tmp[i] = _start[i];
                }
                delete[] _start;
                _start = tmp;
               // _finish = tmp + size();这样的话，finsh就一定为空了
                _finish = tmp + old_size;
                _end_of_storage = tmp + n;
               // delete[] tmp;不可以delete 因为这块空间已经是_start指向的了
            }
        }
        void resize(size_t n, const T& value = T())
        {
            if (n <= size())
            {
                _finish = _start + n;
            }
            else 
            {
                if (n > capacity())
                {
                    reserve(n);
                }
                while (_finish-_start<n)
                {
                    *(_finish++) = value;
               }
            }
        }

        // 修改
        void push_back(const T& x)
        {
            if (capacity() == size())
            {
                reserve(capacity() == 0 ? 4 : capacity() * 2);
            }
            *_finish = x;
            _finish++;
        }
        void pop_back()
        {
            //要判空
            if (size() == 0)
                return;
            _finish--;
        }

        iterator insert(iterator pos, const T& x)//注意这里的pos是迭代器不是下标！！！
        {
            assert(pos>=_start&&pos <= _finish);
            size_t index = pos - _start;//扩容后pos不可用了！！！！！！！
            if (_finish ==_end_of_storage)
            {
                reserve(capacity() == 0 ? 4 : capacity() * 2);
            }

            //for (size_t i = _finish; i > pos; i--)
            //{
            //   // _start[i] = _start[i - 1];
            //   
            //}
            
            iterator tmp = _finish;
            while (tmp >_start+index)
            {
                *(tmp) = *(--tmp);
               // *(tmp) = *(tmp - 1);
            }
           // _start[pos] = x;
            *(_start+index) = x;
            _finish++;
            //return this;返回迭代器啊喂！！！
            return _start + index;//返回插入的元素的迭代器！！
        }
        iterator erase(iterator pos)//删除当前元素
        {
            assert(pos < _finish && pos >= _start);
          /*  for (size_t i = pos; i < size(); i++)
            {
                _start[i - 1] = _start[i];
            }*/
            iterator tmp = pos;
            while (tmp < _finish-1)
            {
                *(tmp) = *(++tmp);
            }
            _finish--;
            //return this;返回迭代器啊喂！！！
            return pos;
        }

        // 元素访问
        T& operator[](size_t i)
        {
            assert(i < size());
           // return _start + size();为什么这里错了，这里返回的是什么？
            //_start是首元素的地址，_start+1是指针运算，*(_start+1)=_start[1]
            return _start[i];//为什么可以用[]?哦，因为_start是T*,T*类型就是T指针，那么，_start就是T类型数组的数组名（不准确），可以通过[]访问
            //还要注意，这里的T不能默认是内置类型，还可能是string等类型，

            // _start 是 T*，指向动态数组的首元素。
            // 指针也可以使用 [] 运算符，因为 p[i] 本质上等价于 *(p + i)。
            // 返回 T& 而不是 T，这样既避免拷贝，又可以支持 v[i] = x 的修改操作。
            // 注意：T 不一定是内置类型，还可能是 string、vector 或自定义类型，
            // 所以这里不能假设 T 是 int、char 等基本类型。
        }
        const T& operator[](size_t i) const
        {
            assert(i < size());
            return *(_start + i);
        }

    private:
        iterator _start=nullptr;
        iterator _finish=nullptr;
        iterator _end_of_storage=nullptr;
    };

    template<class T>
    void print_vector(const vector<T>& v)
    {
        for (auto it : v)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    template<class T>
    void print_content(const T& t)
    {
        for (auto it : t)
        {
            cout << *it << ' ';
        }
        cout << endl;
    }


    void test_vector1();
    void test_vector2();
}