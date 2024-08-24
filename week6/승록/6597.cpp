// s = preorder 순회, t = inorder 순회
// preorder 순회를 중심으로 inorder 와 대조하며 순서를 찾아가주면 된다.
#include <bits/stdc++.h>
using namespace std;

string s, t;

string dfs(int idx, int l, int r) {
    if (l >= r) return "";
    if (l + 1 == r) return string(1, s[idx]);
    int m = t.find(s[idx]);
    auto former = dfs(idx + 1, l, m);
    auto later = dfs(idx + m - l + 1, m + 1, r);
    return former + later + string(1, s[idx]);
}

int main() {

    cin.tie(0)->sync_with_stdio(0);
  	while (1) {
        cin >> s >> t;
        if (cin.eof()) break;
        cout << dfs(0, 0, s.length()) << "\n";
    }
}