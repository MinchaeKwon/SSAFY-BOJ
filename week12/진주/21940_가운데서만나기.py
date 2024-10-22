import sys
input = sys.stdin.readline
N, M = map(int, input().split())
INF = 1e9
dist = [[INF for _ in range(N+1)] for _ in range(N+1)]

for i in range(M):
    a, b, t = map(int, input().split())
    dist[a][b] = t

K = int(input())
frnds = list(map(int, input().split()))

for i in range(N+1):
    dist[i][i] = 0

def fw():
    for r in range(1, N+1):
        for p in range(1, N+1):
            for q in range(1, N+1):
                if dist[p][q] > dist[p][r] + dist[r][q]:
                    dist[p][q] = dist[p][r] + dist[r][q]
fw()
res = []
min_time = INF
for i in range(1, N+1):
    tmp = 0
    for f in frnds:
        tmp = max(dist[f][i] + dist[i][f], tmp)

    if tmp < min_time:
        res = [i]
        min_time = tmp
    elif tmp == min_time:
        res.append(i)
print(*res)
