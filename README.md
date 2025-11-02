# 프로세스 협력 파일 처리기

### 개요

- 클라이언트-서버 모델을 사용하여 파일의 각 줄 처리

- 클라이언트는 파일의 각 줄을 서버에 전송

- 서버는 지정된 처리 모드에 따라 각 줄을 처리한 후 결과를 클라이언트에 반환

- 처리 모드:

  - count: 문자 수 및 단어 수 계산

  - upper: 대문자로 변환

  - lower: 소문자로 변환

  - reverse: 문자열 뒤집기

- 사용법

```

./file_processor_clnt <input_file> <mode>

```

- <input_file>: 처리할 텍스트 파일의 경로

- <mode>: count, upper, lower, reverse 중 하나

## 실행결과

### 클라이언트: count

```

./file_processor_clnt test.txt count

  1번째 줄 전송...
  1번째 줄 결과 수신: Line 1: 12 chars, 2 words
  2번째 줄 전송...
  2번째 줄 결과 수신: Line 2: 19 chars, 2 words
  3번째 줄 전송...
  3번째 줄 결과 수신: Line 3: 26 chars, 3 words
  4번째 줄 전송...
  4번째 줄 결과 수신: Line 4: 21 chars, 2 words
  5번째 줄 전송...
  5번째 줄 결과 수신: Line 5: 18 chars, 5 words

  === 처리 통계 ===
  처리 모드: count
  처리한 줄 수: 5
  소요 시간: 0.00초

```

### 클라이언트: upper

```

./file_processor_clnt test.txt upper

  1번째 줄 전송...
  1번째 줄 결과 수신: Line 1: HELLO WORLD

  2번째 줄 전송...
  2번째 줄 결과 수신: Line 2: SYSTEM PROGRAMMING

  3번째 줄 전송...
  3번째 줄 결과 수신: Line 3: DAEGU CATHOLIC UNIVERSITY

  4번째 줄 전송...
  4번째 줄 결과 수신: Line 4: COMPUTER ENGINEERING

  5번째 줄 전송...
  5번째 줄 결과 수신: Line 5: THIS IS A TEST FILE

  === 처리 통계 ===
  처리 모드: upper
  처리한 줄 수: 5
  소요 시간: 0.00초

```

### 클라이언트: lower

```

./file_processor_clnt test.txt lower

  1번째 줄 전송...
  1번째 줄 결과 수신: Line 1: hello world

  2번째 줄 전송...
  2번째 줄 결과 수신: Line 2: system programming

  3번째 줄 전송...
  3번째 줄 결과 수신: Line 3: daegu catholic university

  4번째 줄 전송...
  4번째 줄 결과 수신: Line 4: computer engineering

  5번째 줄 전송...
  5번째 줄 결과 수신: Line 5: this is a test file

  === 처리 통계 ===
  처리 모드: lower
  처리한 줄 수: 5
  소요 시간: 0.00초

```

### 클라이언트: reverse

```

./file_processor_clnt test.txt reverse

  1번째 줄 전송...
  1번째 줄 결과 수신: Line 1:
  dlroW olleH
  2번째 줄 전송...
  2번째 줄 결과 수신: Line 2:
  gnimmargorP metsyS
  3번째 줄 전송...
  3번째 줄 결과 수신: Line 3:
  ytisrevinU cilohtaC ugeaD
  4번째 줄 전송...
  4번째 줄 결과 수신: Line 4:
  gnireenignE retupmoC
  5번째 줄 전송...
  5번째 줄 결과 수신: Line 5: elif tset a si sihT

  === 처리 통계 ===
  처리 모드: reverse
  처리한 줄 수: 5
  소요 시간: 0.00초

```

### 서버

```

  1번째 줄 처리 중...
  2번째 줄 처리 중...
  3번째 줄 처리 중...
  4번째 줄 처리 중...
  5번째 줄 처리 중...
  프로세스 종료

```
