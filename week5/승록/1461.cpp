// 부호가 반대면 무조건 0을 지나치기 때문에, 음수인 경우와 양수인 경우로 나누어 관리한다.
// 제일 멀리 나가야 할 때를 제일 마지막에 배치하고, 나머지의 경우 멀리서부터 돌아오는 기준으로 더해가면 된다.
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    // 양수인 경우와 음수인 경우 나누어 저장 후 정렳
    // 나눈 집합에서 절댓값이 가장 큰(가장 멀리 나가야 하는) 경우를 포함하는 집합을 v[1]에 배치
    vector<int> v[2];
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x < 0) v[1].push_back(-x);
        else v[0].push_back(x);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    if (v[1].empty() || (!v[0].empty() && v[0].back() > v[1].back())) swap(v[0], v[1]);
    // v[1]의 첫번째 연산을 하는 경우는 돌아가지 않음을 반영
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        int f = 1;
        while (!v[i].empty()) {
            int cur = v[i].back();
            for (int j = 0; j < M && !v[i].empty(); j++) v[i].pop_back();
            ans += cur;
            if (!f || !i) ans +=cur;
            f = 0;            
        }
    }

    cout << ans;
}