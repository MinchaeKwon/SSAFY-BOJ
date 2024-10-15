#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
using pi = pair<int, int>;

int N, M;
int grid[1001][1001];
int path[1001][1001];
int cycleCnt = 0;

// N W E S (상 좌 하 우 순서)
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

// 방문 기록 저장
bool vst[1001][1001];

void grouping(stack<pi> &st, int groupNum) {
	// 스택에 있는 경로를 모두 그룹화
	while (!st.empty()) {
		pi tmp = st.top();
		st.pop();

		int r = tmp.first;
		int c = tmp.second;
		path[r][c] = groupNum;
	}
}

void move(int r, int c) {
	stack<pi> st;
	st.push({ r, c });
	vst[r][c] = true;

	while (!st.empty()) {
		pi cur = st.top();
		int r = cur.first;
		int c = cur.second;

		int dir = grid[r][c];
		int nr = r + dr[dir];
		int nc = c + dc[dir];

		if (path[nr][nc] != -1) {
			// 이미 사이클 그룹에 포함된 경우, 스택에 남아있는 경로도 같은 그룹으로 처리
			grouping(st, path[nr][nc]);
			return;
		}

		if (vst[nr][nc]) {
			// 경로 내에서 사이클 발견, 새로운 그룹 번호 할당
			cycleCnt++;
			grouping(st, cycleCnt);
			return;
		}

		// 새 좌표로 이동
		st.push({ nr, nc });
		vst[nr][nc] = true;
	}
}

int main(void) {
	cin.tie(0)->ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char tmp;
			cin >> tmp;
			path[i][j] = -1; // path 초기화

			if (tmp == 'N') {
				grid[i][j] = 0;
			}
			else if (tmp == 'W') {
				grid[i][j] = 1;
			}
			else if (tmp == 'S') {
				grid[i][j] = 2;
			}
			else {
				grid[i][j] = 3;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (path[i][j] == -1) {
				move(i, j);
			}
		}
	}

	cout << cycleCnt;
	return 0;
}
