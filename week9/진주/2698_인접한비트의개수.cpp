#include <iostream>
#include <cstring>
using namespace std;

int T;
int N, K;
int dp[102][101][2];

int cnt(int n, int k, int val) {
    if(k < 0) return 0;

    if(n == 2) {
        if(val == 1) {
            if(k < 2) return 1;
        }
        else {
            if(k == 0) return 2;
        }
        return 0;
    }

    int& ret = dp[n][k][val];
    if(ret != -1) return ret;

    ret = 0;
    if(val == 0) ret += cnt(n-1, k, 1) + cnt(n-1, k, 0);
    else ret += cnt(n-1, k-1, 1) + cnt(n-1, k, 0);
    return ret;
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> K;
        memset(dp, -1, sizeof(dp));

        //N+1이므로 dp 배열 크기 주의
        cout << cnt(N+1, K, 0) << "\n";
    }
    return 0;
}
