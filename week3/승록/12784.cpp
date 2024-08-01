#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int T, dp[1001];
vector<vector<pii>> adj;

int query(int u, int p) {
    // Tree DP
    // 값이 있다면 리턴
    if (dp[u] != -1) return dp[u];
    // 리프 노드이면 1e9 리턴
    if (u != 1 && adj[u].size() == 1) return dp[u] = 1e9;
    // 리프 노드가 아니면 자식 노드로 가는 간선을 끊는 비용과, 자식 노드에서 리프 노드로 가는 간선을 끊는 비용 중 작은 값을 모두 더해 리턴
    dp[u] = 0;
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        dp[u] += min(w, query(v, u));
    }
    return dp[u];
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // 입력 받고 각 테스트 케이스마다 처리한다.
    // 양방향 간선이므로 연결 리스트
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        memset(dp, -1, sizeof(dp));
        adj.assign(N + 1, {});
        for (int i = 0; i < M; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        // 최초의 노드를 1로 설정하고 Tree DP
        cout << query(1, -1) << '\n';
    }
}