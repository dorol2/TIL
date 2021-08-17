# Unity Coroutine
프레임과 상관 없이 별도의 서브 루틴에서 원하는 작업을 원하는 시간만큼 수행하는 것이 가능하다.
반환형으로 IEnumerator를 사용하고, yield return구문을 적어도 한 번 이상 사용한다.
코루틴이 함수에 정의된 작업을 실행하다가 yield return구문을 만나면 yield return으로 정의된 작업을 하고,코루틴을 호출했던 루틴으로 제어 권한을 넘겨준다. 이것으로 코루틴의 실행이 일시적으로 중지되는 것이다.

**yield return**

|yield return|설명|
|---|---|
|null|다음 프레임까지 대기|
|new WaitForSeconds(float)|지정한 초만큼 대기|
|new WaitForSecondRealtime(float)|timeScale의 영향을 받지 않고, 현실 시간 기준으로 동작한다.|
|new WaitForFixedUpdate()|다음 물리 프레임까지 대기 (FixedUpdate) |
|new WaitForEndOfFrame()|하나의 프레임이 완전히 종료될 때까지 대기|
|StartCoRoutine(string)|다른 코루틴이 끝날 때까지 대기|
|new WWW(string)|웹 통신 작업이 끝날 때까지 대기|
|new AsyncOperation|비동기 작업이 끝날 때까지 대기|
|new WaitUntil(system.Func<Bool> predicate)|특정 조건식이 성공할 때까지 대기|
|new WaitWhile(system.Func<Bool> predicate)|특정 조건식이 false가 될 때까지 대기|


```csharp
StartCoroutine(TestCo());
StartCoroutine("TestCo");
```

코루틴의 함수 이름을 문자열 형식 또는 함수를 전달할 수 있다.
문자열로 전달할 경우, 간편하게 사용할 수는 있지만, 실제 메소드를 찾아내는 과정이 필요하기 때문에 성능이 저하될 수 있다.

- 반드시 MonoBehaviour를 상속하고 있어야 한다.
- 게임오브젝트에 컴포넌트로 붙어 있어야 동작한다.


**예시**

여러 아이템의 다운로드 여부를 체크하는 부분에 사용했었다.

```csharp
public class DownloadCheckClass : MonoBehaviour
{
    public void DownloadCheck(List<Item> itemList, Action<Dictionary<string, int>> completeCallback, Action<float> progress)
    {
        StartCoroutine(CheckRoutine(itemList, completeCallback, progress));
    }

    private IEnumerator CheckRoutine(List<Item> itemList, Action<Dictionary<string, int>> completeCallback, Action<float> progress)
    {
        //null check 등...
        int count = 0;
        Dictionary<string, int> checkDictionary = new Dictionary<string, int>();

        foreach(var item in itemList)          
        {
            var itemKey = item.key;
            Check(itemKey, completeInteger =>
            {
                //해당 key의 아이템을 이미 다운로드 했는지 확인
                ++count;
                if(!checkDictionary.ContainsKey(itemKey))
                    checkDictionary.Add(itemKey, completeInteger);
                progress.Invoke((float) checkDictionary.Count / itemList.Count);
            });
        }

        yield return new WaitUntil(() => count == itemList.Count);

        completeCallback.Invoke(checkDictionary);
    }
}

```

**예시 2**

특정 오브젝트의 생성까지 기다렸다가 진행하는 부분에 사용

```csharp
public void
```


---

- 2021-05-16 : 생성 & 작성
