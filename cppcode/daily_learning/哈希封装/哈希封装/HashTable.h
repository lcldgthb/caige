//#pragma once
//#pragma once
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <utility>
//
//using namespace std;
//
//enum State
//{
//	EXIST,
//	EMPTY,
//	DELETE
//};
//
//template<class K, class V>
//struct HashData
//{
//	pair<K, V> _kv;
//	State _state = EMPTY;
//};
//
//template<class K>
//struct HashFunc
//{
//	size_t operator()(const K& key)
//	{
//		return (size_t)key;
//	}
//};
//
//template<>
//struct HashFunc<string>
//{
//	size_t operator()(const string& s);
//};
//
//inline unsigned long __stl_next_prime(unsigned long n)
//{
//	static const int __stl_num_primes = 28;
//
//	static const unsigned long __stl_prime_list[__stl_num_primes] = {
//		53, 97, 193, 389, 769,
//		1543, 3079, 6151, 12289, 24593,
//		49157, 98317, 196613, 393241, 786433,
//		1572869, 3145739, 6291469, 12582917,
//		25165843, 50331653, 100663319, 201326611,
//		402653189, 805306457, 1610612741,
//		3221225473, 4294967291
//	};
//
//	const unsigned long* first = __stl_prime_list;
//	const unsigned long* last = __stl_prime_list + __stl_num_primes;
//	const unsigned long* pos = lower_bound(first, last, n);
//
//	return pos == last ? *(last - 1) : *pos;
//}
//
//
//namespace open_address
//{
//	template<class K, class V, class Hash = HashFunc<K>>
//	class HashTable
//	{
//	public:
//		HashTable();
//
//		bool Insert(const pair<K, V>& kv)
//		{
//
//		}
//
//		HashData<K, V>* Find(const K& key);
//
//		bool Erase(const K& key);
//
//	private:
//		vector<HashData<K, V>> _tables;
//		size_t _n;
//	};
//}
//
//
//namespace hash_bucket
//{
//	template<class T>
//	struct HashNode
//	{
//		T _data;
//		HashNode<T>* _next;
//
//		HashNode(const T& data)
//			:_data(data)
//			,_next(nullptr)
//		{ }
//	};
//
//
//	// 前置声明
//	template<class K, class T, class KeyOfT, class Hash>
//	class HashTable;
//
//
//	template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
//	struct HTIterator
//	{
//		typedef HashNode<T> Node;
//		typedef HashTable<K, T, KeyOfT, Hash> HT;
//		typedef HTIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self;
//
//		Node* _node;
//		const HT* _ht;
//
//		HTIterator(Node* node, const HT* ht);
//
//		Ref operator*();
//
//		Ptr operator->();
//
//		bool operator!=(const Self& s);
//
//		Self& operator++();
//	};
//
//
//	template<class K, class T, class KeyOfT, class Hash>
//	class HashTable
//	{
//		template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
//		friend struct HTIterator;
//
//		typedef HashNode<T> Node;
//
//	public:
//		typedef HTIterator<K, T, T&, T*, KeyOfT, Hash> Iterator;
//		typedef HTIterator<K, T, const T&, const T*, KeyOfT, Hash> ConstIterator;
//
//	public:
//		HashTable()
//			:_tables(nullptr)
//			,n(0)
//		{ }
//
//		~HashTable();
//
//		Iterator Begin();
//
//		Iterator End();
//
//		ConstIterator Begin() const;
//
//		ConstIterator End() const;
//
//		pair<Iterator, bool> Insert(const T& data)
//		{
//			Hash gethash;
//			size_t hashi = gethash(KeyOfT(data));
//			Node* pre = nullptr;
//			Node* cur = _table[hashi];
//			Node* newnode = new Node(data);
//			if (cur)
//			{
//				newnode->_next = cur->_next;
//				cur->_next = newnode;
//				return { Iterator(newnode),true };
//			}
//			else
//			{
//				_table[hashi] = newnode;
//				return { Iterator(newnode),true };
//			}
//		}
//
//		Iterator Find(const K& key);
//
//		bool Erase(const K& key);
//
//	private:
//		vector<Node*> _tables;
//		size_t _n = 0;
//	};
//}




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
//开放定址法为什么要有三个状态？
//
template<class K, class V>
struct HashData
{
	pair<K, V> _kv;
	State _state = EMPTY;
};

