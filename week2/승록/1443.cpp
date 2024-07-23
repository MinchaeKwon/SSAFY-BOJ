// 백트래킹을 깎으면 될 거 같긴 한데 dp가 되는 것 같다
// dp[cur][rem] = cur에서 rem개의 숫자를 곱했을 때 나올 수 있는 가장 큰 수
// 만약 곱하다 lim을 넘어가면 -1을 리턴
#include <bits/stdc++.h>
using namespace std;

int lim;
map<pair<long long, int>, int> dp;

int solve(long long cur, int rem) {
    // dp 값이 있으면 그 값을 리턴하고, 위의 종료 조건에 맞게 구현
    if (dp.count({cur, rem})) return dp[{cur, rem}];
    if ((cur << rem) >= lim) return dp[{cur, rem}] = -1;
    if (rem == 0) return dp[{cur, rem}] = cur;
    // 최솟값은 -1로 하고, 2부터 9까지 곱해보면서 가장 큰 값을 리턴하도록 한다
    int ret = -1;
    for (int i = 2; i < 10; i++) {
        ret = max(ret, solve(cur * i, rem - 1));
    }

    return dp[{cur, rem}] = ret;
}

int main() {
    int D, P;
    cin >> D >> P;
    // D자리 수를 만들어야 하므로 10^D를 lim으로 설정
    lim = pow(10, D);
    cout << solve(1, P) << '\n';
}