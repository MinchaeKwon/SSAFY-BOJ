# N = 200 밖에 안되므로, N ^ 3으로 플로이드-워셜 알고리즘을 이용해 모든 경로의 길이를 구할 수 있다.
# 구한 모든 i - j 경로를 이용해 조건에 해당하는 도시들만 고르자.
import sys

N, M = map(int, sys.stdin.readline().rstrip().split())
# arr의 각각의 원소 초기값은 적당히 큰 2 ^ 20 정도로 잡았다.
arr = [[1 << 20] * (N + 1) for _ in range(N + 1)]
for k in range(1, N + 1):
    arr[k][k] = 0

for _ in range(M):
    a, b, w = map(int, sys.stdin.readline().rstrip().split())
    arr[a][b] = min(arr[a][b], w)

K = int(sys.stdin.readline().rstrip())
freinds = [int(f) for f in sys.stdin.readline().rstrip().split()]
# 플로이드-워셜
for k in range(1, N + 1):
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j])
# 조건에 해당하는 도시들만 골라주자.
min_dist = 1 << 20
md_cities = []
for k in range(1, N + 1):
    cur = 0
    for f in freinds:
        cur = max(cur, arr[f][k] + arr[k][f])
    
    if cur < min_dist:
        min_dist = cur
        md_cities = []

    if cur == min_dist:
        md_cities.append(str(k))

print(" ".join(md_cities))