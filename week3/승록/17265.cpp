// dp를 할 수도 있겠지만 dfs를 쓰는 구현이 용이하다.
// dfs를 이용하여 모든 경우의 수를 탐색하면 된다.
#include <bits/stdc++.h>
using namespace std;

int N, arr[5][5], mx = -1e9, mn = 1e9;

void dfs(int x, int y, int cur) {
    // 도착지에 도달하면 최대 최소 갱신 후 리턴
    if (x == N - 1 && y == N - 1) {
        mx = max(mx, cur);
        mn = min(mn, cur);
        return;
    }
    // 범위를 벗어나면 리턴
    if (x >= N || y >= N) return;
    // 대각선 위치로 가지는 경우
    if (x + 1 < N && y + 1 < N) {
        if (arr[x + 1][y] == 10) {
            dfs(x + 1, y + 1, cur + arr[x + 1][y + 1]);
        }
        else if (arr[x + 1][y] == 11) {
            dfs(x + 1, y + 1, cur * arr[x + 1][y + 1]);
        }
        else if (arr[x + 1][y] == 12) {
            dfs(x + 1, y + 1, cur - arr[x + 1][y + 1]);
        }

        if (arr[x][y + 1] == 10) {
            dfs(x + 1, y + 1, cur + arr[x + 1][y + 1]);
        }
        else if (arr[x][y + 1] == 11) {
            dfs(x + 1, y + 1, cur * arr[x + 1][y + 1]);
        }
        else if (arr[x][y + 1] == 12) {
            dfs(x + 1, y + 1, cur - arr[x + 1][y + 1]);
        }
    }
    // 오른쪽 위치로 가지는 경우
    if (x + 1 < N) {
        if (arr[x + 1][y] == 10) {
            dfs(x + 2, y, cur + arr[x + 2][y]);
        }
        else if (arr[x + 1][y] == 11) {
            dfs(x + 2, y, cur * arr[x + 2][y]);
        }
        else if (arr[x + 1][y] == 12) {
            dfs(x + 2, y, cur - arr[x + 2][y]);
        }
    }
    // 아래쪽 위치로 가지는 경우
    if (y + 1 < N) {
        if (arr[x][y + 1] == 10) {
            dfs(x, y + 2, cur + arr[x][y + 2]);
        }
        else if (arr[x][y + 1] == 11) {
            dfs(x, y + 2, cur * arr[x][y + 2]);
        }
        else if (arr[x][y + 1] == 12) {
            dfs(x, y + 2, cur - arr[x][y + 2]);
        }
    }
}   

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N;
    // 입력부
    // 숫자는 그대로, +는 10, *는 11, -는 12로 변환하여 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if ('0' <= c && c <= '9') {
                arr[i][j] = c - '0';
            }
            else if (c == '+') {
                arr[i][j] = 10;
            }
            else if (c == '*') {
                arr[i][j] = 11;
            }
            else arr[i][j] = 12;
        }
    }
    // dfs로 모든 경우의 수 탐색 후 최대 최소 출력
    dfs(0, 0, arr[0][0]);
    cout << mx << " " << mn << "\n";
}