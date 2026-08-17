#include <iostream>
#include "HashTable.h"
using namespace std;

// 测试 int 做 key（覆盖：重复插入 + 触发扩容）
void TestInt()
{
    hash_bucket::HashTable<int, int> ht;

    // 这组数据：有重复（3、15 各出现多次），且数量超过初始 11 个桶，会触发扩容
    int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 3, 3, 15 };
    for (auto e : a)
    {
        if (ht.Insert(make_pair(e, e)))
            cout << "插入成功: " << e << endl;
        else
            cout << "插入失败(重复): " << e << endl;
    }

    cout << "=== 查找测试（扩容后所有数据必须都能找到） ===" << endl;
    int keys[] = { 1, 4, 15, 16, 7 };
    for (auto k : keys)
    {
        auto ret = ht.Find(k);
        if (ret != nullptr)
            cout << "找到 " << k << " -> " << ret->_kv.second << endl;
        else
            cout << "!! 未找到 " << k << " （有 bug）" << endl;
    }

    cout << "=== 删除测试 ===" << endl;
    ht.Erase(4);
    ht.Erase(15);
    int erased[] = { 4, 15 };
    for (auto k : erased)
    {
        if (ht.Find(k) != nullptr)
            cout << "!! " << k << " 仍存在（删除有 bug）" << endl;
        else
            cout << k << " 已删除（正确）" << endl;
    }

    // 验证没被删除的 16 仍然能找到（防止 Erase 误删别的节点）
    if (ht.Find(16) != nullptr)
        cout << "16 仍存在（正确）" << endl;
    else
        cout << "!! 16 丢失了（删除逻辑有 bug）" << endl;
}

// 测试 string 做 key（验证 HashFunc<string> 特化是否生效）
void TestString()
{
    hash_bucket::HashTable<string, string> dict;
    dict.Insert(make_pair("sort", "排序"));
    dict.Insert(make_pair("left", "左边"));
    dict.Insert(make_pair("right", "右边"));
    dict.Insert(make_pair("string", "字符串"));

    auto ret = dict.Find("left");
    if (ret != nullptr)
        cout << "left -> " << ret->_kv.second << endl;

    dict.Erase("right");
    if (dict.Find("right") == nullptr)
        cout << "right 已删除" << endl;
}

int main()
{
    TestInt();
    cout << endl;
    TestString();
    return 0;
}
