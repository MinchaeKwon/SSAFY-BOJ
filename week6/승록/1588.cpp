// solve(n, k) = n 번째 수열에서 k 까지의 각각의 합과 현재 문자를 반환
// solve(n, k)는 solve(n - 1, (k - 1) / 3 + 1) 의 값으로부터 분할 정복하여 구할 수 있다.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t, N;
ll l, r;
int nxtnxt[3][3] = {{1, 3, 2}, {2, 1, 1}, {2, 3, 2}};

vector<int> solve(int n, ll k) {
    if (k == 0) return {0, 0, 0, 0};
    if (n == 0 && k == 1) {
        vector<int> ret = {0, 0, 0, t};
        ret[t - 1] = 1;
        return ret;
    }
    auto prv = solve(n - 1, (k - 1) / 3 + 1);
    vector<int> nxt = {prv[0] + prv[1] * 2, prv[0] + prv[1] + prv[2] * 2, prv[0] + prv[2], nxtnxt[prv[3] - 1][(k - 1) % 3]};
    for (int i = 2; i > (k - 1) % 3; i--) nxt[nxtnxt[prv[3] - 1][i] - 1]--;
    return nxt;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> t >> l >> r >> N;
    auto rr = solve(N, r + 1), ll = solve(N, l);
    cout << rr[0] - ll[0] << " " << rr[1] - ll[1] << " " << rr[2] - ll[2];
}