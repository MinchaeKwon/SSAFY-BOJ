// 첫 날 떡의 개수를 a, 둘째 날 떡의 개수를 b라고 하면 세 번 째 날부터 각각 fibo[D - 3] * a + fibo[D - 2] * b개의 떡을 주게 된다.
// D까지의 피보나치 수열을 구한 뒤, a와 b를 구해주면 된다. 
#include <bits/stdc++.h>
using namespace std;

int D, K;
int fibo[40];

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> D >> K;
    // 피보나치 수열 구하기
    fibo[0] = 1;
    fibo[1] = 1;
    for(int i = 2; i < D; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    // a와 b를 역산. a <= b이므로 a를 먼저 구해주면 된다.
    int a = fibo[D - 3], b = fibo[D - 2];
    for (int i = 1; i < K; i++) {
        if ((K - a * i) % b == 0 && (K - a * i) / b >= i) {
            cout << i << '\n' << (K - a * i) / b;
            return 0;
        }
    }
}