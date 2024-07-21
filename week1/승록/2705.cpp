// 1차원 dp로 풀 수 있는 대표적인 문제다.
// 기본적으로 dp[0] = dp[1] = 1
// i >= 2 일 때, dp[i] = (dp[0] ~ dp[n / 2]의 합) 으로 나타낼 수 있다.
// 답은 int 범위를 넘을 수도  있을듯
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T, N;
ll dp[1001];

ll query(int n) {
    ll &ret = dp[n];
    if (ret) return ret;
    if (n < 2) return ret = 1;
    // 가능한 모든 경우를 순회하며 개수를 더한다.
    // 이 경우, n = i + x + i 가 되도록 팰린드롬 파티션을 구성하는 경우의 개수를 모두 더하는 것이다.
    for (int i = 0; i * 2 <= n; i++) {
        ret += query(i);
    }
    return ret;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> T;
    while(T--) {
        cin >> N;
        cout << query(N) << '\n';
    }
}