# stack和queue
接口简单介绍
算法题
## stack实现
适配器 
按需实例化
deque 双端队列 vector和list的缝合怪

list和vector的优缺点

deque的简单了解
底层结构：中控数组
迭代器，四部分，first last，cur node
迭代器的++
头插，尾插

# stack和queue的使用
## 1. stack 的本质

`stack` 是一种：**后进先出（LIFO）** 的线性结构。

## 2. stack 的常用接口

| 接口 | 作用 |
|---|---|
| `stack()` | 构造空栈 |
| `empty()` | 判断是否为空 |
| `size()` | 返回元素个数 |
| `top()` | 返回栈顶元素引用 |
| `push()` | 压栈 |
| `pop()` | 弹栈 |

## 3，stack相关算法题
## 2. queue 的本质

`queue` 是一种： **先进先出（FIFO）** 的线性结构。

## 2. queue 的常用接口

| 接口 | 作用 |
|---|---|
| `queue()` | 构造空队列 |
| `empty()` | 判断是否为空 |
| `size()` | 返回元素个数 |
| `front()` | 返回队头元素引用 |
| `back()` | 返回队尾元素引用 |
| `push()` | 在队尾入队 |
| `pop()` | 在队头出队 |

---
## 3，相关经典算法题
# stack和queue的底层实现
## 容器适配器
因为我们只需要对像vector和list等容器规定只能尾插尾删就可以实现stack，所以，我们可以直接这样来实现栈
template<class T>
	class stack
	{
	public:
		void push(const T& x)
		{
			v.push_back(x);
		}
		void pop()
		{
			v.pop_back();
		}
        ......
	private:
		vector v;
	};

