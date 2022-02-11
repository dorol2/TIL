# FunctionObject (함수 객체)
- operator() 연산자를 오버로딩 한 클래스 객체 

## STL의 함수 객체
- 일반 함수 객체 : 특정 기능을 수행하는 함수 객체
    - 산술 연산 함수 객체
    - 비교 연산 함수 객체 조건자
    - 논리 연산 함수 객체 조건자
- 함수 어댑터 </br> : 함수류(함수 객체, 함수, 함수 포인터)를 인자로 받아 다른 함수 객체로 변환
    - 바인더 (binder) : 이항 함수 객체를 단항 함수 객체로 변환
    - 부정자 (negator) : 결과값을 반대로 바꾸는 것
    - 함수 포인터 어댑터 
    - 멤버 함수 포인터 어댑터
- 함수자 사용의 장점
    - 컴파일 시에 함수자를 알고리즘의 인자로 전달 가능
    - 함수 호출을 인라인화해서 효율성 향상
    - 함수자의 정보를 캡슐화하여 지역화


## 함수 객체 조건자
```cpp
#include <iostream>
using namespace std;

struct LessFunctor
{
	bool operator() (int left, int right) const	// 1. 함수 객체 조건자
	{
		return left < right;
	}
};

bool LessFun(int left, int right)			// 2. 함수 조건자
{
	return left < right;
}

int main()
{
	LessFunctor lessFunctor;				// 1. 함수 객체 조건자
	cout << lessFunctor(10, 20) << endl;	

	cout << LessFun(10, 20) << endl;		// 2. 함수 조건자

	bool (*LessPtr) (int, int) = LessFun;	// 3. 함수 포인터 조건자
	cout << LessPtr(10, 20) << endl;
}
```

## 어댑터
- 함수 객체를 다른 함수 객체로 변환할 때 정의된 형식을 사용해서 변환 수행.
    - STL의 unary_function / binary_function 상속받아 사용
- 단항 함수 객체 : 반드시 argument_type, result_type 정의 되어야 한다. 
- 이항 함수 객체 : 반드시 first_argument_type, second_argument_type, result_type리 정의되어 있어야 한다. 

> [transform() 참고](https://github.com/dorol2/TIL/blob/master/C%2B%2B/STL/AL/2_ModifyingAlgorithms.md#transformb-e-t-fp)
### ex) 1
```cpp
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
struct Plus
{
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef T result_type;


    T operator( )(const T& left, const T& right) const
    {
        return left + right;
    }
};
void main( )
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v3(3); //size: 3인 vector 생성
    //STL 조건자 plus<int> 사용
    //transform(v1.begin(), v1.end(), v3.begin(), binder1st< plus<int> > (plus<int>(), 100));
    //사용자 정의 조건자 Plus<int> 사용
    transform(v1.begin(), v1.end(), v3.begin(), binder1st< Plus<int> > (Plus<int>(), 100) );

    cout <<"v1 : ";
    for(vector<int>::size_type i = 0 ; i < v1.size() ; i++)
        cout << v1[i] << " ";
    cout << endl;

    cout <<"v3 : ";
    for(vector<int>::size_type i = 0 ; i < v3.size() ; i++)
        cout << v3[i] << " ";
    cout << endl;
}
```
### ex) 2 binary_function 상속받아 사용
```cpp
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
struct Plus: public binary_function<T,T,T>
{
    T operator( )(const T& left, const T& right) const
    {
        return left + right;
    }
};
void main( )
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v3(3); //size: 3인 vector 생성
    //STL 조건자 plus<int> 사용
    //transform(v1.begin(), v1.end(), v3.begin(), binder1st< plus<int> > (plus<int>(), 100));
    //사용자 정의 조건자 Plus<int> 사용
    transform(v1.begin(), v1.end(), v3.begin(), binder1st< Plus<int> > (Plus<int>(), 100) );

    cout <<"v1 : ";
    for(vector<int>::size_type i = 0 ; i < v1.size() ; i++)
        cout << v1[i] << " ";
    cout << endl;

    cout <<"v3 : ";
    for(vector<int>::size_type i = 0 ; i < v3.size() ; i++)
        cout << v3[i] << " ";
    cout << endl;
}
```
출력 결과
```
v1 : 10 20 30
v3 : 110 120 130
```

## 산술 연산 함수 객체
(p.455)


## 비교 연산 조건자

### EX
> [count_if](https://github.com/dorol2/TIL/blob/master/C%2B%2B/STL/AL/1_NonmodifyingAlgorirhms.md#count_ifb-e-f)
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

void main( )
{
    vector<int> v;
    v.push_back(10); 
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout <<"v : ";
    for(vector<int>::size_type i = 0 ; i < v.size() ; i++)
        cout << v[i] << " ";
    cout << endl;

    cout << "20 보다 작은 원소의 개수: " << count_if(v.begin(), v.end(), bind2nd<less<int>>(less<int>(), 20)) << endl;

    cout << "20 보다 작거나 같은 원소의 개수: " << count_if(v.begin(), v.end(),bind2nd<less_equal<int>>(less_equal<int>(), 20)) << endl;

    cout << "20 보다 큰 원소의 개수: " << count_if(v.begin(), v.end(), bind2nd<greater<int>>(greater<int>(), 20)) << endl;

    cout << "20 보다 크거나 같은 원소의 개수: " << count_if(v.begin(), v.end(), bind2nd<greater_equal<int>>(greater_equal<int>(), 20)) << endl;

    cout << "20과 같은 원소의 개수: " << count_if(v.begin(), v.end(), bind2nd<equal_to<int>>(equal_to<int>(), 20)) << endl;

    cout << "20과 다른 원소의 개수: " << count_if(v.begin(), v.end(), bind2nd<not_equal_to<int>>(not_equal_to<int>(), 20)) << endl;
}
```



## 논리 조건 연산자
|       함수자     |   내용      |   비고    |
|------           |        -----|        ---|
| logical_and\<T> | AND ( && ) 연산 | 이항조건자 |
| logical_or\<T> | OR ( \|\| ) 연산 | 이항조건자 |
| logical_not\<T> | NOT( ! )연산 | 이항조건자 |

## 바인더 (binder)
이항 함수자를 단항 함수자로 변환
- bind1st : 
- bind2nd : 

## 부정자
이항조건자를 반대의 조건자로 변환
- not1 : 
- not2 : 

## 함수 포인터 어댑터
- 일반 함수를 어댑터 적용이 가능한 함수 객체로 변환
- STL에서 ptr_fun() 제공

## 멤버 함수 포인터 어댑터







