// 기본적으로는 백트래킹으로 푼다
// 시간 절약을 위해 가능한 모든 부분 문자열을 set에 저장해두고 백트래킹에서 가지치기를 한다
// 부분 문자열을 저장할 때는 pair<현재 숫자, 다음 자릿수>로 저장한다
#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> substrings;

// 백트래킹 (현재 숫자, 타겟 숫자, 다음 자릿수)
int solve(int cur, int tg, int nxt_lmul) {
    // 타겟 숫자에 도달하면 1을 반환
    if (cur == tg) {
        return 1;
    }
    // 그렇지 않다면 가능한 경우 합산
    int ret = 0;
    for (int i = 0; i < 10; i++) {
        // 오른쪽 왼쪽에 숫자를 추가하는 경우를 나누어 생각한다
        int rnxt = cur * 10 + i;
        if (substrings.count({rnxt, nxt_lmul * 10})) {
            ret += solve(rnxt, tg, nxt_lmul * 10);
        }
        // 오른쪽 왼쪽에 추가하는 경우가 같다면 진행하지 않는다
        int lnxt = cur + i * nxt_lmul;
        if (rnxt != lnxt && substrings.count({lnxt, nxt_lmul * 10})) {
            ret += solve(lnxt, tg, nxt_lmul * 10);
        }
    }
    return ret;
}

int main() {
    int N;
    cin >> N;

    for (int d = 1; d <= N; d *= 10) {
        int tmp = N;
        while (tmp >= d * 10) {
            substrings.insert({tmp % (d * 10), d * 10});
            tmp /= 10;
        }
        substrings.insert({tmp, d * 10});
    }

    int ans = solve(0, N, 1);
    cout << ans << '\n';
}