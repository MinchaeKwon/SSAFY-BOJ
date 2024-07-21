// 가능한 홀수를 보는 최대 횟수와 최소 횟수에 대해 각각 재귀를 하면 된다. 깊이가 얼마 안 되기에 dp가 따로 필요없다.
// 문제에 주어진 대로 케이스를 나누어 생각하자.
// 답은 int 범위를 넘을 수도 있을듯
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// (현재 숫자, 최대(1) 최소(0) 여부)에 대해 재귀적으로 구한다.
int query(int n, bool mxmn) {
    // 우선 현재 숫자의 모든 자릿수를 순회하며 홀수를 센다.
    int cnt = 0, k = n;
    while (k) cnt += k & 1, k /= 10;
    // 3자리 수라면 다음과 같이 3개로 나눌 수 있는 모든 경우의 수에 대해 고려해 재귀하며 최대/최소를 찾는다.
    if (n > 99) {
        int ret = !mxmn ? 1e9 : 0;
        for (ll i = 100; i <= n; i *= 10) {
            int x = n / i, r = n % i;
            for (ll j = 10; j < i; j *= 10) {
                int y = r / j, z = r % j;
                if (!mxmn) {
                    ret = min(ret, query(x + y + z, 0) + cnt);
                }
                else {
                    ret = max(ret, query(x + y + z, 1) + cnt);
                }
            }
        }
        return ret;
    }
    // 1자리 수나 2자리 수라면 문제 조건에 의해 단 하나의 경우만 고려하면 된다.
    else if (n > 9) {
        return query(n / 10 + n % 10, 0) + cnt;
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    cout << query(N, 0) << " " << query(N, 1);
}