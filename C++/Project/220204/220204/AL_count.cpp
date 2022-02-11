#include <iostream>
#include <vector>
#include <algorithm>
#include "PrintFunctor.h"
using namespace std;

bool Pred(int a, int b)
{
	return b % a == 0;
}

int main()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;

	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(40);


	// v1에서 비교하고자 하는 부분의 size가 v2의 size를 넘으면 에러
	bool isEqual = equal(v1.begin(), v1.begin() + 4, v2.begin(), [](int v1Int, int v2Int) { return v1Int == v2Int; });
	cout << isEqual << endl;

	for_each(v1.begin(), v1.end(), PrintFunctor(", "));
	cout << endl;

}