#  map和set的使用

## 1. 序列式容器和关联式容器
总结：
序列式容器：逻辑为线性结构，两个位置的值之间没有关系，例如，string，vector，list等等
关联式容器：逻辑非线性结构，两个位置的值之间有关系，例如，二叉搜索树（map/set）
前面我们已经接触过 STL 中的部分容器如：string、vector、list、deque、array、forward_list 等，这些容器统称为序列式容器，因为逻辑结构为线性序列的数据结构，两个位置存储的值之间一般没有紧密的关联关系，比如交换一下，它依旧是序列式容器。顺序容器中的元素是按它们在容器中的存储位置来顺序保存和访问的。

关联式容器也是用来存储数据的，与序列式容器不同的是，关联式容器逻辑结构通常是非线性结构，两个位置有紧密的关联关系，交换一下，它的存储结构就被破坏了。顺序容器中的元素是按关键字来保存和访问的。关联式容器有 map/set 系列和 unordered_map/unordered_set 系列。
普通二叉树————满足左小于根，右大于根——>普通二叉搜索树+优化，降低高度——>红黑树——分为set（key场景）/map（key/value场景）



## 2. set系列的使用

### 2.1 set和multiset参考文档

<https://legacy.cplusplus.com/reference/set/>

### 2.2 set类的介绍
总结：
1，set<T,Lesser<T>>即，一般就直接set<T>,默认小根，如果要大根，set<Greater<T>>
2，增删查效率是 **O(logN)，不支持改！！**，
- set 的声明如下，T 就是 set 底层关键字的类型。
- set 默认要求 T 支持小于比较，如果不支持或者想按自己的需求走可以自行实现仿函数传给第二个模板参数。
- set 底层存储数据的内存是从空间配置器申请的，如果需要可以自己实现内存池，传给第三个参数。
- 一般情况下，我们都不需要传后两个模板参数。
- set 底层是用红黑树实现，增删查效率是 **O(logN)**，迭代器遍历是走的搜索树的中序，所以是有序的。
- 前面部分我们已经学习了 vector/list 等容器的使用，STL 容器接口设计高度相似，所以这里我们就不再一个接口一个接口地介绍，而是直接带着大家看文档，挑比较重要的接口进行介绍。

```cpp
template < class T,                        // set::key_type/value_type
           class Compare = less<T>,        // set::key_compare/value_compare
           class Alloc = allocator<T>      // set::allocator_type
           > class set;
```

### 2.3 set的构造和迭代器
#### 1，构造
set<int> s1;//默认构造
set<int> s2(s1);//拷贝构造
set<int> s3(s1.begin(),s1.end());//迭代器区间构造
set<int> s4={1,5,3,7};//初始化列表构造
#### 2，迭代器
1，set是双向迭代器，所以有begin()/rbegin(),end()/rend();
2，set的迭代器不支持修改数据
3，范围for遍历采用中序遍历，遍历是有序的

### 2.4 set的增删查
#### 1，插入insert

1，insert插入元素
```cpp
s.insert(10);//set不允许插入重复元素
//迭代器插入
set<int> s1={1,2,3,5,6};
s.insert(s1.begin(),s1.end());
// 插入一段 initializer_list 列表值，已经存在的值插入失败
 s.insert({ 2,8,3,9 });
```

#### 2，删除eraser

1，erase按照key删除

```cpp
s.erase(10);
```

2，erase按照迭代器删除

```cpp
auto it=s.begin();
s.erase(it);
```
3，erase按照迭代器区间删除
```cpp
s.erase(s.begin(),s.end());
```
注意：删除后迭代器失效！！！
#### 3，clear清空所有元素

```cpp
s.clear();
```
#### 4，查找find

1，find查找元素

