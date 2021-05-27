# Task

값을 반환하지 않고 비동기적으로 실행 되는 단일 작업.
스레드 풀로부터 스레드를 가져와 비동기 작업을 실행한다.
(TaskStatus, TaskCompletionSource, Progress ... )

- TPL : Task Parallel Library : Task 관련 클래스와 Parallel 클래스를 합쳐 부르는 것으로, 기본적으로 다중 CPU 병렬 처리를 염두에 두고 만들어졌다.

## async, await
비동기 메서드 - 제공된 키워드 및 형식을 사용해서 수행하려는 작업을 나타내고, 컴파일러는 일시 중단된 메서드에서 컨트롤이 대기 지점으로 반환될 때 수행되어야 하는 항목을 추척하는 등의 나머지 작업을 수행한다.

## TaskCompletionSource
Task<TResult>를 사용할 때, 사용한 곳에 전달할 수 있는 task를 만들 수 있다.

## IProgress
진행률 업데이트를 정의한다. 작업을 시작한 후 잘못 등록된 이벤트 처리기가 업데이트를 누락시킬 수 있는 경우 잘못된 사용으로 인한 경합상태를 없앨 수 있다. 또한 progress 인터페이스를 통해 다양한 진행률 구현을 지원한다.


**예시**

Coroutine을 사용한 부분을 Task로 감싸서 반환값을 넘기도록 하였다.

```csharp
public class Controller
{
    //사용 class
    public async void DownloadCheck()
    {
        var downloadCheckClass = new DownloadCheckClass();

        Dictionary<string, int> checkDictionary =
                await myRoomCategoryPartsDownloadCheck.DownloadCheck(itemList, ItemDownloadCheckProgress);
    }

    private void ItemDownloadCheckProgress(float progress)
    {
        Debug.Log(progress);
    }
}

public class DownloadCheckClass : MonoBehaviour
{
    //Task Class
    public Task<Dictionary<string, int>> DownloadCheck(List<Item> itemList, Action<float> progressCallback)
    {
        var taskCompletion = new TaskCompletionSource<Dictionary<string, int>>();
        var progress = new Progress<float>(progressCallback.Invoke);

        StartCoroutine(CheckRoutine(itemList, taskCompletion, progress));

        return taskCompleteDictionary.Task;
    }

    private IEnumerator CheckRoutine(List<Item> itemList, TaskCompletionSource<Dictionary<string, int>> taskCompletion, IProgress<float> progress)
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

        taskCompletion.SetResult(checkDictionary);
    }
}
```




---
- 2021-05-16 : 생성
- 2021-05-27 : async, await, TaskCompletionSource, IProgress, 예시 작성
