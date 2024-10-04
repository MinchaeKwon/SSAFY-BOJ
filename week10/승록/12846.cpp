// 스택으로 풀어도 되긴 하는데 세그먼트 트리를 적당히 써도 된다.
// 세그먼트 트리로 min 구간을 관리하며 이분 탐색으로 인덱스마다 해당 인덱스가 min값이 되는 최대 범위를 구한다.
// 구한 범위와 해당 인덱스의 값을 이용해 최대 이득을 계산할 수 있다.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, arr[100001], seg[400004];

void upd(int node, int s, int e, int idx, int val) {
    if (idx < s || idx > e) return;
    if (idx == s && idx == e) {
        seg[node] = val;
        return;
    }
    int m = s + e >> 1;
    upd(node << 1, s, m, idx, val); upd(node << 1 | 1, m + 1, e, idx, val);
    seg[node] = min(seg[node << 1], seg[node << 1 | 1]);
}

int min_query(int node, int s, int e, int l, int r) {
    if (e < l || s > r) return 1e9 + 7;
    if (l <= s && e <= r) return seg[node];
    int m = s + e >> 1;
    return min(min_query(node << 1, s, m, l, r), min_query(node << 1 | 1, m + 1, e, l, r));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(seg, 63, sizeof(seg));
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        upd(1, 1, N, i, arr[i]);
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        int cur = arr[i];

        int l = 1, r = i;
        while (l < r)  {
            int m = l + r >> 1;
            if (min_query(1, 1, N, m, i) == cur) r = m;
            else l = m + 1;
        }
        int s = l;

        l = i, r = N;
        while (l < r) {
            int m = l + r + 1 >> 1;
            if (min_query(1, 1, N, i, m) == cur) l = m;
            else r = m - 1;
        }
        int e = l;

        ans = max(ans, 1LL * cur * (e - s + 1));
    }

    cout << ans;
}