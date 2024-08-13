import sys
input = sys.stdin.readline
N, M, K = map(int, input().split())
grid = []

for _ in range(N):
    grid.append(list(input().rstrip()))

# 칠해야 하는 위치에 따라 add를 정하고, 2차원 누적합 배열을 구한다.
def cal_min(nowC):
    add = 0
    pre_s = [[0] * (M+1) for _ in range(N+1)]
    for i in range(N):
        for j in range(M):
            if (i+j)%2 == 0:
                if(grid[i][j] != nowC): add = 1
                else: add = 0
            else:
                if (grid[i][j] == nowC): add = 1
                else: add = 0
            pre_s[i+1][j+1] = pre_s[i][j+1] + pre_s[i+1][j] - pre_s[i][j] + add

    res = 2000*2000+1
    for i in range(1, N-K+2):
        for j in range(1, M-K+2):
            res = min(res, pre_s[i+K-1][j+K-1]-pre_s[i+K-1][j-1]-pre_s[i-1][j+K-1] + pre_s[i-1][j-1])
          #K 칸의 체스판 중 누적합 값이 min이 되는 값을 구한다. (칠하는 횟수의 최소)
    return res

print(min(cal_min("B"), cal_min("W")))
