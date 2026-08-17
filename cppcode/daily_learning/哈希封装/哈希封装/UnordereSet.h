#pragma once

#include "HashTable.h"
namespace caige
{
template<class K, class Hash = HashFunc<K>>
class unordered_set
{
	struct SetKeyOfT
	{
		const K& operator()(const K& key);
	};

private:
	hash_bucket::HashTable<K, const K, SetKeyOfT, Hash> _ht;
	//这里的设计我们要参考后面哈希节点的设计，节点里面存的是T，T是哈希通的第二个参数
	// template<class T>
	//struct HashNode
	//{
	//	T _data;...
	//// 哈希桶的前置声明
	//template<class K, class T, class KeyOfT, class Hash>
	//class HashTable;
};
}
//
//public:
//	typedef typename hash_bucket::HashTable<K, const K, SetKeyOfT, Hash>::Iterator iterator;
//	typedef typename hash_bucket::HashTable<K, const K, SetKeyOfT, Hash>::ConstIterator const_iterator;
//
//public:
//	iterator begin();
//
//	iterator end();
//
//	const_iterator begin() const;
//
//	const_iterator end() const;
//
//	pair<iterator, bool> insert(const K& key);
//
//	iterator Find(const K& key);
//
//	bool Erase(const K& key);
