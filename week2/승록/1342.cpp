// 범위가 10! = 약 360만이므로 완전탐색으로 해결 가능
// next_permutation을 이용하여 모든 순열을 구한 뒤, 인접 문자가 중복되는지 확인
#include <bits/stdc++.h>
using namespace std;

string S;

int main() {
    cin >> S;
    sort(S.begin(), S.end());
    int cnt = 0;
    do {
        int f = 1;
        for (int i = 0; i < S.size() - 1; i++) {
            if (S[i] == S[i + 1]) {
                f = 0;
                break;
            }
        }
        cnt += f;
    } while (next_permutation(S.begin(), S.end()));
    
    cout << cnt;
}