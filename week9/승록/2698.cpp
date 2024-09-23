// dp[n][k][b] = n 개까지의 비트를 봤을 때 인접한 비트가 k 개이고, 끝이 b 인 경우
// b = 1 일 때, dp[n][k][b] = dp[n - 1][k][0] + dp[n - 1][k - 1][1],
// b = 0 일 때, dp[n][k][b] = dp[n - 1][k][0] + dp[n - 1][k][1] 로 점화식이 나온다.
#include <bits/stdc++.h>
using namespace std;

int dp[102][101][2];

int query(int n, int k, int b) {
    int &ret = dp[n][k][b];
    if (ret != -1) return ret;
    if (n == 1) return ret = (k == 0);
    if (b) return ret = query(n - 1, k, 0) + query(n - 1, k - 1, 1);
    return ret = query(n - 1, k, 0) + query(n - 1, k, 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    memset(dp, -1, sizeof(dp));
    while (T--) {
        int n, k;
        cin >> n >> k;
        cout << query(n + 1, k, 0) << '\n';
    }
}
