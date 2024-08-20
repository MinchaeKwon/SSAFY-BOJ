import sys
import heapq as hq
input = sys.stdin.readline

while True:
    N, A, B = map(int, input().split())
    if N == 0 and A == 0 and B == 0:
        break

    move = 0
    diff = []
    bl = []

    for i in range(N):
        K, DA, DB = map(int, input().split())
        hq.heappush(diff, (-abs(DA-DB), DA, DB, K))

    while diff:
        _, DA, DB, K = hq.heappop(diff)
        if DA > DB:  # A가 더 먼 경우
            if K <= B:
                move += DB * K
                B -= K
            else:
                move += DB * B + DA * (K - B)
                A -= (K - B)
                B = 0
        else:  # B가 더 먼 경우
            if K <= A:
                move += DA * K
                A -= K
            else:
                move += DA * A + DB * (K - A)
                B -= (K - A)
                A = 0

    print(move)