```cpp
auto it=s.find(key);
```
返回：
1，找到：返回元素迭代器
2，未找到：返回end()
这里注意，库里面也用一个find，但是效率太慢了（O(N)），优先使用set的find函数接口
```cpp
// 算法库的查找 O(N)
    auto pos1 = find(s.begin(), s.end(), x);
    // set 自身实现的查找 O(logN)
    auto pos2 = s.find(x);
    //find和eraser的配合
     // 直接查找再利用迭代器删除 x
    cin >> x;
    auto pos = s.find(x);
    if (pos != s.end())
    {
        s.erase(pos);
    }
    else
    {
        cout << x << "不存在!" << endl;
    }
```
相似的：
二叉搜索树类的STL的find都用自己的
list有list.sort和list.reverse，所以，list可以用自己的sort和reverse
所有容器的swap，都优先使用容器.swap，而不是库里的swap
优先使用库里的情况：
1，vector/string没有reverse，所以只能用库里的,list用自己的
总之，容器自己实现了肯定优先使用容器的
#### 5，count统计元素个数

```cpp
s.count(key);
```
因为set不允许重复：所以只能返回0（不存在）和1（存在）
1，存在：1
2，不存在：0
主要运用：查看是否存在某个key
```cpp
 // 利用 count 间接实现快速查找
    cin >> x;
    if (s.count(x))
    {
        cout << x << "在!" << endl;
    }
    else
    {
        cout << x << "不存在!" << endl;
    }
```
#### 6，范围查找——lower_bound和upper_bound

1，lower_bound

```cpp
auto it=s.lower_bound(key);
```
返回第一个大于等于key的元素

2，upper_bound

```cpp
auto it=s.upper_bound(key);
```
返回第一个大于key的元素
#### 运用————找到这样一个区间：[30, 60]
```cpp
    std::set<int> myset;
    for (int i = 1; i < 10; i++)
        myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90 
    // 实现查找到的 [itlow, itup) 包含 [30, 60] 区间
    // 返回 >= 30的第一个迭代器log(N)；
    auto itlow = myset.lower_bound(30);
    // 返回 > 60的第一个迭代器log(N)
    auto itup = myset.upper_bound(60);
    // 删除这段区间的值
    myset.erase(itlow, itup);
```

### 2.7 multiset和set的差异
1，头文件同一个
multiset 和 set 的使用基本完全类似，主要区别点在于 multiset 支持值冗余，
3， insert/find/count/erase 都围绕着支持值冗余有所差异，具体参看下面的样例代码理解。
multiset：
find，找中序的第一个
eraser 全部删掉
cont 有几个返回几个
```cpp
#include<iostream>
#include<set>
using namespace std;

int main()
{
    // 相比 set 不同的是，multiset 是排序，但是不去重
    multiset<int> s = { 4,2,7,2,4,8,4,5,4,9 };

    auto it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    // 相比 set 不同的是，x 可能会存在多个，find 查找中序的第一个
    int x;
    cin >> x;
    auto pos = s.find(x);
    while (pos != s.end() && *pos == x)
    {
        cout << *pos << " ";
        ++pos;
    }
    cout << endl;

    // 相比 set 不同的是，count 会返回 x 的实际个数
    cout << s.count(x) << endl;

    // 相比 set 不同的是，erase 给值时会删除所有的 x
    s.erase(x);

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
```
## 3，set相关的简单算法题
### 两个数组的交集⭐⭐

#### 题目链接

[两个数组的交集](https://leetcode.cn/problems/intersection-of-two-arrays/description/)

---

#### 题目描述

给定两个数组 `nums1` 和 `nums2`，返回它们的交集。结果中的每个元素必须是唯一的，返回结果可以按照任意顺序。

---

#### 解题思路

利用 `set` 的去重和查找特性。先将第一个数组中的元素存入 `set`，然后遍历第二个数组，如果元素存在于第一个 `set` 中，则加入结果 `set`，最后转换成 `vector` 返回。

---

#### 解题代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // 存储 nums1 中的元素，自动去重
        set<int> s1;

        // 存储最终交集，保证结果唯一
        set<int> ret;

        // 将 nums1 中所有元素加入集合
        for (auto it : nums1)
            s1.insert(it);

        // 判断 nums2 中的元素是否存在于 nums1 集合中
        for (auto it : nums2)
        {
            if (s1.count(it))
                ret.insert(it);
        }

        vector<int> rret;

        // set 转换为 vector
        for (auto it : ret)
            rret.push_back(it);

        return rret;
    }
};
```

---

#### 解题思路2

利用 `set` 自动去重并排序的特点。

先分别将两个数组转换成 `set`，然后使用两个迭代器同时遍历两个集合：

- 如果两个元素相等，说明找到交集，加入结果。
- 如果当前 `nums1` 的元素较小，则移动 `nums1` 的迭代器。
- 否则移动 `nums2` 的迭代器。

类似归并排序中的双指针思想。

---

#### 解题代码

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> s1;
        set<int> s2;

        vector<int> ret;

        // 保存 nums1 中的元素，自动去重并排序
        for (int x : nums1)
        {
            s1.insert(x);
        }

        // 保存 nums2 中的元素，自动去重并排序
        for (int x : nums2)
        {
            s2.insert(x);
        }

        // 两个 set 同时遍历
        auto cur1 = s1.begin();
        auto cur2 = s2.begin();

        while (cur1 != s1.end() && cur2 != s2.end())
        {
            if (*cur1 == *cur2)
            {
                // 找到公共元素
                ret.push_back(*cur1);

                cur1++;
                cur2++;
            }
            else
            {
                // 小的元素不可能再匹配，移动较小的一方
                if ((*cur1) < (*cur2))
                    cur1++;
                else
                    cur2++;
            }
        }

        return ret;
    }
};
```
  
