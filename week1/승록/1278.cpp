// 가능한 최대 장면의 수는 가능한 모든 배우들의 등장 상태를 모두 실행하는 것으로, 2 ^ N - 1 이다.
// 여기 도달하기 위해서는 한명씩 들어가고 나가면서 비트마스킹을 이용해 방문한 상태들을 건너뛰어 주게 되면, 도달 가능한 모든 상태에 도달하게 된다.
// 이 구현에서 마지막으로 무대에 있게 되는 배우는 N 번째 배우이다.
#include <bits/stdc++.h>
using namespace std;

// N 이 최대 17 이므로, vis 배열은 2 ^ 17 로 생성한다.
int N, vis[1 << 17];
vector<int> ans;

// 재귀하면서 방문하지 않은 상태들로 계속 전이한다.
void solve(int mask) {
    for (int i = 0; i < N; i++) {
        int nxt = mask ^ (1 << i);
        if (vis[nxt]) continue;
        vis[nxt] = 1;
        ans.push_back(i);
        solve(nxt);
        return;
    }
}

int main() {
    cin >> N;
    // solve로 전체 상태를 순회하며 얻은 방문 순서를 출력
    vis[0] = 1력
    solve(0);
    cout << ans.size() << "\n";
    for (int i : ans) cout << i + 1 << "\n";
    cout << N;
}