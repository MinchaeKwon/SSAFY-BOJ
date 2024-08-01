// bottom-up 방식으로 dp를 채워나가며 가능한 무게들을 모두 체크해둔다.
// 그리고 입력받은 무게들이 dp에 있는지 확인한다.
// 중간에 음수인 값이 나오는 경우를 생각해 map으로 관리
// dp를 채우는 방식은 비트마스킹을 이용하여 구현
#include <bits/stdc++.h>
using namespace std;

map<int, int> dp;
vector<int> weights;

void dp_fill(int i, int w) {
    // dp[w]의 i번째 비트가 켜져있다면 i번째의 인덱스에서 w의 무게를 만들 수 있다.
    // i가 weights.size()보다 크거나 dp에 w가 있고 dp[w]에 i번째 비트가 켜져있으면 리턴
    if (i > weights.size() || (dp.count(w) && (dp[w] & (1 << i)))) {
        return ;
    }
    // dp[w]에 i번째 비트를 켜준다.
    dp[w] |= (1 << i);
    // i번째 무게를 더하거나 빼거나 그대로 둔다.
    dp_fill(i + 1, w - weights[i]);
    dp_fill(i + 1, w);
    dp_fill(i + 1, w + weights[i]);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // 입력 받고 dp를 채운다.
    int N, M;
    cin >> N;
    weights.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }
    dp_fill(0, 0);
    // 입력 받고 dp에 있는지 확인해 출력한다.
    cin >> M;
    for (int i = 0; i < M; i++) {
        int w;
        cin >> w;
        cout << (dp.count(w) ? "Y" : "N") << ' ';
    }
}