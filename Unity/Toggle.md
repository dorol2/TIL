# Unity toggle

## 2021-04-23

```csharp
1.  toggle.onValueChanged.Invoke(true);
2.  toggle.isOn = true;
```

1번은 onValueChanged에 연결된 이벤트만 호출하고 토글 자체는 on이 안된다.
2번은 토글도 on시키고 onValueChanged도 invoke 한다.


## 2021-05-16

```csharp
toggle.SetIsOnWithoutNotify(true);
```
토글에 연결된 이벤트를 호출하지 않고 토글의 값만 바꾼다.