### 环形链表 II⭐⭐⭐

#### 题目链接

[环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/description/)

---

#### 题目描述

给定一个链表的头节点 `head`，判断链表是否存在环。如果存在环，返回环的入口节点；如果不存在环，返回 `nullptr`。

---

#### 解题思路

使用 `set` 记录已经访问过的节点地址。

遍历链表时，如果当前节点已经存在于 `set` 中，说明之前访问过该节点，即链表形成环，当前节点就是环的入口。

如果遍历结束仍未重复，则说明不存在环。

---

#### 解题代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(0), next(NULL) {}
 * };
 */

class Solution {
    typedef struct ListNode listnode;

public:

    typedef struct ListNode ListNode;

    ListNode *detectCycle(ListNode *head) {

        // 保存已经访问过的节点地址
        set<ListNode*> s1;

        auto it = head;

        while (it)
        {
            // 如果节点已经访问过，说明进入环
            if (s1.count(it))
                return it;

            // 记录当前节点
            s1.insert(it);

            // 继续向后遍历
            it = it->next;
        }

        // 遍历结束，没有环
        return it;
    }
};
```

---

没懂？看看大神的解题代码！！

#### 大神解题代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(0), next(NULL) {}
 * };
 */

class Solution {
public:

    ListNode *detectCycle(ListNode *head) {

        if (head == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // 快慢指针判断是否有环
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                // 找环入口
                ListNode* cur = head;

                while (cur != slow)
                {
                    cur = cur->next;
                    slow = slow->next;
                }

                return cur;
            }
        }

        return nullptr;
    }
};
```

## 3. map系列的使用

### 3.1 map和multimap参考文档

<https://legacy.cplusplus.com/reference/map/>

### 3.2 map类的介绍
与set几乎一样，只是第一个参数变成了pair类型
map<pair<T1,T2>> mp;
mp<pair<T1,T2>,greater<T>>mp;
第一个参数是一个pair类型，第二个是仿函数


### 3.3 pair类型介绍(以后常用)
map里面的pair，本质上就是：用一个结构体把两个值封装起来了
```cpp
typedef pair<const Key, T> value_type;//注意，mp里面的第一个参数是const修饰的，不能修改哦，普通的pair是可以修改的
```
普通pair的底层实现
```cpp
template <class T1, class T2>
struct pair
{
    typedef T1 first_type;
    typedef T2 second_type;
    T1 first;
    T2 second;
    pair()
        : first(T1()), second(T2())
    {}

    pair(const T1& a, const T2& b)
        : first(a), second(b)
    {}

    template<class U, class V>
    pair(const pair<U, V>& pr)
        : first(pr.first), second(pr.second)
    {}
};

template <class T1, class T2>
inline pair<T1, T2> make_pair(T1 x, T2 y)
{
    return (pair<T1, T2>(x, y));
}
```
这里库提供了一个make_pair函数，
```cpp
pair<string string> p=make_pair("ac","bada");
//同时，C++11支持隐式类型转换，比如，我们后面写insert的时候就可以：
// C++11
	dict.insert({ "auto", "自动的" });
```
### 3.4 map的构造
```cpp
    map<string, string> dict;//默认构造
    pair<string, string> kv1("first", "第一个");
    map<string ,string> m2={kv1};//使用pair插入初始化
    //map<string string> m1(kv1);没有这种构造哦
	map<string, string> dict = { {"left", "左边"}, {"right", "右边"}, {"insert", "插入"},{ "string", "字符串" } };//使用初始化列表构造
    map<string,string> dict2(dict1.begin(),dict1.end());//迭代器构造
    map<string,string> dict2(m1);//拷贝构造	
```
map的迭代器等与set一致
map 支持正向和反向迭代遍历，遍历默认按 key 的升序顺序，因为底层是二叉搜索树，迭代器遍历走的中序；支持迭代器就意味着支持范围 for。map 支持修改 value 数据，不支持修改 key 数据，修改关键字数据会破坏底层搜索树的结构。

