# philosophers : 식사하는 철학자 문제 구현 프로젝트
동시성 문제를 해결하기 위해 철학자들이 교착 상태 없이 식사, 생각, 잠자기를 반복하도록 하는 멀티스레드/멀티프로세스 시스템을 구현하는 프로젝트입니다.

![2024-06-036 39 45-ezgif com-video-to-gif-converter](https://github.com/im-madylin/philosophers/assets/85945788/44208114-d4fc-402b-937c-ef19ca2be19d)



### 식사하는 철학자 문제란,
식사하는 철학자 문제(Dining Philosophers Problem)는 1965년 에츠허르 데이크스트라(Edsger W. Dijkstra)가 제안한 고전적인 동시성 문제입니다. 이 문제는 여러 프로세스 간의 자원 경쟁과 교착 상태(deadlock)를 설명하기 위한 비유로 자주 사용됩니다.

## 프로젝트 요구사항
### 공통
- N명의 철학자가 원탁에 앉아 있고, N개의 포크가 준비되어 있습니다.
- 철학자는 먹거나, 자거나, 생각하는 행동을 해야 합니다.
- 먹기 위해서는 포크 2개가 필요합니다.
- 철학자는 서로 소통할 수 없습니다.
- 교착 상태가 발생하지 않아야 합니다.
- 데이터 레이스가 발생하지 않아야 합니다.
- 철학자가 행동을 했을 때 타임스탬프와 함께 내용을 출력해야 합니다.
- 출력 순서가 섞이면 않아야 합니다.
- 철학자가 한 명이라도 죽거나, 지정된 식사 횟수를 채워 시뮬레이션이 종료된 경우 다른 철학자의 행동이 출력되지 않아야 합니다.
- 지연을 최소화 해야 합니다.
- 철학자는 죽는 것을 피해 오래 살아야 합니다.


### 필수 파트
- 철학자 사이에 포크가 하나씩 놓여 있습니다.
- 같은 프로세스 내에서 메모리를 공유합니다.

### 보너스 파트
- 원탁 가운데에 모든 포크가 놓여 있습니다.
- signal() 함수만을 사용하여 프로세스 간 통신해야 합니다.
- getpid() 함수는 사용할 수 없습니다. (자식이 부모에게 시그널을 보낼 수 없습니다.)


## 설치 방법
1. 저장소 복제
   ```
   git clone https://github.com/im-madylin/philosophers.git
   ```
2. 디렉토리 이동
   ```
   cd philo   //mandatory part (멀티스레드)
   cd philo_bonus  //bonus part (멀티프로세스)
   ```
3. 컴파일
   ```
   make
   ```

## 실행 방법
```
./philo <철학자 수> <먹지 않고 살 수 있는 시간> <밥 먹는 시간> <생각하는 시간> {<최소 먹어야 하는 식사 횟수>}
```


