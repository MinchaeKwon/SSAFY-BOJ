#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

int T, N;
int dp[1001];

int dfs(int N) {
	int &ret = dp[N];
	if (ret != -1) return ret;

	ret = 0; //ret 초기화
	for (int i = 0; i < N; i++) {
		if ((N - i) / 2 * 2 + i == N) ret += dfs((N - i) / 2);
	}

	return ++ret; //자기 자신도 추가
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> T;

	memset(dp, -1, sizeof(dp));
	dp[0] = 0; 
	dp[1] = 1; 
	dp[2] = 2;
	dp[3] = 2;

	for (int t = 0; t < T; t++) {
		cin >> N;
		cout << dfs(N) << "\n";
	}

}
