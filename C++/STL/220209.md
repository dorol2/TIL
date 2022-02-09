# Set
- 연관컨테이너 / 노드 기반 컨테이너 / 균형 이진 트리
    - 연산 O(log(n)) : find, count, lower_bound, upper_bound, equal_range
    - 삽입 O(log(n)) : insert
- 유일한 key값을 가짐
- 자동 오름차순 정렬 (내림차순 : set<int, greater\<int>> s)

## 인터페이스
- __insert__ : 반환값 : __pair(set\<int>::iterator, bool)__
- __find(인자)__ : return set<T>::iterator
- __count(인자)__ : return 해당 인자의 갯수 => set은 원소의 중복을 허용하지 않으므로 있으면 1 없으면 0
- __lower_bound(인자), upper_bound(인자)__ : return set<T>::iterator => 인자가 시작하는 부분의 iterator, 인자가 끝나는 부분의 iterator
- __equal_bound(인자)__ : return pair<set<int>::iterator, set<int>::iterator> => first = lower_bound, second = upper_bound

```cpp
#include<iostream>
#include<set>
using namespace std;

int main()
{
	set<int> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)	// 10 30 40 50 70 80 90
		cout << *iter << " ";
	cout << endl;

	/*pair*/
	pair<set<int>::iterator, bool> setPair;
	setPair = s.insert(50);

	cout << *setPair.first << " / " << setPair.second << endl; // 50 / 0

	/*find*/
	set<int>::iterator findIterator = s.find(30);
	if (findIterator != s.end())
		cout << *findIterator << endl;	// 30
	else
		cout << "없음" << endl;

	/*count*/
	cout << s.count(40) << endl; // 1  => set은 원소의 중복을 허용하지 않으므로 있으면 1 없으면 0

	/*lower_bound, upper_bound*/
	set<int>::iterator lowerIterator = s.lower_bound(30);		// 인자가 시작하는 구간의 iterator
	set<int>::iterator upperIterator = s.upper_bound(30);		// 인자가 끝나는 구간의 iterator

	cout << *lowerIterator << " / " << *upperIterator << endl;	// 30 / 40

	/*equal_range*/
	pair<set<int>::iterator, set<int>::iterator> equalPair = s.equal_range(30);

	cout << *equalPair.first << " / " << *equalPair.second << endl;	// 30 / 40 => first = lower_bound, second = upper_bound

	return 0;
}
```


















