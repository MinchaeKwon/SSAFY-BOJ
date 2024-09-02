// 전형적인 패러메트릭 서치 문제이다.
// 주어진 조건에 의하면, 가능한 점수 후보를 선형으로 놓고 봤을 때, 특정 점수 이전까진 가능하다가, 그 이후 불가능해진다는 치역의 특성이 있다.
// 이를 이용해 치역의 값이 true 가 되는 마지막 지점을 이분 탐색으로 구한다.
#include <bits/stdc++.h>
using namespace std;
// 확인하기 위한 함수이다. 점수 n 이상인 k 개의 덩어리를 벡터 v로부터 만들어 낼 수 있다면 true, 아니면 false.
bool chk(int n, int k, const vector<int> &v) {
    int i = 0, tmp = 0, cnt = 0;
    // 문제 조건에 따라서, 연속된 시험지들의 합이 n을 넘어서는 순간 하나의 덩어리로 본다.
    while (i < v.size()) {
        tmp += v[i];
        if (tmp >= n) {
            tmp = 0;
            if (++cnt >= k) return 1;
        }
        i++;
    }

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    vector<int> X(N);
    for (int &i : X) cin >> i;
    // 패러메트릭 서치
    int l = 0, r = 20 * N;
    while (l < r) {
        int m = l + r + 1 >> 1;
        if (chk(m, K, X)) l = m;
        else r = m - 1;
    }

    cout << l;
}