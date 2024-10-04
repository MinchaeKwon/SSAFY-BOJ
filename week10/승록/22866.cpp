// 양 방향으로 단조 스택을 이용해 보이는 건물의 개수를 구할 수 있다.
// 양쪽에서 보이는 수를 전부 합하자. 그리고 문제 조건에 맞게 가장 가까운 건물도 구한다.
// O(N)이면 충분하다.
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    int N, arr[100000]; cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    stack<pii> st;
    int cnt[100000], idx[100000], dist[100000];
    memset(cnt, 0, sizeof(cnt));
    memset(dist, 63, sizeof(dist));
     
    for (int i = 0; i < N; i++) {
        while (!st.empty() && st.top().first <= arr[i]) st.pop();
        cnt[i] += st.size();
        if (!st.empty()) idx[i] = st.top().second, dist[i] = i - idx[i];
        st.emplace(arr[i], i);
    }
    
    while (!st.empty()) st.pop();
    for (int i = N - 1; i >= 0; i--) {
        while (!st.empty() && st.top().first <= arr[i]) st.pop();
        cnt[i] += st.size();
        if (!st.empty() && st.top().second - i < dist[i]) idx[i] = st.top().second;
        st.emplace(arr[i], i);
    }

    for (int i = 0; i < N; i++) {
        cout << cnt[i];
        if (cnt[i]) cout << ' ' << idx[i] + 1;
        cout << '\n';
    }
}