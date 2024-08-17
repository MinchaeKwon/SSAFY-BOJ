// 실질적으로 결과 문자열을 보면서 원본 문자열의 길이까지 역연산을 해 나갈 때, 끝의 문자가 A인지 B인지에 따라서 가능한 연산이 한정된다.
// 따라서 경우에 맞게 역연산해 가면서 길이가 같아졌을 때 일치하는가를 확인한다.
#include <bits/stdc++.h>
using namespace std;

string S, T;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> S >> T;
    // 길이가 같아질 때까지 역연산
    while (T.length() > S.length()) {
        char tmp = T.back();
        T.pop_back();
        if (tmp =='B') reverse(T.begin(), T.end());
    }
    
    cout << (S == T ? 1 : 0);
}