template<class K>
struct HashFunc
{
	size_t operator()(const K& key);
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
		HashTable()
			:_n(0)
			,_tables(__stl_next_prime(1))
		{};

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))//避免重复key的插入
				return false;
			if (_n * 10 / _tables.size() >= 7)
			{
				HashTable<K,V, Hash> tmp;
				tmp._tables.resize(__stl_next_prime(_tables.size() + 1));
				for (auto& data : _tables)
				{
					if (data._state == EXIST)
					{
						tmp.Insert(data._kv);
					}
				}
				swap(tmp._tables, _tables);
			}
			//除法散列法
			HashFunc hashfunc;
			size_t hash0 = hashfunc(kv.first) % _tables.size();
			size_t hashi = hash0;
			while (_tables[hashi]._state ==EXIST)
			{
				hashi = (hashi + _tables.size() + 1) % _tables.size();
			}
			/*线性探测的另一种写法
			size_t i = 1;
			while (_tables[hashi]._state == EXIST)
			{
				hashi = (hash0 + i) % _tables.size();
				i++;
			}*/

			/*二次探测，i变成i*i，本质还是想要避免哈希冲突，让数据更分散
			size_t i = 1;
			while (_tables[hashi]._state == EXIST)
			{
				hashi = (hash0 + i*i) % _tables.size();
				i++;
			}*/
			/*多重探测 / 双重散列
			起点一个哈希，步长再一个哈希。(代码略）*/
			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			_n++;
			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			HashFunc hashf;
			size_t hash0 = hashf(key) % _tables.size();
			while (_tables[hash0]._state != EXIST && _tables[hash0]._kv.first != key)
			{
				hash0++;
				hash0 %= _tables.size();
			}
			if (_tables[hash0]._kv.first == key)
				return &_tables[hash0];
			else return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ptarget = Find(key);
			if (ptarget == nullptr)return false;
			/*HashData<K, V> target = *ptarget;
			target._state = DELETE;*/
			
			ptarget->_state = DELETE;
			_n--;
			return true;
		}

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
			, _next(nullptr)
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

		HTIterator(Node* node, const HT* ht)
			:_node(node)
			,_ht(ht)
		{ }

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}
		/* 
		*it 调用it.operator*()
		而：it->name调用：it.operator->()->name，有两次->
		因为C++ 会自动帮你调用迭代器的：operator->()
		所以：it->name本质上可以理解为：
		it.operator->()->name
		又因为->的调用对象必须是指针，所以要&取地址
			*/
		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}

		Self& operator++()
		{
			Hash hashf;
			KeyOfT kot;
			if (_node->_next)
			{
				_node= _node->_next;
				return *this;
			}
			else
			{
				size_t hash0 = hashf(kot(_node->_data)) % _ht->_tables.size();
				size_t i = hash0+1;
				while (i <= _ht->_tables.size())
				{
					if (i == _ht->_tables.size())
					{
						_node = nullptr;
						return *this;
					}
					if ((_ht->_tables[i]))
					{
						break;
					}
					i++;
				}
				_node = _ht->_tables[i];
				return *this;
			}
		}
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
			:_tables(__stl_next_prime(1))
		{ }

		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;

					cur = next;
				}

				_tables[i] = nullptr;
			}
		}

		Iterator Begin()
		{
			for (auto& it : _tables)
				if (it)
					return Iterator(it,this);
			return End();
		}

		Iterator End()
		{
			return Iterator(nullptr, this);
		}

		ConstIterator Begin() const
		{
			for (auto& it : _tables)
				if (it)
					return ConstIterator(it, this);
			return End();
		}

		ConstIterator End() const
		{
			return ConstIterator(nullptr, this);
		}

		pair<Iterator, bool> Insert(const T& data)
		{
			KeyOfT kot;
			Hash hashf;
			if (Find(kot(data)) != End())
				return { Find(kot(data) ),false };
			if (_n ==_tables.size())//理论上超过1任然可以存储
			{
				/*HashTable<K, T, KeyOfT, Hash> nhash;
				nhash._tables.resize(__stl_next_prime(_tables.size() + 1));
				for (auto& it : _tables)
				{
					if (it)
					{
						Node* cur = it;
						while (cur)
						{
							nhash.Insert(it->_data);
							cur = cur->_next;
						}
					}
				}
				swap(nhash._tables, _tables);*/
				//不新创建Node的方法
				vector<Node*> nhashtable(__stl_next_prime(_tables.size() + 1));
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t nhash0 = hashf(kot(cur->_data)) % nhashtable.size();
						//头插
						cur->_next = nhashtable[nhash0];
						nhashtable[nhash0] = cur;
						cur = next;
					}
				}
				_tables.swap(nhashtable);
			}
			//.用作不是指针类型的时候，->用作是类型的时候，访问的是该指针指向的对象里面的元素
	
			size_t hash0 = hashf(kot(data)) % _tables.size();
		/*	Node newnode(data);*/
			Node* newnode = new Node(data);
			
			////要保存前置地址，因为这里用的是单链表来实现
			//Node* pre = nullptr;
			//Node* cur = _tables[hash0];
			//while (cur)
			//{
			//	pre = cur;
			//	cur = cur->_next;
			//}
			//pre->_next = newnode;
			// 上面错误示例
			//直接头插即可
			if (_tables[hash0] == nullptr)
				_tables[hash0] = newnode;
			else
			{
				Node* tmp = _tables[hash0]->_next;
				_tables[hash0]->_next = newnode;
				newnode->_next = tmp;
			}
			_n++;
			
			return { Iterator(newnode,this),true };
		}

		Iterator Find(const K& key)
		{
			KeyOfT kot;
			Hash hashf;
			size_t hash0 = hashf(key) % _tables.size();
			
			Node* cur = _tables[hash0];
			while (cur&&kot(cur->_data) != key)
			{
				cur = cur->_next;
			}
			return Iterator(cur, this);
		}

		bool Erase(const K& key)
		{
			Hash hashf;
			KeyOfT kot;
			/*if (Find(key) != End())
				return false;*/
			size_t hash0 = hashf(key) % _tables.size();
			if (_tables[hash0] == nullptr)
				return false;//可能为空桶，要特判
			if (kot(_tables[hash0]->_data) == key)
			{
				Node* tmp = _tables[hash0];
				_tables[hash0] = tmp->_next;
				delete tmp;
				_n--;
				return true;
			}
			Node* pre = _tables[hash0];
			Node* cur = _tables[hash0]->_next;
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					pre->_next = cur->_next;
					delete cur;
					_n--;
					return true;
				}
				pre = cur;
				cur = cur->_next;
			}
			return false;
		}

	private:
		vector<Node*> _tables;
		size_t _n = 0;
	};
}