#pragma once
#include"RBTree.h"

namespace caige
{
	template <class K ,class V>
	class map
	{
	public:
		class keyofmap//·Âº¯Êý
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
		
	private:
		RBTree<K, pair<const K, V>, keyofmap > _map;
	};
}