#define _CRT_SECURE_NO_WARNINGS
#include"vector.h"
using namespace std;
int main()
{
	caige::vector<int> v1(10, 1);
	caige::vector<caige::vector<int>> v2(5, v1);
	v2[0][0] = 2;
	for (int i = 0; i < v2[0].size(); i++)
		for (int j = 0; j < v2.size(); j++)
			v2[i][j] = 10086;
	return 0;
}