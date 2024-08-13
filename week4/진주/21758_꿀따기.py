import sys
input = sys.stdin.readline

N = int(input())
MAX = 100001
arr = [0]*MAX
pre_s = [0]*MAX

tmp = list(map(int, input().split()))

for i in range(1, N+1):
    arr[i] = tmp[i-1]
    pre_s[i] = arr[i] + pre_s[i-1]

res = 0
for i in range(2, N):
    res = max(res, pre_s[N] - arr[1] - arr[i] + pre_s[N] - pre_s[i])

for i in range(2, N):
    res = max(res, pre_s[N] - arr[N] -arr[i] + pre_s[i-1])

for i in range(2, N):
    res = max(res, pre_s[i] - arr[1] + pre_s[N] - pre_s[i-1] - arr[N])

print(res)
