#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
int N;

int main(void) {
    cin.tie(0) -> ios_base::sync_with_stdio(false);

    cin >> N;
    vector<int> wage(N);
    for(int i=0; i<N; ++i) {
        cin >> wage[i];
    }

    ll ret = 0;
    stack<int> st;

    for (int i = 0; i < N; ++i) {
        // 스택의 top에 있는 임금보다 현재 임금이 작을 때, 스택에서 pop하여 구간 계산
        while (!st.empty() && wage[st.top()] > wage[i]) {
            int tmp = wage[st.top()];
            st.pop();

            // 구간의 넓이를 계산 (인덱스 차이)
            int width = st.empty() ? i : (i - st.top() - 1);
            ret = max(ret, (ll)tmp * width);  // 최대 수익 갱신
        }
        st.push(i);
    }

    // 남은 스택 처리
    while (!st.empty()) {
        int tmp = wage[st.top()];
        st.pop();

        int width = st.empty() ? N : (N - st.top() - 1);
        ret = max(ret, (ll)tmp * width);
    }
    cout << ret << "\n";
    return 0;
}
