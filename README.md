# TIL

그날그날 알게 된 것들 정리할 예정

# TIL - 1 (2021-04-23)

- unity toggle

```csharp
1.  toggle.onValueChanged.Invoke(true);
2.  toggle.isOn = true;
```

1번은 onValueChanged에 연결된 이벤트만 호출하고 토글 자체는 on이 안된다.
2번은 토글도 on시키고 onValueChanged도 invoke 한다.
