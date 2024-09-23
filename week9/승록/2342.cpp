// dp[n][lf][rf] = n 번쨰 지시에서 왼발이 lf, 오른발이 rf 에 있을 때 최소의 힘
// dp로 탐색이 가능하다.
#include <bits/stdc++.h>
using namespace std;

int N, dp[100001][5][5];
vector<int> v;
// from 에서 to로 발을 옮기는데 필요한 힘을 반환
int get_power(int from, int to) {
    if (!from) return 2;
    if (from == to) return 1;
    if (abs(from - to) == 2) return 4;
    return 3;
}

int query(int n, int lf, int rf) {
    int &res = dp[n][lf][rf];
    if (res < 1e9) return res;
    if (n == N) return 0;
    // 오른발을 움직이는 경우 왼발은 해당 지시와 다른 위치에 있어야 한다.
    if (v[n] != lf) res = min(res, query(n + 1, lf, v[n]) + get_power(rf, v[n]));
    // 왼발을 움직이는 경우 오른발은 해당 지시와 다른 위치에 있어야 한다.
    if (v[n] != rf) res = min(res, query(n + 1, v[n], rf) + get_power(lf, v[n]));
    return res;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    while (1) {
        cin >> N;
        if (!N) break;
        v.push_back(N);
    }
    N = v.size();
    memset(dp, 63, sizeof(dp));
    cout << query(0, 0, 0);
}
