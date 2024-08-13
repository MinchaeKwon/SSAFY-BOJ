// 여는 괄호는 언제 열려도 뒤에 문자열이 남아있다면 괜찮지만, 닫는 괄호는 나오는 순간에 짝이 맞지 않으면 바로 틀린다.
// 이를 이용해서 여는 괄호에 대해 +1, 닫는 괄호에 대해 -1 을 적용해보자.
// 누적 합이 음수가 되는 순간에, 그 앞선 위치에 있는 괄호들 중 하나는 반대였어야 한다. 
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string S;
    cin >> S;
    // 길이가 홀수면 가능성 자체가 없다.
    if (S.length() & 1) {
        cout << 0;
        return 0;
    }
    // 정방향, 역방향에 대해 검사
    vector<int> psum(S.length() + 1), psum_rev(S.length() + 1);
    for (int i = 0; i < S.length(); i++) {
        psum[i + 1] += psum[i] + (S[i] == '(' ? 1 : -1);
        if (psum[i + 1] < 0) {
            int ans = 0;
            while (i >= 0) ans += S[i] == ')', i--;
            cout << ans;
            return 0;
        }
    }
    reverse(S.begin(), S.end());
    for (int i = 0; i < S.length(); i++) {
        psum_rev[i + 1] += psum_rev[i] + (S[i] == ')' ? 1 : -1);
        if (psum_rev[i + 1] < 0) {
            int ans = 0;
            while (i >= 0) ans += S[i] == '(', i--;
            cout << ans;
            return 0;
        }
    }
    //오타는 최대 1개이지 1개가 반드시 존재하는 것은 아니므로 오타가 존재하지 않는다면 0을 출력
    cout << 0;
}