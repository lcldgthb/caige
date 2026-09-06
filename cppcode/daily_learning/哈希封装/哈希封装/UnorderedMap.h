#pragma once

#include "HashTable.h"

namespace caige
{
	template<class K, class V, class Hash = HashFunc<K>>
	class unordered_map
	{
		struct MapKeyOfT//从T里面得到key
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::Iterator iterator;
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::ConstIterator const_iterator;
			iterator begin()
			{
				_ht.Begin();
	         }

			iterator end()
			{
				_ht.End();
			}

	const_iterator begin() const 
	{
		_ht.Begin();
	}

	const_iterator end() const 
	{
		_ht.End();
	}

	V& operator[](const K& key)
	{
		/*pair<iterator,bool> tmp= _ht.Insert(key);
		return tmp.first->_data.second;*/
		pair<iterator, bool> ret = insert({ key, V() });
		return ret.first->second;
	}

	pair<iterator, bool> insert(const pair<K, V>& kv)
	{
		_ht.Insert(kv);
	}

	iterator find(const K& key)
	{
		_ht.Find(key);
	}

	bool erase(const K& key)
	{
		_ht.Erase(key);
	}
	
	private:
		hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash> _ht;
		//这里的设计我们要参考后面哈希节点的设计，节点里面存的是T，T是哈希通的第二个参数
	// template<class T>在这里T就是pair<const K, V>
	//struct HashNode
	//{
	//	T _data;...
	//// 哈希桶的前置声明
	//template<class K, class T, class KeyOfT, class Hash>
	//class HashTable;
	};
}
//public:
//	iterator begin();
//
//	iterator end();
//
//	const_iterator begin() const;
//
//	const_iterator end() const;
//
//	V& operator[](const K& key);
//
//	pair<iterator, bool> insert(const pair<K, V>& kv);
//
//	iterator Find(const K& key);
//
//	bool Erase(const K& key);