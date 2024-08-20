// 어떤 방에 풍선을 갖다주는 과정에서, 거리가 더 짧은 쪽에 갖다주게 되면 abs(A방 거리 - B방 거리) 만큼의 총 거리의 이득을 본다.
// 볼 수 있는 이득의 크기를 기준으로 정렬한 뒤에 가능한 배치를 시도한다.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, A, B;
    while (1) {
        cin >> N >> A >> B;
        if (N == 0 && A == 0 && B ==0) break;
        // 이득의 크기 기준 정렬
        vector<vector<int>> v(N);
        for (auto &r : v) r.resize(3), cin >> r[0] >> r[1] >> r[2];
        sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> & b) {
            return abs(a[1] - a[2]) > abs(b[1] - b[2]);
        });
        // 해당하는 양 만큼의 풍선 개수를 빼주는 함수
        auto sub_balloons = [&](int &bln, int &cnt, int dist) {
            int amt = min(bln, cnt);
            bln -= amt;
            cnt -= amt;

            return 1LL * amt * dist;
        };
        // 정렬된 배열을 보면서 가능한 경우 이득을 취해준다
        ll ans = 0;
        for (auto &r : v) {
            if (r[2] > r[1]) {
                if (A > 0) ans += sub_balloons(A, r[0], r[1]);
                if (r[0] > 0) ans += sub_balloons(B, r[0], r[2]);
            }
            else {
                if (B > 0) ans += sub_balloons(B, r[0], r[2]);
                if (r[0] > 0) ans += sub_balloons(A, r[0], r[1]);
            }
        }

        cout << ans << "\n";
    }
}