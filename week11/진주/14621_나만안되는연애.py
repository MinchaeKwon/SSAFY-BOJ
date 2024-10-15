import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**4)
#union find를 이용한 mst
N, M = map(int, input().split())
gender = ['_']
gender += list(input().split())

tmp = []
for _ in range(M):
    tmp.append((map(int, input().split())))

edges = []
for a, b, dist in tmp:
    if gender[a] != gender[b]:
        edges.append((dist, a, b))

edges.sort()
parents = [i for i in range(N+1)]

def find_p(n):
    if parents[n] == n:
        return n
    parents[n] = find_p(parents[n])
    return parents[n]

def union(a,b):
    a = find_p(a)
    b = find_p(b)
    if a<b:
        parents[b] = a
    elif a>b:
        parents[a] = b

res = 0
for dist, a, b in edges:
    if find_p(a) != find_p(b):
        union(a,b)
        res += dist

root = find_p(1)
for i in range(1, N+1):
    if root != find_p(i):
        res = -1
        break
print(res)
