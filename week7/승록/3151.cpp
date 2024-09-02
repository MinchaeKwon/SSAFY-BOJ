// N^2 만큼의 가능한 합들에 대해, 해당 합을 0 으로 만들 수 있는 원소가 몇 개나 있는지를 이분 탐색으로 구한다.
// 숫자 범위 상 답은 long long 범위가 될 수 있으니 주의
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &i : A) cin >> i;
    sort(A.begin(), A.end());
    // 이분 탐색을 통해 가능한 쌍에 대해 0으로 만드는 원소의 개수를 구해준다.
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int tg = -A[i] - A[j];
            int cnt = upper_bound(A.begin(), A.end(), tg) - lower_bound(A.begin(), A.end(), tg) - (A[i] == tg) - (A[j] == tg);
            ans += cnt;
        }
    }
    // 해당 과정을 거치면 순회 과정으로부터 3번 중복이 있게 되므로 3으로 나눠준다.
    cout << ans / 3;
}