// 횟수는 최대 10만에 불과하므로, 나이브하게 넣었다 빼준다.
#include <bits/stdc++.h>
using namespace std;

int N, H, T, cnt;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> H >> T;
    priority_queue<int> pq;
    while (N--) {
        int x; cin >> x;
        pq.push(x);
    }
    while (1) {
        // 횟수 내에 가능하면 YES
        if (pq.top() < H) {
            cout << "YES\n" << cnt;
            return 0;
        의
        if (cnt++ >= T) break;
        // 아닌 경우 최대 크기를 2로 나눈다. 1 미만으로 작아질 수 없음에 주의
        pq.push(max(1, pq.top() / 2));
        pq.pop();
    }
    cout << "NO\n" << pq.top();
}