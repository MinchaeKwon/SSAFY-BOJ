// 구해야 하는 값의 특징을 생각해보면, 어느 시점까지는 가능하다 그 이후 불가능하다.
// 즉 패러메트릭 서치를 이용해 쉽게 구할 수 있으며, 평가 함수에 SPFA를 사용한다.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 평가 함수. 다익스트라 대신 SPFA를 사용했다.
// 시작점 A로부터 도착점 B까지, C원 이하로 가는 경로 중 최대로 지불하는 통행료가 m원 이하로 가능한지의 여부이다.
bool chk(int m, ll a, ll b, ll c, const vector<vector<pair<int, int>>> &vv) {
    vector<bool> inq(vv.size());
    vector<ll> d(vv.size(), 1e18);
    queue<int> q;
    q.push(a);
    d[a] = 0;
    inq[a] = 1;

    while (!q.empty()) {
        int u = q.front();
        inq[u] = 0;
        q.pop();

        if (u == b) return 1;

        for (auto &[v, w] : vv[u]) {
            if (w > m) continue;
            ll nxt = d[u] + w;
            if (nxt <= c && nxt < d[v]) {
                d[v] = nxt;
                if (!inq[v]) q.push(v), inq[v] = 1;
            }
        }
    }

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll N, M, A, B, C;
    cin >> N >> M >> A >> B >> C;
    vector<vector<pair<int, int>>> vv(N + 1);
    while (M--) {
        int a, b, w;
        cin >> a >> b >> w;
        vv[a].emplace_back(b, w);
        vv[b].emplace_back(a, w);
    }

    int l = 0, r = 1e9 + 1;
    while (l < r) {
        int m = l + r >> 1;
        if (chk(m, A, B, C, vv)) r = m;
        else l = m + 1;
    }

    cout << (l > 1e9 ? -1 : l) << '\n';
}