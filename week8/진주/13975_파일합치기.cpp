#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int T;

ll add(priority_queue<ll, vector<ll>, greater<ll>>&PQ) {
    ll tmp1, tmp2, ret = 0;

    while (PQ.size() > 1) {
        tmp1 = PQ.top();
        PQ.pop();

        tmp2 = PQ.top();
        PQ.pop();

        ret += tmp1 + tmp2;
        PQ.push(tmp1 + tmp2);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> T;

    while (T--) {
        priority_queue<ll, vector<ll>, greater<ll>> PQ;
        int K, tmp;

        cin >> K;
        for (int i = 0; i < K; i++) {
            cin >> tmp;
            PQ.push(tmp);
        }
        cout << add(PQ) << '\n';
    }
    return 0;
}
