import sys
input = sys.stdin.readline

INF = sys.maxsize
N, M, A, B, C = map(int, input().split())
graph = [[] for _ in range(N+1)]
cost = []

for _ in range(M):
    u, v, w = map(int, input().split())
    graph[u].append([w, v])
    graph[v].append([w, u])
    cost.append(w)

import heapq as hq

def dijkstra(limit):
    dist = [INF for _ in range(N+1)]
    dist[A] = 0 #시작점 초기화

    PQ = []
    hq.heappush(PQ, [0, A])

    while PQ:
        nowcost, nownode = hq.heappop(PQ)

        if dist[nownode] < nowcost:
            continue

        for nxtcost, nxtnode in graph[nownode]:
            if dist[nxtnode] > nxtcost + nowcost and nxtcost <= limit:
                # 간선 비용 제한 이내일 때 이동
                dist[nxtnode] = nxtcost + nowcost
                hq.heappush(PQ, [nxtcost + nowcost, nxtnode])

    if dist[B] > C:
        return INF
    else:
        return dist[B]

# 간선 비용 최소/최대 값을 기록한 것으로 이분 탐색 하기
cost.sort()
st, ed = 0, len(cost)-1
res = INF

while st <= ed:
    mid = (st + ed) // 2
    total = dijkstra(cost[mid])

    if total == INF:
        st = mid + 1
    else:
        ed = mid - 1
        res = min(res, cost[mid])

print(res if res < INF else -1)
