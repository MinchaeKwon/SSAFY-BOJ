// 15559 내 선물을 받아줘
// 각 정점에 쓰인 이동 방향을 이용해 Union-Find하면 정점 집합들을 만들 수 있다.
// 이렇게 만들어진 정점 집합의 수가 곧 최소로 선물을 놓아야 하는 개수이다.
#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> dx = {{'N', -1}, {'S', 1}, {'W', 0}, {'E', 0}}, dy = {{'N', 0}, {'S', 0}, {'W', -1}, {'E', 1}};

int fp(int n, vector<int> &p) {
    return p[n] == n ? n : p[n] = fp(p[n], p);
}

int unite(int a, int b, vector<int> &p) {
    int pa = fp(a, p), pb = fp(b, p);
    if (pa == pb) return 0;
    p[pb] = pa;
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (auto &s : S) cin >> s;

    int ans = N * M;
    vector<int> p(N * M);
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int nx = i + dx[S[i][j]], ny = j + dy[S[i][j]];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            ans -= unite(i * M + j, nx * M + ny, p);
        }
    }

    cout << ans << '\n';
}