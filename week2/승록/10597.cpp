// 백트래킹을 이용해 가능한 경우를 탐색
// 최대 범위가 50까지이므로 비트마스킹으로 가능한 범위만 탐색하도록 할 수 있다
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// idx: 현재 탐색 위치, mask: 사용한 숫자 비트마스크
void solve(const string &S, vector<int> &ans, int idx, ll mask) {
    // 수열의 끝에 도달했을때 처리
    if (idx == S.length()) {
        // 현재 길이는 9 이상인 경우와 나머지 경우로 나누어 처리 후 모든 비트를 충족하면 출력 후 종료
        int len = S.length() > 9 ? (S.length() - 9) / 2 + 9 : S.length();
        if (mask == (1LL << len) - 1) {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << ' ';
            }
            exit(0);
        }
        return;
    }
    // 현재 위치에서 1자리 또는 2자리 숫자를 탐색
    // 범위를 벗어나지 않게 주의
    for (int i = 1; i <= 2 && idx + i <= S.length(); i++) {
        int num = stoi(S.substr(idx, i));
        if (num == 0 || num > 50) {
            continue;
        }
        if (mask & (1LL << num - 1)) {
            continue;
        }
        ans.push_back(num);
        solve(S, ans, idx + i, mask | (1LL << num - 1));
        ans.pop_back();
    }
}

int main() {
    string S;
    cin >> S;
    vector<int> ans;
    solve(S, ans, 0, 0);
}