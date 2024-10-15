#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int N, M, answer = 0, idx = 1;
int DAT[26] = { 0 }, visitied[1000][1000] = {0};
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
char arr[1000][1000];
set<int> st;

void dfs(int y, int x, int idx) {
	int dir = DAT[arr[y][x] - 'A'];
	//cout << y << " " << x << " " << dir << " " << arr[y][x] << "\n";
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (visitied[ny][nx] == idx) {
		answer++;
		return;
	}
	if (visitied[ny][nx]) {
		return;
	}
	visitied[ny][nx] = idx;
	dfs(ny, nx, idx);
}

int main()
{
	DAT['N' - 'A'] = 0;
	DAT['E' - 'A'] = 1;
	DAT['S' - 'A'] = 2;
	DAT['W' - 'A'] = 3;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visitied[i][j]) continue;
			visitied[i][j]=idx;
			dfs(i, j,idx);
			idx++;
		}
	}
	cout << answer;
}