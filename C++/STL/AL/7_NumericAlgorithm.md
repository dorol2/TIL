# NumericAlgorithm
수치 관련 원소를 다루는 알고리즘</br>
#include \<numeric>헤더에 의해 정의

## accumulate(b, e, x, (f))
- 모든 원소의 합을 구하기 위한 알고리즘.
- x를 초깃값으로 [b, e) 구간의 원소의 총 합을 구한다.
- 순차열 전체에 사용자가 정의한 f연산 수행 가능 
```cpp
template<typename T>
class FunctionTest
{
public:
    T operator () (const T& left, const T& right)
    {
        return ...;
    }
};
```

## inner_product(b, e, b2, x, f1, f2)
- 두 순차열으 내젹(모든 원소의 곱의 합)
- x를 초깃값으로, 두 순차열의 내적을 반환
- f1은 + 연산, f2는 *연산

## adjancent_difference(b, e, t)
- [b, e)의 반복자가 p일때, (*p - *(p - 1))의 연산을 순차열 [t, p)에 저장 
- return 값은 t의 저장하고 난 후의 다음 iterator값

## partial_sum(b, e, t, (f)) 
- 현재 원소까지의 합















