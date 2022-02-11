# SortingAlgorithm

## heap 알고리즘
- 완전 트리로 표현 

### make_heap(b, e, (f))
구간의 순차열을 힙구조로 만든다.

### push_heap(v.begin(), v.end(), (f))
구간의 힙 추가 연산 수행

### pop_heap(b, e, (f))
힙에서 루트노드  제거

### sort_heap(b, e, (f))
오름차순으로 정리


## nth_element(b, m, e)
순차열의 원소 중 n개의 원소 선별
구간의 원소 중 m-b개 만큼 원소를 선별하여 [b, m)의 순차열에 놓는다.


## sort(b, e)
- 퀵소트 
- 평균 O(NlogM)

```cpp 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;

	for (int i = 0; i < 100; ++i)
		v.push_back(rand() % 1000);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	sort(v.begin(), v.end());

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}
```

## stable_sort(b, e)
순차열 정렬시 같은 원소의 상대적인위치 유지

## partial_sort(b, m, e)
- b, e 구간의 원소를 b, m 의 순차열에 원소 정렬
- 특정 범위까지만 sort하고 싶을 때 사용

### partial_sort_copy(b, e, b', e', (f))
- 따로 갯수를 받지 않고, v2의 크기만큼 채운다. 






















