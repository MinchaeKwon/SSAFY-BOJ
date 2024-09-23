// 대나무가 더 많은 지점으로만 이동하게 되므로, 판다의 이동 방향은 DAG가 된다.
// 따라서 dfs를 이용해 dp 점화식을 세울 수 있다.
#include <iostream>
using namespace std;

int N, ans;
int forest[501][501];
int hist[501][501];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int dfs(int r, int c) {
    if (hist[r][c]) return hist[r][c];

    int max_cnt = 0;
    // 4방향을 보면서 더 큰 숫자의 대나무 밭으로만 이동하도록 dp
    for (int i = 0; i < 4; ++i) {
        int nx = r + dir[i][0], ny = c + dir[i][1];
        if (0 < nx && nx <= N && 0 < ny && ny <= N) {
            if (forest[nx][ny] > forest[r][c]) max_cnt = max(max_cnt, dfs(nx, ny));
        }
    }

    return hist[r][c] = max_cnt + 1;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> forest[i][j];
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
        dfs(i, j);
        ans = max(ans, hist[i][j]);
    }
    cout << ans;
}