### 3.5 map的增删查

#### 1，插入insert

```cpp
map<int,string> m;
//插入pair
m.insert(pair<int,string>(1,"张三"));
//C++11支持隐式类型转换，所以支持这种写法
m.insert({2,"李四"});
````
注意；
1，map不允许插入重复key
2，key会自动排序
3，value可以重复

2，插入一段迭代器区间
```cpp
map<int,string> m1=
{
    {1,"a"},
    {2,"b"},
    {3,"c"}
};
map<int,string> m2;
m2.insert(m1.begin(),m1.end());
```
3，插入initializer_list列表值
```cpp
m.insert({
    {4,"d"},
    {5,"e"}
});
```
注意：
如果key已经存在，插入失败，不会覆盖原来的value

---

#### 2，删除erase

1，erase按照key删除

```cpp
m.erase(1);
0 //删除失败，key不存在
1 //删除成功
```
2，erase按照迭代器删除

```cpp
auto it=m.begin();

m.erase(it);
```

3，erase按照迭代器区间删除

```cpp
m.erase(m.begin(),m.end());
```

注意：
删除后迭代器失效！！！

---

#### 3，clear清空所有元素

```cpp
m.clear();
```
---

#### 4，查找find

1，find查找元素

```cpp
auto it=m.find(key);
```
1，找到：返回键值对的迭代器
2，未找到：返回end()

map迭代器访问：

```cpp
auto it=m.find(1);

cout<<it->first<<endl;//key
cout<<it->second<<endl;//value
```

这里注意，库里面也有一个find，但是效率太慢了（O(N)），优先使用map自己的find函数接口

#### 5，count统计元素个数

```cpp
m.count(key);
```
因为map不允许重复key：所以只能返回：
1，存在：1
2，不存在：0

主要运用：查看某个key是否存在
```cpp
int x;
cin>>x;
if(m.count(x))
{
    cout<<x<<"存在!"<<endl;
}
else
{
    cout<<x<<"不存在!"<<endl;
}
```
注意：
map也可以使用count实现快速查找是否存在，但是推荐find，因为find可以直接获得对应的value。


---

#### 6，operator[]访问和修改元素⭐️⭐️⭐️

operator[]访问和修改元素是map最常用接口之一

例如：

```cpp
map<int,string> m;

m[1]="张三";

cout<<m[1];
```
注意：
1，根据key访问value
2，不存在时会插入新的键值对
3，如果只是判断key是否存在，不推荐使用：operator[]，因为会导致插入。推荐：find

---

#### 7，范围查找——lower_bound和upper_bound

1，lower_bound

```cpp
auto it=m.lower_bound(key);
```

返回：第一个key大于等于key的键值对pair

例如：

```cpp
map<int,string> m=
{
    {10,"a"},
    {20,"b"},
    {30,"c"}
};


auto it=m.lower_bound(15);
```

结果：

```cpp
20,"b"
```

---

2，upper_bound

```cpp
auto it=m.upper_bound(key);
```

返回：

第一个key大于key的键值对

例如：

```cpp
auto it=m.upper_bound(20);
```

结果：

```cpp
30,"c"
```

---

#### 运用————找到这样一个区间：[30,60]

```cpp
map<int,string> mp;


