# MutatingAlgorithm
순차열의 원소를 서로 교환하거나 이동하여 순차열 원소의 순서를 변경

## partition(b, e, f)
순차열의 원소를 특정 조건에 따라 분류
iterator가 반환되는데, [begin, 반환iterator) 참 / [반환iterator, end) 거짓 으로 분류

### stable_partition
- 원소의 *상대적인 순서*를 유지하면서 조건에 대한 참과 거짓을 분류
- buffer를 사용해서 구현된다. 

## random_shuffle()
순차열의 원소의 순서를 랜덤으로 뒤섞는다 

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

    // 추가 랜덤 초깃값 (#include <ctime> 필요)
	srand((unsigned)time(NULL));

	random_shuffle(v.begin(), v.end());
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	random_shuffle(v.begin(), v.end());
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	return 0;
}
```

## reverse()
순차열의 모든 원소를 역순으로 뒤집는다. 

## rotate(b, middle, e)
- [b, e)구간의 순차열을 middle - v.begin() 만큼 회전한다. 
- rotate_copy : 회전하여 다른 순차열에 저장



















