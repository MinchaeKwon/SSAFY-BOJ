// 체스판을 다시 칠하는 경우는 특정 좌표를 흰색, 검은색으로 두는 2가지의 경우 밖에 없다.
// 이를 통해서 해당 경우에 대해 다시 칠해야 하는 영역의 개수를 2차원 누적 합으로 표현이 가능하다.
// K * K 인 모든 영역에 대해 가장 큰 값을 찾으면 답이 된다.
#include <bits/stdc++.h>
using namespace std;

int N, M, K, ans = 998244353;
string s;
vector<vector<int>> b, w;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> K;
    // b는 첫 칸이 검은색인 경우의, w는 첫 칸이 하얀색인 경우 다시 칠해야 하는 색의 개수의 누적합이다.
	b.assign(N + 1, vector<int> (M + 1));
	w.assign(N + 1, vector<int> (M + 1));
	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <= M; j++) {
			if (s[j - 1] == 'W') b[i][j] = i + j & 1, w[i][j] = (i + j & 1) == 0; 
			else b[i][j] = (i + j & 1) == 0, w[i][j] = i + j & 1;
			
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
			w[i][j] += w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1];
		}
	}
    // K * K 사이즈의 모든 경우에 대해 최댓값 찾기
	for (int i = N; i >= K; i--) {
		for (int j = M; j >= K; j--) {
			ans = min(ans, b[i][j] - b[i - K][j] - b[i][j - K] + b[i - K][j - K]); 
			ans = min(ans, w[i][j] - w[i - K][j] - w[i][j - K] + w[i - K][j - K]);
		}
	}

	cout << ans;
}