for(int i=1;i<10;i++)
{
    mp.insert({i*10,"value"});
}


// 返回 >=30 的第一个迭代器 O(logN)
auto itlow=mp.lower_bound(30);


// 返回 >60 的第一个迭代器 O(logN)
auto itup=mp.upper_bound(60);


// 删除 [30,60] 区间
mp.erase(itlow,itup);
```

---

#### 8，交换swap

1，优先使用map自己的swap

```cpp
map<int,string> m1;
map<int,string> m2;


m1.swap(m2);
```

不要优先使用：

```cpp
swap(m1,m2);
```

原因：

容器自己的swap通常效率更高。

相似：

```cpp
set.swap();

map.swap();

vector.swap();

list.swap();
```

---

#### 总结

1，map底层也是红黑树，所以：

```cpp
map:
key自动排序
查找 O(logN)
```

2，map和set区别：

```cpp
set:
key


map:
key-value
```

3，map常用接口：

```cpp
insert     插入键值对

erase      删除元素

clear      清空

find       查找key

count      判断key是否存在

[key]      访问/修改value

lower_bound
upper_bound
```

4，和set一样：

```cpp
map.find()
>
algorithm.find()
```

因为：

```text
STL容器自己的接口
知道底层结构

algorithm算法
只通过迭代器遍历
```

所以：

```text
容器自己实现了对应功能
优先使用容器自己的接口
```



map 的增删查关注以下几个接口即可：

map 增接口插入的是 pair 键值对数据，跟 set 有所不同，但是查和删的接口只用关键字 key，跟 set 是完全类似的。不过 find 返回 iterator，不仅仅可以确认 key 在不在，还能找到 key 映射的 value，同时通过迭代器还可以修改 value。

Member types

- `key_type     -> The first template parameter (Key)`
- `mapped_type  -> The second template parameter (T)`
- `value_type   -> pair<const key_type, mapped_type>`

```cpp
// 单个数据插入，如果 key 已经存在则插入失败，key 存在相等 value 不相等也会插入失败
pair<iterator,bool> insert (const value_type& val);

// 列表插入，已经在容器中存在的值不会插入
void insert (initializer_list<value_type> il);

// 迭代器区间插入，已经在容器中存在的值不会插入
template <class InputIterator>
void insert (InputIterator first, InputIterator last);

// 查找 k，返回 k 所在的迭代器，没有找到返回 end()
iterator find (const key_type& k);

// 查找 k，返回 k 的个数
size_type count (const key_type& k) const;

// 删除一个迭代器位置的值
iterator  erase (const_iterator position);

// 删除 k，k 不存在返回 0，存在返回 1
size_type erase (const key_type& k);

// 删除一段迭代器区间的值
iterator  erase (const_iterator first, const_iterator last);

// 返回大于等于 k 位置的迭代器
iterator lower_bound (const key_type& k);

// 返回大于 k 位置的迭代器
const_iterator lower_bound (const key_type& k) const;
```

### 3.6 map的数据修改

前面我提到 map 支持修改 mapped_type 数据，不支持修改 key 数据，修改关键字数据会破坏底层搜索树的结构。

map 第一个支持修改的方式是通过迭代器，迭代器遍历时或者 find 返回 key 所在的 iterator 修改。map 还有一个非常重要的修改接口 `operator[]`，但是 `operator[]` 不仅仅支持修改，还支持插入数据和查找数据，所以它是一个多功能复合接口。

需要注意从内部实现角度，map 这里把我们传统说的 value 值给的是 T 类型，typedef 为 mapped_type。而 value_type 是红黑树结点中存储的 pair 键值对值。日常使用我们还是习惯将这里的 T 映射值叫做 value。

Member types

- `key_type     -> The first template parameter (Key)`
- `mapped_type  -> The second template parameter (T)`
- `value_type   -> pair<const key_type, mapped_type>`

```cpp
// 查找 k，返回 k 所在的迭代器，没有找到返回 end()，
// 如果找到了通过 iterator 可以修改 key 对应的 mapped_type 值
iterator find (const key_type& k);

