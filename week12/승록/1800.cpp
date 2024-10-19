// 조건을 잘 설정해서 다익스트라 또는 SPFA 한 번이면 충분하다.
// SPFA로 구현했다.
#include <bits/stdc++.h>
using namespace std;
// SPFA 부분
// N이 1,000 이하라는 점을 이용하자. 공짜 케이블이 k개 남아있을 때 노드 n에 있는 경우를 n + k * (n + 1)로 매핑이 가능하다.
// 대충 100만 정도니 여유롭게 2 ^ 21로 크기들을 설정했다.
int d[1 << 21], in_q[1 << 21];

int spfa(int n, int k, const vector<vector<pair<int, int>>> &vv) {
    memset(d, 63, sizeof(d));
    queue<int> q;
    d[1 + k * (n + 1)] = 0;
    in_q[1 + k * (n + 1)] = 1;
    q.push(1 + k * (n + 1));

    int ret = 1e9 + 7;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        in_q[cur] = 0;
        // 다른 정점으로 가는 경로에서, 공짜 찬스를 쓰는 경우를 생각해서 탐색한다.
        int u = cur % (n + 1), kk = cur / (n + 1);
        for (auto &[v, w] : vv[u]) {
            int dnxt = max(d[cur], w), nv = v + kk * (n + 1);
            if (dnxt < d[nv]) {
                if (v == n) ret = min(ret, dnxt);
                d[nv] = dnxt;
                if (!in_q[nv]) {
                    in_q[nv] = 1;
                    q.push(nv);
                }
            }

            if (kk > 0) {
                int nnv = v + (kk - 1) * (n + 1);
                if (d[cur] < d[nnv]) {
                    if (v == n) ret = min(ret, d[cur]);
                    d[nnv] = d[cur];
                    if (!in_q[nnv]) {
                        in_q[nnv] = 1;
                        q.push(nnv);
                    }
                }
            }
        }
    }

    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, P, K;
    cin >> N >> P >> K;
    vector<vector<pair<int, int>>> v(N + 1);
    while (P--) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].emplace_back(b, w);
        v[b].emplace_back(a, w);
    }

    int ans = spfa(N, K, v);
    cout << (ans > 1e9 ? -1 : ans) << '\n';
}