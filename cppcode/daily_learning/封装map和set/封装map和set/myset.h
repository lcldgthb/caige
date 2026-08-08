#pragma once
#include"RBTree.h"
namespace caige
{
	template <class K>
	class set
	{
	public:
		struct keyofset//因为要和map保持一致，所以，也要写一个仿函数
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
		typedef typename RBTree<K, const K, keyofset>::Iterator iterator;
		typedef typename RBTree<K, const K, keyofset>::Const_Iterator const_iterator;
		iterator begin()
		{
			return _set.begin();
		}

		iterator end()
		{
			return _set.end();
		}

		const_iterator begin() const
		{
			return _set.begin();
		}

		const_iterator end()  const
		{
			return _set.end();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _set.Insert(key);
		}
	private:
		RBTree< K, const K, keyofset> _set;
	};
}