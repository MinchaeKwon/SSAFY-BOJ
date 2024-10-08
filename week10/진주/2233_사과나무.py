import sys
input = sys.stdin.readline
n = int(sys.stdin.readline())
arr = list(map(int, input().rstrip()))
x, y = map(int, input().split())

# 방문하는 정점(자기 자신 포함)의 visit cnt 증가
def dfs(node):
    cnt[node] += 1
    for next in adj[node]:
        dfs(next)

st = []
binary_pos = [0] * (2 * n)  # 이진 수열 위치를 나타내는 arr
num = 0
adj = [[] for _ in range(n)]  # 자식 -> 부모 방향 단방향 리스트
cnt = [0] * n  # dfs 방문 cnt
height = [0] * n

for i in range(len(arr)):
    if arr[i] == 0:
        if st:
            # 바로 밑은 부모이므로 높이 1 증가
            height[num] = height[st[-1]] + 1
        st.append(num)
        binary_pos[i] = num
        num += 1
    # 끝날 때 부모 노드와 인접 리스트 연결
    else:
        tmp = st.pop()
        binary_pos[i] = tmp
        if st:
            adj[tmp].append(st[-1])

# 썩은 사과의 정점 번호를 이진수 위치 x-1, y-1로 찾기
x, y = binary_pos[x - 1], binary_pos[y - 1]
dfs(x)
dfs(y)

# res에 모든 정점들의 방문 횟수와 깊이, 정점 번호를 저장
res = []
for i in range(n):
    res.append((cnt[i], height[i], i))

# 공통 조상 정점은 방문 횟수가 2, 그 중에서 가장 깊이가 깊어야 함
# -> 정렬 해서 답 찾기
res.sort(key=lambda x: (-x[0], -x[1]))
for i in range(len(arr)):
    if binary_pos[i] == res[0][2]:
        print(i+1, end=' ')
