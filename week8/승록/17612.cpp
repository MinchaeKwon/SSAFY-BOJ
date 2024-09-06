// 어느 계산대로 안내할지를 pq로 관리해준다.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    priority_queue<pii> waiting;
    vector<tuple<int, int, int>> cashing;
    // 계산대들에 대해 미리 처리
    for (int k = 1; k <= K; k++) {
        waiting.emplace(0, -k);
    }

    for (int i = 0; i < N; i++) {
        int id, w;
        cin >> id >> w;
        // 계산대 pq에서 꺼내 다음 가능해지는 시간과 번호를 닷기 넣는다.
        int t = -waiting.top().first, no = waiting.top().second;
        int nt = t + w;
        waiting.pop();
        waiting.emplace(-nt, no);

        cashing.emplace_back(nt, no, id);
    }
    // 조건에 따라 먼저 계산하는 순서대로 정렬
    sort(cashing.begin(), cashing.end());
    ll ans = 0, ii = 0;
    for (auto &[t, no, id] : cashing) ans += ++ii * id;
    cout << ans;
}