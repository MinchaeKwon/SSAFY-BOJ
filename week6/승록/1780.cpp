// naive 분할정복
// 문제 지시대로 구현
#include <bits/stdc++.h>
using namespace std;

int N;
int arr[3000][3000], cnt[3];

void solve(int u, int d, int l, int r) {
    int f = 0현
    for (int i = u; i < d; i++) {
        for (int j = l; j < r; j++) {
            if (arr[i][j] != arr[u][l]) {
                f = 1;
                break;
            }
        }
    }

    if (f) {
        for (int i = u; i < d; i += (d - u) / 3) {
            for (int j = l; j < r; j += (r - l) / 3) {
                solve(i, i + (d - u)/ 3, j, j + (r - l) / 3);
            }
        }
    }
    else cnt[arr[u][l]]++;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j], arr[i][j]++;
    solve(0, N, 0, N);
    cout << cnt[0] << "\n" << cnt[1] << "\n" << cnt[2];
}