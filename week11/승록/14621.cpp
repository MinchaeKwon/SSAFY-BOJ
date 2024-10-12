// 14621 나만 안되는 연애
// 간단한 Union-Find 문제다.
// 서로 다른 성별인 경우에만 간선을 추가하고 크루스칼 알고리즘으로 처리하자.
#include <bits/stdc++.h>
using namespace std;

int fp(int n, vector<int> &p) {
    if (p[n] == n) return n;
    return p[n] = fp(p[n], p);
}

int unite(int a, int b, vector<int> &p) {
    int pa = fp(a, p), pb = fp(b, p);
    if (pa == pb) return 0;
    p[pb] = pa;
    return 1;
}

int main() {
    int N, M; cin >> N >> M;
    string s(N, ' ');
    for (char &c : s) cin >> c;
    vector<int> p(N);
    iota(p.begin(), p.end(), 0);
    vector<tuple<int, int, int>> v;
    while (M--) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        if (s[a] != s[b]) v.emplace_back(w, a, b);
    }
    
    int cnt = N - 1, ans = 0;
    sort(v.begin(), v.end());
    for (auto &[w, a, b] : v) {
        int res = unite(a, b, p);
        cnt -= res;
        ans += res * w;
    }

    cout << (cnt ? -1 : ans) << '\n';
}