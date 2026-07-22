# vector 01 vector的使用，后面再讲vector的实现
vector，中文：向量
vector的构造，遍历，加例子
reserve与string 不同！！
对于reserve()小于capacity时
string :
vs2022 不缩，g++4.8,会缩
vector，都不缩
void test_vector1()
{
	vector<int> v1;
	vector<int> v2(10, 1);

	vector<int> v3(++v2.begin(), --v2.end());

	for (size_t i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
}


void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	v.reserve(100);

	sz = v.capacity();
	cout << "capacity changed: " << sz << '\n';

	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_vector2()
{
	//TestVectorExpand();

	vector<int> v(10, 1);
	v.reserve(20);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(15);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

void test_vector3()
{
	//TestVectorExpand();

	vector<int> v(10, 1);
	v.reserve(20);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(15, 2);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(25, 3);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}
### 总结：vector 的基本使用、构造与 reserve、resize
- vector 本质：vector 是一种动态顺序表（动态数组），底层使用连续内存存储元素，支持随机访问和自动扩容。
- 与 string 的关系：两者设计思想高度一致，都具有 size()、capacity()、reserve()、resize()、push_back() 等接口，可以将 string 看作是面向字符的特殊动态序列（思想类似，而不是继承关系）。
- 构造方式：支持默认构造、指定元素个数和值构造、区间构造，其中 STL 的区间均遵循 左闭右开 [first, last) 的规则。
- 遍历方式：支持下标遍历、迭代器遍历和 C++11 范围 for 遍历，其中迭代器是 STL 的统一访问方式，后续所有容器和算法都会大量使用。
- reserve()：只负责调整容量（capacity），不会改变元素个数（size），并且只能扩容，不能缩容。
- resize()：负责调整元素个数（size），当元素增多且空间不足时会自动扩容；当元素减少时，仅修改 size，通常不会缩小 capacity。
- 牢记区别：reserve 管的是预留空间，resize 管的是实际元素数量，这是学习 vector 最容易混淆、也是最重要的知识点之一。

# vector 02 接口
operater[],at,
insert,eraser，只支持迭代器。
vector的比较
为什么不能用vector<char>代替string，string的优势！
vector除了int，double等，还可以存，自定义类，string，vector（二维数组）等等
void test_vector4()
{
	vector<int> v(10, 1);
	v.push_back(2);
	v.insert(v.begin(), 0);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.begin()+3, 10);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v1(5, 0);
	for (size_t i = 0; i < 5; i++)
	{
		cin >> v1[i];
	}

	for (auto e : v1)
	{
		cout << e << ",";
	}
	cout << endl;

	vector<char> v2;
	string s2;
	// \0

	vector<int> v3;
	// send(s2.c_str())
}

void test_vector5()
{
	vector<string> v1;
	string s1("xxxx");
	v1.push_back(s1);

	v1.push_back("yyyyy");
	for (const auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	// ά
	// 10*5
	vector<int> v(5, 1);
	vector<vector<int>> vv(10, v);
	vv[2][1] = 2;
	// vv.operator[](2).operator[](1) = 2;
	for (size_t i = 0; i < vv.size(); i++)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//template<class T>
//class vector
//{
//	T& operator[](int i)
//	{
//		assert(i < _size);
//
//		return _a[i];
//	}
//private:
//	T* _a;
//	size_t _size;
//	size_t _capacity;
//};

// vector<int>
//class vector
//{
//	int& operator[](int i)
//	{
//		assert(i < _size);
//
//		return _a[i];
//	}
//private:
//	int* _a;
//	size_t _size;
//	size_t _capacity;
//};
//
//// vector<vector<int>>
//class vector
//{
//	vector<int>& operator[](int i)
//	{
//		assert(i < _size);
//
//		return _a[i];
//	}
//private:
//	vector<int>* _a;
//	size_t _size;
//	size_t _capacity;
//};

### 总结：vector 常用接口与设计思想
operator[] 与 at()：两者都用于访问元素，operator[] 速度快但通常不进行越界检查；at() 会进行边界检查，越界时抛出 std::out_of_range 异常，更安全。
insert() 与 erase()：都以迭代器作为位置参数，这是 STL 为了统一所有容器接口而设计的。由于底层需要移动元素，因此在 vector 中时间复杂度通常为 O(n)。
vector 支持比较运算：支持 ==、!=、<、<=、>、>= 等运算，其中 < 等关系运算采用字典序比较。
不能完全用 vector<char> 替代 string：vector<char> 可以存放字符，但不会自动维护 '\0'，缺少丰富的字符串操作接口，也没有许多 string 实现中的专门优化（如 SSO），因此 string 更适合表示和处理文本。
本节体现的 STL 思想：模板实现泛型、迭代器统一访问方式、运算符重载提升易用性、容器隐藏底层实现细节，这些思想贯穿整个 STL。

# vector 03 二维数组
二维数组，本质
模版实例化了两个类，一个是vector<int>,一个是vector<vector<int>>

算法题:杨辉三角
1,C语言的实现：指针数组，malloc
2，vector二维数组

## 本节总结：vector 二维数组
vector<vector<int>> 本质是 外层 vector 存放多个 vector<int> 对象，并不是一整块连续的二维内存。
模板会实例化两个类：vector<int> 和 vector<vector<int>>。
vv[i] 返回 vector<int>&，vv[i][j] 再调用一次 operator[]，最终返回 int&，因此支持直接赋值。
vv[i][j] 等价于 vv.operator[](i).operator[](j)。
杨辉三角的核心规律是：首尾为 1，中间元素 = 上一行相邻两个元素之和，实现时注意访问上一行应使用 ret[i-2]，这是最容易出错的地方。

# 03 实现
候捷老师，老师建议我们可以看书，跟着老师学习，独立思考和解决问题能力不足，
学习C++推荐的三本书
STL源码剖析，
C++Prinmer
C++effective

简单看一下源码：
先看类，看变量，看构造函数
三个指针，start,finsh,end_of_storage;
未来工作，都要靠自己，所以要提升思考能力，解决问题能力，学习能力，搜索能力，工程文件之间类联系比较大，所以，比较难，但要培养自己这方面的能力。
当前阶段不建议看太多，能力还不够！

## 本节总结：STL源码学习（03）——初识 STL 源码与学习方法
学习 STL 源码的目的不是背代码，而是学习优秀类的设计思想，理解容器为什么这样实现。
推荐阅读三本经典书籍：《STL源码剖析》《C++ Primer》《Effective C++》，分别侧重底层实现、语言基础和编程实践。
阅读源码时遵循 "先看类 → 再看成员变量 → 再看构造函数 → 最后看成员函数" 的顺序，不要一开始陷入模板细节。
vector 的核心成员变量通常是三个指针：start、finish、end_of_storage，它们分别表示数据起始位置、有效数据结束位置和整个存储空间结束位置。
当前阶段不必强行阅读完整 STL 源码，应先掌握容器使用和简化实现，再逐步阅读真实源码。
比阅读源码更重要的是培养程序员的核心能力：独立思考能力、解决问题能力、持续学习能力、搜索能力以及阅读大型工程代码的能力。这些能力才是未来学习新技术和参与实际项目开发的基础。

# 04，自己实现vector

## 八、本次知识点总结
operator[] 返回的是元素引用（T&），不是指针。
_start 是指向动态数组首元素的指针，而不是数组名，但可以像数组一样使用 []。
p[i] 本质等价于 *(p+i)。
p+1 表示移动 1 个元素，编译器会自动乘 sizeof(T)。
STL（vector、string、算法、迭代器等）中的指针运算，全部都是以元素为单位，而不是字节为单位。
实现模板类时，要始终牢记 T 可能是任意类型，不能按内置类型的思维去实现。
