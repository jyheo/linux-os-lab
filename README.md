# OperatingSystemExercise



## 스레드 테스트
1. thread.c를 컴파일하여 실행해보고 결과를 살펴보시오. 왜 그런 순서로 나왔는지 이유를 설명하시오.  
힌트: sleep()으로 인해 스레드가 블럭(blocked)됨

```
$ make
$ ./thread
```

2. 여러번 실행 해보고 실행할 때마다 결과가 달라지는지 확인해 보시오. 달라지는 이유에 대해서 설명해보시오.

## 경쟁조건 테스트
* race_cond.c
* race_cond_2.c

## 상호배제 적용
* race_mutex.c
