// 고도가 낮아지는 순간 건물 하나 단위가 확정된다. 
// 현재 보는 지점의 높이보다 더 크면 pop 해줘서 스택을 단조롭게 관리한다.
// 만약 삽입할 지점의 top과 삽입할 원소의 높이가 동일하다면 삽입하지 않는다.
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<pii> v(N);
    for (pii &i : v) cin >> i.first >> i.second;
    sort(v.begin(), v.end());
    v.emplace_back(998244353, 0);

    int ans = 0;
    stack<int> st;
    for (pii &i : v) {
        while (!st.empty() && st.top() > i.second) {
            ans++;
            st.pop();
        }
        if (st.empty() || st.top() < i.second) st.push(i.second);
    }

    cout << ans;
}