
// 메모리 제한에 신경써서, 현재 지점에서 목표 지점까지 남은 횟수보다 pq의 사이즈가 더 크면 작은 값 말고는 넣지 말자.
// 그 외는 일반적인 pq 문제와 동일. visited 배열은 set으로 관리한다.
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K, mx, primes[100];
    cin >> K >> N;
    // 입력으로 들어오는 모든 소수에 대해 최댓값을 확인하고 방문처리 한다.
    unordered_set<int> vis;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int k = 0; k < K; k++) {
        cin >> primes[k];
        mx = max(mx, primes[k]);
        vis.insert(primes[k]);
        pq.push(primes[k]);
    }

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        // 목표에 도달하면 출력하고 종료
        if (!--N) {
            cout << cur;
            return 0;
        }
        // 아닌 경우 방문하지 않은 수의 경우 pq에 삽입. 이 때 문제 조건에 따라 2^31을 넘는 수는 예외처리.
        for (int k = 0; k < K; k++) {
            int nxt = (1LL * primes[k] * cur < (1LL << 31) ? primes[k] * cur : 0);
            if (nxt && !vis.count(nxt) && (nxt < mx || N > pq.size())) {
                mx = max(mx, nxt);
                vis.insert(nxt);
                pq.push(nxt);
            } 
        }
    }

    cout << -1;
}