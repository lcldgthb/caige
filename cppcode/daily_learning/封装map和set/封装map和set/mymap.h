#pragma once
#include"RBTree.h"

namespace caige
{
	template <class K ,class V>
	class map
	{
	public:
		class keyofmap//仿函数
		{
		public:
			const K& operator()(const pair<K,V>& kv)
			{
				return kv.first;
			}
		};
		typedef typename RBTree<K, pair<const K,V>, keyofmap>::Iterator iterator;
		typedef typename RBTree<K,  pair<const K, V>, keyofmap>::Const_Iterator const_iterator;
		iterator begin()
		{
			return _map.begin();
		}

		iterator end()
		{
			return _map.end();
		}

		const_iterator begin() const
		{
			return _map.begin();
		}

		const_iterator end()  const
		{
			return _map.end();
		}

		pair<iterator, bool> insert(const pair< K, V>& kv)
		{
			return _map.Insert(kv);
		}
		/*iterator& operator[](const V& v,const K& k)
		{
			return Insert({ v,k }).first;
		}*/
		//复习一下运算符重载，错误理解
		//单参数；返回值就是该参数
		//双参数：第二个参数做返回值，第一个参数做参数
		//正确理解
		//一元运算符：成员函数 0 个显式参数（this 就是那唯一的操作数）
		//二元运算符：成员函数 1 个显式参数（this 是左操作数，显式参数是右操作数）
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}

		
	private:
		RBTree<K, pair<const K, V>, keyofmap > _map;
	};
}