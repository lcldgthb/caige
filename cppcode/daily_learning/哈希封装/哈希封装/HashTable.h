#pragma once
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

enum State
{
	EXIST,
	EMPTY,
	DELETE
};

template<class K, class V>
struct HashData
{
	pair<K, V> _kv;
	State _state = EMPTY;
};

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct HashFunc<string>
{
	size_t operator()(const string& s);
};

inline unsigned long __stl_next_prime(unsigned long n)
{
	static const int __stl_num_primes = 28;

	static const unsigned long __stl_prime_list[__stl_num_primes] = {
		53, 97, 193, 389, 769,
		1543, 3079, 6151, 12289, 24593,
		49157, 98317, 196613, 393241, 786433,
		1572869, 3145739, 6291469, 12582917,
		25165843, 50331653, 100663319, 201326611,
		402653189, 805306457, 1610612741,
		3221225473, 4294967291
	};

	const unsigned long* first = __stl_prime_list;
	const unsigned long* last = __stl_prime_list + __stl_num_primes;
	const unsigned long* pos = lower_bound(first, last, n);

	return pos == last ? *(last - 1) : *pos;
}


namespace open_address
{
	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable();

		bool Insert(const pair<K, V>& kv);

		HashData<K, V>* Find(const K& key);

		bool Erase(const K& key);

	private:
		vector<HashData<K, V>> _tables;
		size_t _n;
	};
}


namespace hash_bucket
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			,_next(nullptr)
		{ }
	};


	// 前置声明
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;


	template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
	struct HTIterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef HTIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self;

		Node* _node;
		const HT* _ht;

		HTIterator(Node* node, const HT* ht);

		Ref operator*();

		Ptr operator->();

		bool operator!=(const Self& s);

		Self& operator++();
	};


	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
		template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
		friend struct HTIterator;

		typedef HashNode<T> Node;

	public:
		typedef HTIterator<K, T, T&, T*, KeyOfT, Hash> Iterator;
		typedef HTIterator<K, T, const T&, const T*, KeyOfT, Hash> ConstIterator;

	public:
		HashTable()
			:_tables(nullptr)
			,n(0)
		{ }

		~HashTable();

		Iterator Begin();

		Iterator End();

		ConstIterator Begin() const;

		ConstIterator End() const;

		pair<Iterator, bool> Insert(const T& data)
		{
			Hash gethash;
			size_t hashi = gethash(KeyOfT(data));
			Node* pre = nullptr;
			Node* cur = _table[hashi];
			Node* newnode = new Node(data);
			if (cur)
			{
				newnode->_next = cur->_next;
				cur->_next = newnode;
				return { Iterator(newnode),true };
			}
			else
			{
				_table[hashi] = newnode;
				return { Iterator(newnode),true };
			}
		}

		Iterator Find(const K& key);

		bool Erase(const K& key);

	private:
		vector<Node*> _tables;
		size_t _n = 0;
	};
}