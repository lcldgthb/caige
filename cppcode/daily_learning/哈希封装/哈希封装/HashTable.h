#pragma once
#include <vector>
#include <string>
using namespace std;

// ==================== 哈希函数仿函数（已提供，无需补全） ====================
// 作用：把 key 转成可以取模的 size_t 整数
template<class K>
struct HashFunc
{
    size_t operator()(const K& key)
    {
        return (size_t)key;
    }
};

// string 特化：BKDR 哈希
// 思考：为什么不能把每个字符直接相加？
// 因为 "abcd" 和 "bcad" 相加结果相同，会冲突。
// 每次乘以质数 131，让不同排列的字符产生不同哈希值。
template<>
struct HashFunc<string>
{
    size_t operator()(const string& key)
    {
        size_t hash = 0;
        for (auto ch : key)
        {
            hash = hash * 131 + ch;
        }
        return hash;
    }
};

// ==================== 哈希桶（链地址法） ====================
namespace hash_bucket
{
    // 桶节点（已提供，无需补全）
    template<class K, class V>
    struct HashNode
    {
        pair<K, V> _kv;
        HashNode<K, V>* _next;

        HashNode(const pair<K, V>& kv)
            : _kv(kv)
            , _next(nullptr)
        {}
    };

    template<class K, class V, class Hash = HashFunc<K>>
    class HashTable
    {
        typedef HashNode<K, V> Node;
    public:
        HashTable()
        {
            // TODO: 给 _tables 开好初始桶（建议 11 个），每个桶初始化为 nullptr
        }

        ~HashTable()
        {
            // TODO: 遍历每个桶，逐个 delete 释放节点
            // 注意：先保存 cur->_next，再 delete cur，否则删完找不到下一个
        }

        bool Insert(const pair<K, V>& kv)
        {
            // 1. 判重：key 已存在则 return false（可复用 Find）

            // 2. 扩容：当 _n == _tables.size()（负载因子 == 1）时
            //    - 开一个新表，桶数 = 旧桶数 * 2，全部初始化为 nullptr
            //    - 遍历旧表每个桶的每个节点，重新计算下标，头插到新表
            //    ⚠️ 迁移前必须先保存 cur->_next，否则头插会弄断链表
            //    - 最后 swap 新旧表

            // 3. 头插新节点：算 hashi → new 节点 → 头插 → ++_n → return true
        }

        Node* Find(const K& key)
        {
            // 1. 算 hashi = hs(key) % _tables.size()
            // 2. 从 _tables[hashi] 开始遍历链表
            // 3. cur->_kv.first == key 则返回 cur；遍历完返回 nullptr
        }

        bool Erase(const K& key)
        {
            // 1. 算 hashi
            // 2. 用 prev、cur 双指针遍历桶链表
            // 3. 找到后分两种情况删除：
            //    - 删除的是头节点：_tables[hashi] = cur->_next
            //    - 删除的是中间/尾节点：prev->_next = cur->_next
            // 4. delete cur，--_n，return true；没找到 return false
        }

    private:
        vector<Node*> _tables; // 指针数组：每个桶是一个链表的头指针
        size_t _n = 0;         // 存储的有效数据个数
    };
}
