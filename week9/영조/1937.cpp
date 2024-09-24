#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[500][500], dp[500][500], visitied[500][500];
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
int answer = 0;

int dfs(int y, int x, int dist) {
	int mx = dist;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || nx<0 || ny>=N || nx>=N) continue;
		if (arr[ny][nx] <= arr[y][x]) continue;
		if (dp[ny][nx]>0) {
			mx = max(mx, dist + 1 + dp[ny][nx]);
			continue;
		}
		visitied[ny][nx] = 1;
		mx = max(mx, dfs(ny, nx, dist + 1));
		visitied[ny][nx] = 0;
	}
	dp[y][x] = mx - dist;
	answer = max(dp[y][x], answer);
	return mx;
}

int main()
{
	fill(&dp[0][0], &dp[0][0] + 500 * 500, 0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dfs(i, j, 1);
		}
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << answer+1;
}
