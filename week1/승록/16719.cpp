// 제한이 작기 때문에, 해당 상태에서 문자 1개를 소거해서 만들 수 있는 상태 모두를 만든 다음 정렬해서 확인해도 된다.
// 길이가 1이 될 때까지 재귀 호출하며 반복하자.
#include <bits/stdc++.h>
using namespace std;

void solve(string S) {
    // 길이가 1에 도달했다면 해당 문자열만 출력하고 종료
    if (S.length() == 1) {
        cout << S << '\n';
        return;
    }
    // 가능한 모든 문자열들을 만들고 정렬
    vector<string> v;
    for (int i = 0; i < S.length(); i++) {
       v.push_back(S.substr(0, i) + S.substr(i + 1));
    렬
    sort(v.begin(), v.end());
    // 사전순 맨 위의 것으로 재귀 호출 후 끝나면 현재 상태를 출력
    solve(v[0]);
    cout << S << '\n';
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string S;
    cin >> S;
    solve(S);
}