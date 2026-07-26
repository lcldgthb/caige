#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"Stack.h"
#include"Queue.h"
#include"priority_queue.h"

namespace caige
{
	template<class T>
	class Lesser
	{
	public :
		bool operator()(int x, int y)
		{
			return x < y;
		}
	};
	template<class T>
	class Greater
	{
	public:
		bool operator()(int x, int y)
		{
			return x >y;
		}
	};
}
int main()
{

	return 0;
}