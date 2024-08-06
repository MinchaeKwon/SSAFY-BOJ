#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 5 * 5 * 5 * 5 * 5 + 1;
int maxR = -MAX;
int minR = MAX;

int N;
char grid[5][5];
bool vst[5][5];
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

void DFS(int x, int y, int sum) {

	if (x == N-1 && y == N-1) {
		maxR = max(maxR, sum);
		minR = min(minR, sum);
		return;
	}
	else {
		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (!vst[nx][ny]) {
				vst[nx][ny] = true;

				if (grid[x][y] == '+') DFS(nx, ny, sum+(grid[nx][ny] - '0'));
				else if (grid[x][y] == '-') DFS(nx, ny, sum-(grid[nx][ny] - '0'));
				else if (grid[x][y] == '*') DFS(nx, ny, sum*(grid[nx][ny] - '0'));
				else DFS(nx, ny, sum);

				vst[nx][ny] = false;
			}
		}
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

	DFS(0, 0, grid[0][0] - '0');
	cout << maxR << " " << minR << "\n";
	return 0;
}