// 文档中对 insert 返回值的说明
// The single element versions (1) return a pair, with its member pair::first
// set to an iterator pointing to either the newly inserted element or to the
// element with an equivalent key in the map. The pair::second element in the pair
// is set to true if a new element was inserted or false if an equivalent key
// already existed.

// insert 插入一个 pair<key, T> 对象
// 1、如果 key 已经在 map 中，插入失败，则返回一个 pair<iterator, bool> 对象，
//    返回 pair 对象 first 是 key 所在结点的迭代器，second 是 false。
// 2、如果 key 不在 map 中，插入成功，则返回一个 pair<iterator, bool> 对象，
//    返回 pair 对象 first 是新插入 key 所在结点的迭代器，second 是 true。
// 也就是说无论插入成功还是失败，返回 pair<iterator, bool> 对象的 first 都会指向 key 所在的迭代器。
// 那么也就意味着 insert 插入失败时充当了查找的功能，正是因为这一点，insert 可以用来实现 operator[]。
// 需要注意的是这里有两个 pair，不要混淆了：
// 一个是 map 底层红黑树节点中存的 pair<key, T>，
// 另一个是 insert 返回值 pair<iterator, bool>。

pair<iterator,bool> insert (const value_type& val);

mapped_type& operator[] (const key_type& k);

// operator[] 的内部实现
mapped_type& operator[] (const key_type& k)
{
    // 1、如果 k 不在 map 中，insert 会插入 k 和 mapped_type 默认值，
    //    同时 [] 返回结点中存储 mapped_type 值的引用，
    //    那么我们可以通过引用修改映射值。所以 [] 具备了插入+修改功能。
    // 2、如果 k 在 map 中，insert 会插入失败，但是 insert 返回 pair 对象的 first
    //    是指向 key 结点的迭代器，[] 同时返回结点中存储 mapped_type 值的引用，
    //    所以 [] 具备了查找+修改的功能。
    pair<iterator, bool> ret = insert({ k, mapped_type() });
    iterator it = ret.first;
    return it->second;
}
```

### 3.7 构造遍历及增删查使用样例

```cpp
#include<iostream>
#include<map>
using namespace std;