这里的vector也可以换成list等等，所以，我们可以加入模版
template<class T, class Container >
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		const T& top() const
		{
			return _con.back();
		}
		size_t size() const
		{
			return _con.size();
		}
		bool empty() const
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
    同理我们也可以实现队列
    template<class T, class Container >
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		const T& front() const
		{
			return _con.front();
		}

		const T& back() const
		{
			return _con.back();
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

     我们可以在这里给上缺省参数：  template<class T, class Container >，=vector和list都可以，但是你会发现库里面给的是 template<class T, class Container =deque<T>>
     deque双端队列！！vector和list的缝合怪
## vector 和 list 优缺点总结

### vector
由于连续存储，空间连续
**优点：**
- 支持随机访问（`O(1)`）
- 尾插、尾删效率高（均摊 `O(1)`）
- CPU 缓存命中率高，遍历速度快

**缺点：**
- 中间或头部插入、删除效率低（`O(n)`）
- 扩容会重新申请空间，导致迭代器失效

---

### list

**优点：**
- 任意位置插入、删除效率高（已知位置为 `O(1)`）
- 不需要连续空间，不会整体扩容
- 插入、删除不会导致其他节点迭代器失效（被删除节点除外）

**缺点：**
- 不支持随机访问，只能顺序遍历（`O(n)`）
- 每个节点额外存储两个指针，空间开销大
- 缓存命中率低，遍历速度慢
那么，我们可不可以把他们的优缺点都结合起来形成一个新的结构呢？可以——deque双端队列！
---
# deque 双端队列（了解即可，但必须要了解）
deque的底层（课件）
deque(双端队列)：是一种双开口的"连续"空间的数据结构，双开口的含义是：可以在头尾两端
进行插入和删除操作，且时间复杂度为O(1)，与vector比较，头插效率高，不需要搬移元素；与
list比较，空间利用率比较高。
deque并不是真正连续的空间，而是由一段段连续的小空间拼接而成的，实际deque类似于一个
动态的二维数组，其底层结构如下图所示：
双端队列底层是一段假象的连续空间，实际是分段连续的，为了维护其“整体连续”以及随机访问
的假象，落在了deque的迭代器身上，因此deque的迭代器设计就比较复杂，如下图所示：

## deque的迭代器
### 1、deque 迭代器包含四部分

STL 中 deque 的迭代器一般包含四个成员：
| 成员 | 含义 |
| :--- | :--- |
| first | 当前 Buffer 的起始位置 |
| last | 当前 Buffer 的结束位置（尾后位置） |
| cur | 当前元素位置 |
| node | 当前 Buffer 在中控数组中的位置 |
### 头插，尾插
### ++、--
## 总结
1、deque头插尾插效率很高，更甚于vector和list
2、下标随机访问也还不错，相比vector略逊一筹
3、中间插入删除效率很低，要挪动数据，是O（N）
刚好，完美适合我们的stack和queue，因为他们一般都不用在中间插入或者删除数据！所以，非常适合作为我们栈和队列的默认模版
# priority_queue优先级队列
## 介绍+使用
## 接口
## 底层实现（重点是仿函数）
### 仿函数
类，本质是一个类，
// 仿函数：本质是一个类，这个类重载operator(),他的对象可以像函数一样使用

# 堆的一些算法
sort_heap();is_heap();make_heap();
可以传数组的指针
## 仿函数什么时候要自己写
//	// 1、类类型不支持比较大小
//	// 2、支持比较大小，但是比较的逻辑不是你想要的
//	// 需要自己实现仿函数
这部分老师其实主要想讲 **STL 比较器为什么存在**，以及**什么时候需要自定义仿函数**。按照你的博客风格，我建议整理成下面这样即可。

---

## 自定义仿函数

前面介绍了仿函数的写法，那么什么时候需要自己编写仿函数呢？

通常有以下两种情况：

1、**类类型本身不支持比较大小。**

例如，一个类没有重载 `operator<`、`operator>` 等比较运算符，此时 STL 无法知道对象之间应该如何比较，只能自己编写仿函数来指定比较规则。

2、**支持比较大小，但是比较逻辑不是你想要的。**

例如，下面的 `Date` 类已经重载了 `<` 和 `>`，默认按照**年月日**进行比较：

```cpp
class Date
{
public:
    bool operator<(const Date& d) const
    {
        return (_year < d._year)
            || (_year == d._year && _month < d._month)
            || (_year == d._year && _month == d._month && _day < d._day);
    }

    bool operator>(const Date& d) const
    {
        return (_year > d._year)
            || (_year == d._year && _month > d._month)
            || (_year == d._year && _month == d._month && _day > d._day);
    }

private:
    int _year;
    int _month;
    int _day;
};
```

默认情况下，比较的是**日期先后**。

但如果现在希望：

* 只按照**年份**排序；
* 只按照**月份**排序；
* 按照**离今天最近**排序；

那么原来的 `operator<` 就无法满足需求，此时就可以编写不同的仿函数，实现不同的比较规则，而无需修改 `Date` 类本身。

---

## 指针类型为什么需要自定义仿函数？

还有一种比较特殊的情况，就是容器中存放的是**指针**。

例如：

```cpp
bit::priority_queue<Date*> q;
```

默认情况下，比较的是**指针地址**：

```cpp
p1 < p2
```

而不是 `Date` 对象本身的大小。

显然，我们真正想比较的是日期，因此需要自己编写仿函数：

```cpp
class DateLess
{
public:
    bool operator()(Date* p1, Date* p2)
    {
        return *p1 < *p2;
    }
};
```

这里先对指针进行解引用，再调用 `Date` 的 `operator<`，这样比较的就是对象本身，而不是地址。

使用时只需要将仿函数作为第三个模板参数传入即可：

```cpp
bit::priority_queue<Date*, vector<Date*>, DateLess> q;
```

---

## 为什么 `priority_queue<int*>` 不需要自定义仿函数？

老师上课还举了下面这个例子：

```cpp
bit::priority_queue<int*> q;

q.push(new int(2));
q.push(new int(1));
q.push(new int(3));
```

很多同学会疑惑：为什么这里没有传 `DateLess` 这样的仿函数？

实际上，**如果不传比较器，默认比较的仍然是指针地址，而不是整数的值。**

也就是说：

```cpp
new int(1)
new int(2)
new int(3)
```

默认比较的是这三个对象在内存中的地址大小：

```cpp
0x0012FF10
0x0012FF30
0x0012FF20
```

地址大小与整数值没有任何关系，因此输出结果也是**不确定的**，不能认为一定是 `3、2、1`。

如果希望按照整数值比较，同样应该编写仿函数：

```cpp
class IntLess
{
public:
    bool operator()(int* p1, int* p2)
    {
        return *p1 < *p2;
    }
};
```

然后：

```cpp
bit::priority_queue<int*, vector<int*>, IntLess> q;
```

这样比较的才是 `*p1` 和 `*p2`，也就是整数值本身。

> **总结：**
>
> 对于指针类型，STL 默认比较的是**指针地址**，而不是指针指向对象的内容。如果希望按照对象本身进行比较，就需要自定义仿函数。这样做也体现了 STL **策略与数据分离**的设计思想。
