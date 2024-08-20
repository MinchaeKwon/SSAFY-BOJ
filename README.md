# SSAFY 12기 알고리즘 스터디
#### 삼성 역량테스트 B형 취득, 코테 대비를 목적으로 진행합니다.
#### [회의록📋](https://docs.google.com/document/d/1EjaM0CXsTt4PHvZbOxp-2EXrSIyDbMyl6VO1BHClmkc/edit?usp=sharing)

## Rules
- 매 주 정해진 알고리즘 주제 하에 문제를 추천합니다.
- 팀원 별 한 개의 문제를 추천하여 주 4개의 문제를 풉니다.
- 주 1회, 오프라인 모임을 통해 본인 코드를 설명하고 최적화를 위한 코드 리뷰를 합니다.

## Members

| 이름 (Github Link) | 소속 |
|------------------|------|
| [강진주](https://github.com/Pearl-K) | 전공 Java반 |
| [권민채](https://github.com/MinchaeKwon) | 전공 Java반 |
| [나영조](https://github.com/Taebee00) | 전공 임베디드반 |
| [이승록](https://github.com/SeokguKim) | 전공 임베디드반 |




## Week 1 : 재귀 ✅
[2705. 팰린드롬 파티션](https://www.acmicpc.net/problem/2705)
- N을 기준으로 홀/짝 경우를 나눠서 생각하기
- 문제를 부분 문제로 분할하다보면 이전의 값을 쓸 수 있다는 사실을 발견할 수 있다.
- 팀원들은 대체로 재귀를 사용한 top-down dp의 형식으로 접근했다. 


[16719. ZOAC](https://www.acmicpc.net/problem/16719)
- 문자열에서 가장 앞에 오는 문자의 위치를 발견
- 해당 위치~end 까지 먼저 재귀를 돌리고, 다음에 start ~현재 위치 재귀 함수를 돌린다 (정석 풀이)
- 문자열의 길이가 100으로 짧게 주어지기 때문에, 모든 문자를 탐색하여 정렬하는 풀이가 제한 시간 안에 돈다.


[20164. 홀수 홀릭 호석](https://www.acmicpc.net/problem/20164)
- 길이가 1, 2, 3 이상일 때 경우를 각각 나눠서 처리
- 3 이상일 때 이중 for문 사용하여 전체 문자열에서 가능한 모든 분기점을 잡고 3분할 하여 확인


[1278. 연극](https://www.acmicpc.net/problem/1278)
- 비트마스킹으로 next 상태를 표현할 수 있음


## Week 2 : 백트래킹 ✅
[1342. 행운의 문자열](https://www.acmicpc.net/problem/1342)
 - 팀원들이 각자 다양한 방법으로 풀어서 아이디어를 공유했다.
   1. 백트래킹으로 가능한 조합을 찾아주면서 중복 체크 해주기
   2. C++의 next_permutation을 이용하여 가능한 순열 찾기
   3. 문자열 중복을 고려하여 팩토리얼을 활용한 식으로 개수를 세어 활용


[10597. 순열장난](https://www.acmicpc.net/problem/10597)
 - 기본적으로 담을 수 있는 한자리 수와 두자리 숫자를 나눠서 백트래킹으로 더했다.
 - 구현 측면에서 팀원들마다 세부적인 차이가 나왔다.
    1. 최대값 N을 찾아서 한계값을 정하고 시작하는지 아닌지
    2. 가지치기 할 때 세부 조건 차이 등


[17255. N으로 만들기](https://www.acmicpc.net/problem/17255)
 - 기본적으로 왼쪽 포인터와 오른쪽 포인터를 나눠서 각각 백트래킹으로 추가했다.
 - 중복되는 과정을 체크해주는게 중요 (팀원들은 각각 Set, Map, HashSet 등을 활용하여 중복 체크)


[1443. 망가진 계산기](https://www.acmicpc.net/problem/1443)
 - 자릿수의 한계가 주어졌기 때문에 큰 수부터 곱하면서 가지치기를 하는 방법이 Java로 통과한다.
 - 위와 같은 방법이 C++으로도 충분히 통과한다.


## Week 3 : DP ✅
[2502. 떡 먹는 호랑이](https://www.acmicpc.net/problem/2502)
 - 바텀업 dp나 피보나치 수열의 점화식을 통해서 cnt를 셀 수 있다.
 - 가능한 경우 중 하나만 찾으면 되므로 for문과 간단한 수식을 통해 경우를 구할 수 있다.


[17265. 나의 인생에는 수학과 함께](https://www.acmicpc.net/problem/17265)
 - grid의 범위 제한이 작고 숫자와 연산자의 위치가 규칙성이 있다.
 - 우하향 방향으로만 가는 dfs를 통해 max와 min을 갱신해주면 된다.


[12784. 인하니카 공화국](https://www.acmicpc.net/problem/12784)
 - tree dp 문제, 리프노드 가중치의 합과 부모노드 가중치 중에 min을 갱신한다.
 - 리프노드를 체크해주는 조건과 엣지케이스를 처리하는게 중요하다.

[2629. 양팔저울](https://www.acmicpc.net/problem/2629)
- 2차원 냅색 문제, 1차원 dp 테이블로 풀고 싶다면 상태를 비트마스킹으로 표현할 수 있다.


## Week 4 : 누적 합 ✅
[21758. 꿀 따기](https://www.acmicpc.net/problem/21758)
 - 누적 합 배열을 이용하여 부분합의 구간, 값을 빼야 하는 위치를 잘 파악하는 문제


[25682. 체스판 다시 칠하기](https://www.acmicpc.net/problem/25682)
 - 2차원 누적 합 테이블의 응용
 - Black과 White 중 어느 것을 중점으로 둘 지 파악한 후, 누적 합을 통해 칠하는 최소 횟수를 파악한다.

[2632. 피자판매](https://www.acmicpc.net/problem/2632)
 - 원형 형태를 배열으로 표현한 후, 누적합을 계산하는 테크닉이 필요하다.
 - 가능한 누적 합 조합 수를 파악한 후 이분 탐색 or 해시맵 + 완탐을 통해 경우의 수를 구할 수 있다.


## Week 5 : Greedy ✅
[12904. A와 B](https://www.acmicpc.net/problem/12904)
 - 

[1461. 도서관](https://www.acmicpc.net/problem/1461)
 - 

[1826. 연료 채우기](https://www.acmicpc.net/problem/1826)
 - 
 
[4716. 풍선](https://www.acmicpc.net/problem/4716)
 - 
