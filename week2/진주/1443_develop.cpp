#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int D, P;
ll ret = -1;

void dfs(int cnt, int start, long long num) {
    // 계산된 숫자의 자릿수가 D를 초과할 경우 바로 종료
    if (to_string(num).length() > D) {
        return;
    }

    // 연산 횟수를 다 사용한 경우 최댓값 갱신
    if (cnt == P) {
        ret = max(ret, num);
        return;
    }

    // 제일 큰 숫자를 얻는 것이기 때문에 큰 숫자부터 반복문 시작
    for (int i = start; i >= 2; i--) {
        dfs(cnt + 1, i, num * i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> D >> P;
    dfs(0, 9, 1); // 곱할 수 있는 제일 큰 숫자인 9부터 시작
    cout << ret;
    return 0;
}
