# HashTable, Dictionary
[참고](http://www.csharpstudy.com/DS/hash.aspx)

## HashTable

- non-generic collection
- key와 value 값 모두 object 타입을 받는다. 
- 박싱/언박싱 사용
- double hashing 방식 사용하여 collision resolution (2개의 해시함수를 두고, 데이터가 들어올 때, 저장 위치를 띄엄띄엄 둔다. 만약, 같은 주소로 hashing된 경우, 해시함수를 통해 빈 주소를 찾을 때까지 해시함수를 통해 주소를 찾아 간다.) ([참고](https://m.blog.naver.com/beaqon/221300416700?view=img_3))
- 추가, 삭제, 검색에서 O(1)의 시간 소요


## Dictionary

- generic collection
- key와 value 값 모두 strong type을 받는다. 
- 박싱/언박싱 사용 x
- chaining 방식 사용하여 collision resolution (같은 주소로 hashing되는 원소를 모두 하나의 linked list로 관리한다. ) ([참고](http://egloos.zum.com/sweeper/v/925740))
- 추가, 삭제, 검색에서 O(1)의 시간 소요
