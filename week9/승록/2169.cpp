// 아래쪽으로는 단방향, 오른쪽 또는 왼쪽으로 갈 때는 최초에 방향이 선택 가능하다.
// 음수를 다뤄야 하기에 min 값을 충분히 작은 수로 설정하자.
#include <bits/stdc++.h>
using namespace std;

int N, M, arr[1002][1002], dp[1002][1002][3];

int query(int n, int m, int k) {
    int &ret = dp[n][m][k];
    if (ret > -2e9) return ret;
    if (n > N || m > M || m < 1) return ret = -1e9 - 7;
    // 아래로 가는 경우
    if (n == N && m == M) return ret = arr[n][m];
    ret = max(ret, arr[n][m] + query(n + 1, m, 0));
    // 왼쪽으로 가는 경우
    if (k != 2) ret = max(ret, arr[n][m] + query(n, m - 1, 1));
    // 오른쪽으로 가는 경우
    if (k != 1) ret = max(ret, arr[n][m] + query(n, m + 1, 2));
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    // 모든 바이트가 128로 세팅되어서 int로는 -2e9 미만의 값이 나온다.
    memset(dp, 128, sizeof(dp));
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) cin >> arr[i][j];
    cout << query(1, 1, 0);
}
