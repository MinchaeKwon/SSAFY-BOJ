// 연료를 채울 주유소들을 미리 정하고 들어간다고 가정해보자.
// 이 때 어떻게든 해당 주유소들을 방문할 방법이 존재하므로, 그리디하게 현재 도달 가능한 주유소들을 보며 연료를 채워 나가자.
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
// 방문 체크
int vis[10000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, L, P;
    cin >> N;
    // 연료와 거리 순으로 정렬한다
    vector<pii> v(N);
    for (pii &i : v) cin >> i.first >> i.second;
    sort(v.begin(), v.end(), [](pii a, pii b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    });
    cin >> L >> P;
    // 갈 수 있는 거리가 L에 도달할 때까지, 연료 순으로 보면서 도달할 수 있는 거리라면 방문할 주유소로 치고 기름 양에 더한다.
    int ans = 0;
    while (P < L) {
        ans++;
        int i = 0;
        for (; i < N; i++) {
            if (vis[i]) continue;
            if (v[i].first <= P) break;
        }
        if (i >= N) break;

        P += v[i].second;
        vis[i] = 1;

        if (P >= L) {
            cout << ans;
            return 0;
        } 
    }

    if (P >= L) cout << 0;
    else cout << -1;
}