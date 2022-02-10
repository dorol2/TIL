# Nonmodifying algorirhms
- 원소의 순서나 원소의 값이 변경되지 않고 원소를 읽기만 하는 알고리즘

## adjacent_find(b,e,f)
- adjancent_find(시작iterator, 끝iterator, (이항조건))
- 현재 원소와 다음 원소가 같아지는 첫 번째 iterator 반환
- 같은 원소가 없다면 구간에서 끝값 반환

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
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
	
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)	// 10 20 30 30 40 40 50
		cout << v1[i] << " ";	
	cout << endl;

	vector<int>::iterator iter1 = adjacent_find(v1.begin(), v1.end());  // 사용
	if (iter1 != v1.end())
		cout << (*iter1) << endl;				// 30

	for (iter1; iter1 != v1.end(); ++iter1)		// 30 30 40 40 50
		cout << (*iter1) << " ";
	cout << endl;

	vector<int>::iterator startIter = v1.begin();
	vector<int>::iterator endIter = v1.begin() + 3;
	//vector<int>::iterator iter2 = adjacent_find(v1.begin(), v1.end(), Pred);  // 사용
    vector<int>::iterator iter2 = adjacent_find(v1.begin(), v1.end(), [](int a, int b)->bool { return b % a == 0; });   // adjacent_find(b, e, f)사용 & 람다식
	if (iter2 != endIter)   // 구간으로 비교시 없는지 확인
		cout << (*iter2) << endl;				// 10
}
```

## count(b, e, v)
- 찾는 원소(v)의 갯수 반환

### count_if(b, e, f)
- count_if(begin, end, bool function(a))

```cpp
int count = count_if(v1.begin(), v1.end(), [](int a)->bool {return a > 25; });
```

## equal(b, e, b2, (f))
- 두 원소가 같은지(==) 판단
- [b, e) 구간과 [b2, b2 + (e - b))의 순차열이 같은지 판단 : (b2는 e-b개 만큼 비교하므로)

```cpp
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
	bool isEqual = equal(v1.begin(), v1.begin() + 4, v2.begin(), [](int v1Int, int v2Int)->bool { return v1Int == v2Int; });
	cout << isEqual << endl;

}
```

## find(b, e, v) / find_if(b, e, v, f) 
- [b, e) 구간에서 특정 원소를 찾는 알고리즘

### find_end(b, e, b', e', (f))
- return v1의 iterator
- [v1.begin(), v1.end()]의 순차열 구간에 [v2.begin(), v2.end()]의 순차열이 속해 있는 지 판단
- 일치하는 구간이 여러 개라면 마지막 순차열의 첫 원소 반환

### find_first_of(b, e, b', e', (f))
- 두 순차열을 비교하여 모든 원소 중 같은 원소가 하나라도 발견되면 발견된 첫 원소의 iterator를 반환

## for_each(b, e, f)
- [b, e) 구간의 iterator가 p일때, 모든 원소에 대해 f(*p) 적용한다. 
```cpp
for_each(v1.begin(), v1.end(), [](int a) { cout << a << " / "; });
```

```cpp
class PrintFunctor
{
private:
	string split;
public:
	explicit PrintFunctor(string c = " / ") : split(c) { }
	void operator()(int n) const
	{
		cout << n << split;
	}
};

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

    //functor 사용
	for_each(v1.begin(), v1.end(), PrintFunctor()); 
	cout << endl;
}
```

## lexicographical_compare(b, e, b', e', (f))
- 순차열의 사전순 비교시 사용 (default : less <)
- 순치열 [b, e)와 [b', e')의 모든 원소를 문자열 처럼 비교

## max(a, b, (f)), min(a, b, (f))
- c/c++의 기본 타입이 아닌 경우 직접 비교가 안되기 때문에 3번째 인자로 비교 규칙을 명시한 함수를 넣어야 한다.

## max_element(b, e, (f)), min_element(b, e, (f))
- 범위 내 최댓값과 최솟값 반환
- f로 비교 가능 

ex)
```cpp
class Point
{
	int x;
	int y;

public:
	explicit Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
	int GetX() const { return x; }
	int GetY() const { return y; }
	void Print() const { cout << "(" << x << " / " << y << ")" << endl; }
};

bool Compare(const Point& left, const Point& right)
{
	if (left.GetX() < right.GetX())
		return true;
	else if (left.GetX() > right.GetX())
		return false;
	else
		return left.GetY() < right.GetY();
}

int main()
{
	vector<Point> v;
	v.push_back(Point(3, 2));
	v.push_back(Point(2, 5));
	v.push_back(Point(1, 5));
	v.push_back(Point(3, 3));
	v.push_back(Point(3, 2));

	vector<Point>::iterator iter = max_element(v.begin(), v.end(), Compare);

	cout << "Max : ";
	(*iter).Print();	//iter->Print()
	cout << endl;

	return 0;
}
```

## mismatch(b, e, b', (f))
- 두 순차열을 비교하여 원소의 값이 서로 다른 위치를 찾아 iterator pair를 반환
- 반환되는 pair는 v1의 iterator, v2의 iterator 이다. 
- 두 순차열의 크기가 다르면 오류난다. 

```cpp
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
v2.push_back(40);
v2.push_back(40);
v2.push_back(40);
v2.push_back(40);

pair<vector<int>::iterator, vector<int>::iterator> mismatchPair;
mismatchPair = mismatch(v1.begin(), v1.end(), v2.begin());
cout << *mismatchPair.first << " / " << *mismatchPair.second << endl;   // 30 / 40
```

## search(b, e, b', e', (f))
순차열 [b, e)에 [b', e')의 순차열이 일치하는지 판단하여 일치하는 순차열 구간이 여러 개라면 첫 번째 순차열의 첫 원소 iterator를 반환한다.
(find_frist_of()와 반환 같아 보임)

### search(b, e, n, x)
[b, e) 구간에서 원소 x가 n번 연속한 첫 원소의 iterator 반환

```cpp
vector<int> v;
v.push_back(10);
v.push_back(20);
v.push_back(30);
v.push_back(30);
v.push_back(30);
v.push_back(40);
v.push_back(50);

vector<int>::iterator iter;
iter = search_n(v.begin(), v.end(), 3, 30);
if( iter != v.end() )
{
    cout << "iter : " << *iter << endl;         // 30
    cout << "iter-1 : " <<*(iter-1) << endl;    // 20
    cout << "iter+1 : " <<*(iter+1) << endl;    // 30
}
```




















