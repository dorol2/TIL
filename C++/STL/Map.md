# Map
- 연관 컨테이너 / 균형 이진 트리
- key, value의 쌍을 저장
- key의 중복을 허용하지 않음
- key 오름차순 정렬
- map<int, int, greater\<int>> : 내림차순 정렬
- [] 연산자를 이용하여 key에 해당하는 value에 쉽게 접근할 수 있다. 

```cpp
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	map<int, int> m;

	m.insert(pair<int, int>(5, 100));
	m.insert(pair<int, int>(3, 100));
	m.insert(pair<int, int>(8, 30));

	m[4] = 70;
	m[1] = 40;
	m[7] = 100;

	pair<int, int> mapPair(9, 50);
	m.insert(mapPair);

	pair<map<int, int>::iterator, bool> insertCheck;
	insertCheck = m.insert(pair<int, int> (2, 50));
	if (insertCheck.second)
		cout << insertCheck.first->first << " / " << (*insertCheck.first).second << " Insert Success" << endl;
	else
		cout << "Insert Fail" << endl;
	
	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << (*iter).first << ", " << (*iter).second << ") ";	// (1, 40) (2, 50) (3, 100) (4, 70) (5, 100) (7, 100) (8, 30) (9, 50)
	cout << endl;

	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << ", " << iter->second << ") ";		// (1, 40) (2, 50) (3, 100) (4, 70) (5, 100) (7, 100) (8, 30) (9, 50)
	cout << endl;

	/*string*/
	map<string, string, greater<string>> m2;
	m2.insert(pair<string, string>("asdf", "asdf"));
	m2.insert(pair<string, string>("wer", "wer"));
	m2.insert(pair<string, string>("e", "wer"));
	m2.insert(pair<string, string>("f", "wer"));
	m2.insert(pair<string, string>("g", "wer"));
	m2.insert(pair<string, string>("h", "wer"));

	map<string, string>::iterator iter2;
	for (iter2 = m2.begin(); iter2 != m2.end(); ++iter2)
		cout << "(" << iter2->first << ", " << iter2->second << ") ";	// (wer, wer) (h, wer) (g, wer) (f, wer) (e, wer) (asdf, asdf)
	cout << endl;
}

```
## 인터페이스
- find(key)
- lower_bound / upper_bound
- equal_bound

# Multimap
- key의 중복 허용
- 중복된 key가 들어오면 정렬 시, 먼저 insert된 순서대로 정렬된다. 

```cpp
#include<iostream>
#include<map>
using namespace std;

int main()
{
	multimap<int, int> multiMap;
	multiMap.insert(pair<int, int>(5, 100));
	multiMap.insert(pair<int, int>(3, 100));
	multiMap.insert(pair<int, int>(8, 30));
	multiMap.insert(pair<int, int>(3, 40));
	multiMap.insert(pair<int, int>(1, 70));
	multiMap.insert(pair<int, int>(7, 100));
	multiMap.insert(pair<int, int>(8, 50));

	multimap<int, int>::iterator iter3;
	for (iter3 = multiMap.begin(); iter3 != multiMap.end(); ++iter3)
		cout << "(" << iter3->first << ", " << iter3->second << ") ";	// (1, 70) (3, 100) (3, 40) (5, 100) (7, 100) (8, 30) (8, 50)
	cout << endl;
}
```

















