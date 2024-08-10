// 양 끝을 제외하고 임의의 위치를 골라보자.
// 최대한으로 벌꿀을 따는 경우는 그 지점과 한 쪽 끝에 벌을 배치하고 반대쪽 끝에 꿀통을 배치하거나, 그 지점에 꿀통을 배치하고 양 끝에 벌을 배치하는 경우다.
// 누적 합을 이용해 전처리 후 선형으로 계산가능
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N
    // 누적 합 생성
    vector<ll> v(N + 1);
    for (int i = 1; i <= N; i++) cin >>v[i], v[i] += v[i - 1];
    // 양 끝 제외 모든 칸에 대해 가능성 탐색
    ll ans = 0;
    for(int i = 2; i < N; i++) {
        ans = max(ans, v[N - 1] - v[i - 1] + v[i] - v[1]);
        ans = max(ans, v[N] - v[1] + v[N] - v[i] + v[i - 1] - v[i]);
        ans = max(ans, v[N - 1] + v[i - 1] + v[i - 1] - v[i]);
    }
    cout << ans;
}