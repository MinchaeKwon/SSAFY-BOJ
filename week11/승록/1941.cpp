// 1941 소문난 칠공주
// 모든 경우의 수라고 해봐야 2^25, 약 3천만개이다.
// 비트마스킹과 브루트포스로 풀린다.
#include <bits/stdc++.h>
using namespace std;
// 인접한 정점을 탐색하는 데 Union-Find를 썼다.
int fp(int n, vector<int> &p) {
    return n == p[n] ? n : p[n] = fp(p[n], p);
}

int unite(int a, int b, vector<int> &p) {
    int pa = fp(a, p), pb = fp(b, p);
    if (pa == pb) return 0;
    p[pb] = pa;
    return 1;
}

int main() {
    string seat[5];
    int mask = 0;
    for (int i = 0; i < 5; i++) {
        cin >> seat[i];
        for (int j = 0; j < 5; j++) mask |= (seat[i][j] == 'S') << i * 5 + j;
    }

    int ans = 0;
    vector<int> p(25);
    // 비트마스킹 순회
    for (int m = 0; m < (1 << 25); m++) {
        // 팝카운트가 7이 아니거나, 이다솜파가 4명 미만이라면 건너뛴다.
        if (__builtin_popcount(m) != 7 || __builtin_popcount(m & mask) < 4) continue;
        // 모두 인접하다면 Union-Find를 한 집합 수가 1이다. 판별해서 더해주자.
        int cnt = 7;
        iota(p.begin(), p.end(), 0);
        for (int i = 0; i < 25; i++) {
            for (int j = i + 1; j < 25; j++) {
                if (!(m & (1 << i)) || !(m & (1 << j))) continue;

                int ix = i / 5, iy = i % 5, jx = j / 5, jy = j % 5;
                if ((abs(ix - jx) + abs(iy - jy)) == 1) cnt -= unite(i, j, p);
            }
        }

        ans += (cnt == 1);
    }

    cout << ans << '\n';
}