// 스택을 이용하면 각각의 정점의 끝에 방문할 때, 시작하는 문자열 상의 위치가 어디었는지 알 수 있다.
// 정점 끝에 다다랐을 때, 주어진 트리 구조 특성 상 제일 먼저 X, Y를 포함하는 구간이 정답이다.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X, Y, x = 0, y = 0;
    string S;
    cin >> N >> S >> X >> Y;

    stack<int> st;
    for (int i = 0; i < 2 * N; i++) {
        int ii = i + 1;
        if (S[i] == '0') {
            st.push(ii);
            if (X == ii) x = ii;
            if (Y == ii) y = ii;
        }
        else {
            int t = st.top();
            st.pop();
            if (X == ii) x = t;
            if (Y == ii) y = t;
            
            if (x >= t && y >= t && x <= ii && y <= ii) {
                cout << t << ' ' << ii << '\n';
                return 0;
            }
        }
    }
}