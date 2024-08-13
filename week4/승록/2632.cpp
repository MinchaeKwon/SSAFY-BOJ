// 하나의 피자로부터 피자 조각을 사는 경우는 2배 길이로 늘린 뒤 누적 합을 이용하면 계산이 가능하다.
// 이 모든 경우를 전처리한 후 한쪽 컨테이너의 모든 값에 대해 반대쪽을 이분 탐색하면 합이 K가 되는 개수를 빠르게 찾을 수 있다.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int K, M, N;
    cin >> K >> M >> N;
    // 길이 2배의 누적 합으로 전처리
    vector<int> A(M + 1 << 1), B(N + 1 << 1);
    for (int i = 1; i <= M; i++) cin >> A[i], A[i + M] = A[i];
    for (int i = 1; i <= N; i++) cin >> B[i], B[i + N] = B[i];
    for (int i = 1; i <= M * 2; i++) A[i] += A[i - 1];
    for (int i = 1; i <= N * 2; i++) B[i] += B[i - 1];
    // 가능한 모든 경우 추출 후 
    vector<int> As = {0, A[M]}, Bs = {0, B[N]};
    for (int i = 0; i < M; i++) {
        for (int j = 1; j < M; j++) {
            As.push_back(A[i + j] - A[i]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            Bs.push_back(B[i + j] - B[i]);
        }
    }
    sort(As.begin(), As.end()); sort(Bs.begin(), Bs.end());
    // 이분 탐색으로 가능한 경우 수 합산
    ll ans = 0;
    for (int &i : As) {
        int tg = K - i;
        if (tg < 0) break;
        ans += upper_bound(Bs.begin(), Bs.end(), tg) - lower_bound(Bs.begin(), Bs.end(), tg);
    }
    cout << ans;
}