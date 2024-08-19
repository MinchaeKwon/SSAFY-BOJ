import sys
input = sys.stdin.readline
S = list(input().rstrip())
T = list(input().rstrip())

#행동이 크게 두 가지로 나뉘는데 뒤에서부터 처리해주면서 원래의 S를 만들 수 있는지 확인한다.
def check(T):
    while len(S) != len(T):
        if T[-1] == 'A':
            T.pop()
        elif T[-1] == 'B':
            T.pop()
            T = T[::-1]
    if S == T:
        return 1
    else:
        return 0
print(check(T))