int main()
{
    // initializer_list 构造及迭代遍历
    map<string, string> dict = {
        {"left", "左边"},
        {"right", "右边"},
        {"insert", "插入"},
        {"string", "字符串"}
    };

    //map<string, string>::iterator it = dict.begin();
    auto it = dict.begin();
    while (it != dict.end())
    {
        //cout << (*it).first << ":" << (*it).second << endl;

        // map 的迭代基本都使用 operator->，这里省略了一个 ->
        // 第一个 -> 是迭代器运算符重载，返回 pair*；
        // 第二个箭头是结构指针解引用取 pair 数据。
        //cout << it.operator->()->first << ":" << it.operator->()->second << endl;

        cout << it->first << ":" << it->second << endl;
        ++it;
    }
    cout << endl;

    // insert 插入 pair 对象的 4 种方式，对比之下，最后一种最方便
    pair<string, string> kv1("first", "第一个");
    dict.insert(kv1);
    dict.insert(pair<string, string>("second", "第二个"));
    dict.insert(make_pair("sort", "排序"));
    dict.insert({ "auto", "自动的" });

    // "left" 已经存在，插入失败
    dict.insert({ "left", "左边，剩余" });

    // 范围 for 遍历
    for (const auto& e : dict)
    {
        cout << e.first << ":" << e.second << endl;
    }
    cout << endl;

    string str;
    while (cin >> str)
    {
        auto ret = dict.find(str);
        if (ret != dict.end())
        {
            cout << "->" << ret->second << endl;
        }
        else
        {
            cout << "无此单词，请重新输入" << endl;
        }
    }

    // erase 等接口跟 set 完全类似，这里就不演示讲解了

    return 0;
}
```

### 3.8 map的迭代器和[]功能样例

```cpp
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    // 利用 find 和 iterator 修改功能，统计水果出现的次数
    string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
                     "苹果", "香蕉", "苹果", "香蕉" };
    map<string, int> countMap;

    for (const auto& str : arr)
    {
        // 先查找水果在不在 map 中
        // 1、不在，说明水果第一次出现，则插入 {水果, 1}
        // 2、在，则查找到的节点中水果对应的次数 ++
        auto ret = countMap.find(str);
        if (ret == countMap.end())
        {
            countMap.insert({ str, 1 });
        }
        else
        {
            ret->second++;
        }
    }

    for (const auto& e : countMap)
    {
        cout << e.first << ":" << e.second << endl;
    }
    cout << endl;

    return 0;
}
```

```cpp
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    // 利用 [] 插入+修改功能，巧妙实现统计水果出现的次数
    string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
                     "苹果", "香蕉", "苹果", "香蕉" };
    map<string, int> countMap;

    for (const auto& str : arr)
    {
        // [] 先查找水果在不在 map 中
        // 1、不在，说明水果第一次出现，则插入 {水果, 0}，
        //    同时返回次数的引用，++ 一下就变成 1 次了
        // 2、在，则返回水果对应的次数 ++
        countMap[str]++;
    }

    for (const auto& e : countMap)
    {
        cout << e.first << ":" << e.second << endl;
    }
    cout << endl;

    return 0;
}
```

```cpp
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string, string> dict;
    dict.insert(make_pair("sort", "排序"));

    // key 不存在 -> 插入 {"insert", string()}
    dict["insert"];

    // 插入+修改
    dict["left"] = "左边";

    // 修改
    dict["left"] = "左边、剩余";

    // key 存在 -> 查找
    cout << dict["left"] << endl;

    return 0;
}
```

### 3.9 multimap和map的差异

multimap 和 map 的使用基本完全类似，主要区别点在于 multimap 支持关键值 key 冗余，那么 ins ert/find/count/erase 都围绕着支持关键值 key 冗余有所差异，这里跟 set 和 multiset 完全一样。比如 find 时，有多个 key，返回中序第一个。其次就是 multimap 不支持 `[]`，因为支持 key 冗余，`[]` 就只能支持插入了，不能支持修改。
## map相关算法题
### 复制带随机指针的链表⭐⭐⭐⭐

#### 题目链接

[复制带随机指针的链表](https://leetcode.cn/problems/copy-list-with-random-pointer/)

---

#### 题目描述

给你一个长度为 `n` 的链表，每个节点包含：

- `val`：节点值
- `next`：指向下一个节点
- `random`：可以指向链表中的任意节点或者 `null`

要求返回链表的深拷贝。

---

#### 解题思路

使用 `map` 建立 **原链表节点 -> 新链表节点** 的映射。

分两步：

1. 第一次遍历链表，复制所有节点，并建立原节点和新节点的对应关系。
2. 第二次遍历链表，根据 `map` 找到 `random` 指向的新节点，完成随机指针连接。

---

#### 我的解题代码

```cpp
/*
 // Definition for a Node.
 class Node {
 public:
     int val;
     Node* next;
     Node* random;

     Node(int _val) {
         val = _val;
         next = NULL;
         random = NULL;
     }
 };
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        // 保存 原节点 -> 新节点 的映射
        map<Node*, Node*> m;

        Node* rhead = head;

        // 创建虚拟头节点，方便连接新链表
        Node* rethead = new Node(-1);
        Node* ret = rethead;

        // 第一次遍历：复制所有节点
        while (head)
        {
            Node* tmp = new Node(head->val);

            rethead->next = tmp;
            rethead = tmp;

            // 建立映射关系
            m[head] = rethead;

            head = head->next;
        }

        // 删除虚拟头节点，返回真正的头节点
        Node* tmp = ret;
        ret = ret->next;
        delete tmp;

        // 保存原链表头，用于第二次遍历
        while (rhead)
        {
            // 根据映射关系设置 random 指针
            m[rhead]->random = m[rhead->random];

            rhead = rhead->next;
        }

        return ret;
    }
};
```
#### 优化版，思路一样
```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> nodeMap;
        Node* copyhead = nullptr, *copytail = nullptr;
        Node* cur = head;

        while (cur)
        {
            if (copytail == nullptr)
            {
                copyhead = copytail = new Node(cur->val);
            }
            else
            {
                copytail->next = new Node(cur->val);
                copytail = copytail->next;
            }

            // 原节点和拷贝节点 map kv 存储
            nodeMap[cur] = copytail;
            cur = cur->next;
        }

        // 处理 random
        cur = head;
        Node* copy = copyhead;
        while (cur)
        {
            if (cur->random == nullptr)
            {
                copy->random = nullptr;
            }
            else
            {
                copy->random = nodeMap[cur->random];
            }

            cur = cur->next;
            copy = copy->next;
        }

        return copyhead;
    }
};
```

---

没懂？看看大神的解题代码！！

#### 大神解题代码（深拷贝，直接原地复制数组）

```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr)
            return nullptr;

        // 第一步：复制节点，并插入到原节点后面
        Node* cur = head;

        while (cur)
        {
            Node* copy = new Node(cur->val);

            copy->next = cur->next;
            cur->next = copy;

            cur = copy->next;
        }

        // 第二步：处理 random 指针
        cur = head;

        while (cur)
        {
            if (cur->random)
                cur->next->random = cur->random->next;

            cur = cur->next->next;
        }

        // 第三步：拆分链表
        Node* ret = head->next;
        cur = head;

        while (cur)
        {
            Node* copy = cur->next;

            cur->next = copy->next;

            if (copy->next)
                copy->next = copy->next->next;

            cur = cur->next;
        }

        return ret;
    }
};
```


### 3.11 692. 前K个高频单词 — 力扣（LeetCode）

本题目我们利用 map 统计出次数以后，返回的答案应该按单词出现频率由高到低排序，有一个特殊要求：如果不同的单词有相同出现频率，按字典顺序排序。

#### 解决思路1

用排序找前 k 个单词，因为 map 中已经对 key 单词排序过，也就意味着遍历 map 时，次数相同的单词，字典序小的在前面，字典序大的在后面。那么我们将数据放到 vector 中用一个稳定的排序就可以实现上面特殊要求，但是 sort 底层是快排，是不稳定的，所以我们要用 stable_sort，它是稳定的。

```cpp
class Solution {
public:
    struct Compare
    {
        bool operator()(const pair<string, int>& x, const pair<string, int>& y) const
        {
            return x.second > y.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> countMap;
        for (auto& e : words)
        {
            countMap[e]++;
        }

        vector<pair<string, int>> v(countMap.begin(), countMap.end());
        // 仿函数控制降序
        stable_sort(v.begin(), v.end(), Compare());
        //sort(v.begin(), v.end(), Compare());

        // 取前 k 个
        vector<string> strV;
        for (int i = 0; i < k; ++i)
        {
            strV.push_back(v[i].first);
        }

        return strV;
    }
};
```

#### 解决思路2

将 map 统计出的次数的数据放到 vector 中排序，或者放到 priority_queue 中来选出前 k 个。利用仿函数强行控制次数相等的，字典序小的在前面。

```cpp
class Solution {
public:
    struct Compare
    {
        bool operator()(const pair<string, int>& x, const pair<string, int>& y) const
        {
            return x.second > y.second || (x.second == y.second && x.first < y.first);
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> countMap;
        for (auto& e : words)
        {
            countMap[e]++;
        }

        vector<pair<string, int>> v(countMap.begin(), countMap.end());
        // 仿函数控制降序，仿函数控制次数相等，字典序小的在前面
        sort(v.begin(), v.end(), Compare());

        // 取前 k 个
        vector<string> strV;
        for (int i = 0; i < k; ++i)
        {
            strV.push_back(v[i].first);
        }

        return strV;
    }
};
```

```cpp
class Solution {
public:
    struct Compare
    {
        bool operator()(const pair<string, int>& x, const pair<string, int>& y) const
        {
            // 要注意优先级队列底层是反的，大堆要实现小于比较，
            // 所以这里次数相等，想要字典序小的在前面要比较字典序大的为真
            return x.second < y.second || (x.second == y.second && x.first > y.first);
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> countMap;
        for (auto& e : words)
        {
            countMap[e]++;
        }

        // 将 map 中的 <单词，次数> 放到 priority_queue 中，
        // 仿函数控制大堆，次数相同按照字典序规则排序
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare>
            p(countMap.begin(), countMap.end());

        vector<string> strV;
        for (int i = 0; i < k; ++i)
        {
            strV.push_back(p.top().first);
            p.pop();
        }

        return strV;
    }
};
```
