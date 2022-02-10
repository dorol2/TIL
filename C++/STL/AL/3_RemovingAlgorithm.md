# RemovingAlgorithm

## remove(b, e, x)
- [b, e)구간에서 x의 원소를 삭제
- size에 변화 없음(논리적으로 제거) -> 한 칸씩 복사하여 넣음 
    - size변경 하고 싶은 경우 v.erase() 사용
- return iterator는 복사
EX)
```cpp
void main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "v : ";
    for (vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << "(" << v[i] << ", " << &v[i] << ") ";
    cout << endl;

    vector<int>::iterator iter_end;
    iter_end = remove(v.begin(), v.end(), 30);

    cout << "v : ";
    for (vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << "(" << v[i] << ", " << &v[i] << ") ";
    cout << endl;

    cout << "remove 후 [v.begin(), iter_end) 순차열: " << endl;
    cout << "v : ";
    for (vector<int>::iterator iter = v.begin(); iter != iter_end; ++iter)
        cout << "(" << *iter << ", " << &(*iter) << ") ";
    cout << endl;

    v.erase(iter_end, v.end());

    cout << "erase 후 : " << endl;

    cout << "v : ";
    for (vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << "(" << v[i] << ", " << &v[i] << ") ";
    cout << endl;
}
```
출력 결과
```
v : (10, 000002088172F050) (20, 000002088172F054) (30, 000002088172F058) (40, 000002088172F05C) (50, 000002088172F060)
v : (10, 000002088172F050) (20, 000002088172F054) (40, 000002088172F058) (50, 000002088172F05C) (50, 000002088172F060)
remove 후 [v.begin(), iter_end) 순차열:
v : (10, 000002088172F050) (20, 000002088172F054) (40, 000002088172F058) (50, 000002088172F05C)
erase 후 :
v : (10, 000002088172F050) (20, 000002088172F054) (40, 000002088172F058) (50, 000002088172F05C)
```

### remove_copy(b1, e1, b2, x)
- 원본을 변경하지 않고 제거한 순차열 복사

## unique(b, e)
- 인접한 중복된 원소 제거 (인접하지 않은 중복 원소는 남아있음)
- 논리적 제거 -> 삭제하고 앞으로 값만 복사 : size 변화 X

### unique(b, e, f)
- 조건에 따라 삭제 여부 결정

















