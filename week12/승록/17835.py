# 간선 정보들을 모두 역으로 저장하게 되면, 각각의 면접장들을 시작점으로 두고 다익스트라를 돌리면 된다.
import sys
import heapq

N, M, K = map(int, sys.stdin.readline().rstrip().split())
dist = [-1] * (N + 1)
vv = {}
# 간선 정보를 역으로 저장해준다.
for _ in range(M):
    a, b, w = map(int, sys.stdin.readline().rstrip().split())
    if b not in vv:
        vv[b] = []
    vv[b].append([a, w])
# 면접장에 해당하는 도시들을 출발 노드로 설정하고 거리 0으로 설정한다.
q = []
k = [int(val) for val in sys.stdin.readline().rstrip().split()]
for spot in k:
    dist[spot] = 0
    heapq.heappush(q, [0, spot])
# 다익스트라
while q:
    cur, u = heapq.heappop(q)

    if u not in vv or (dist[u] >= 0 and dist[u] < cur):
        continue

    for v, w in vv[u]:
        nxt = cur + w
        if dist[v] == -1 or nxt < dist[v]        :
            dist[v] = nxt
            heapq.heappush(q, [nxt, v])

md_city = -1
max_dist = 0
for i in range(1, N + 1):
    if dist[i] > max_dist:
        max_dist = dist[i]
        md_city = i

print(f"{md_city}\n{max_dist}")