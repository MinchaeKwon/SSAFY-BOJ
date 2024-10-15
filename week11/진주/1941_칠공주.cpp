#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int pos[5][5];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// 비트로 7명이 인접 확인
bool connCheck(int bit) {
    vector<pair<int, int>> select;
    for (int i = 0; i < 25; i++) {
        if (bit & (1 << i)) {
            int r = i / 5;
            int c = i % 5;

            select.push_back({r, c});
        }
    }

    // BFS로 인접 확인
    queue<pair<int, int>> q;
    bool vst[5][5] = {false};

    q.push(select[0]);
    vst[select[0].first][select[0].second] = true;
    int cnt = 1;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5 && !vst[nr][nc]) {
                // 현재 위치가 비트마스크에 포함된 위치일 때
                if (bit & (1 << (nr * 5 + nc))) {
                    vst[nr][nc] = true;
                    q.push({nr, nc});
                    cnt++;
                }
            }
        }
    }

    return (cnt == 7); // 7명이 모두 인접해야 true
}

// 'S'가 4명 이상인지 확인
bool dasomPower(int bit) {
    int power = 0;
    for (int i = 0; i < 25; i++) {
        if (bit & (1 << i)) {
            int r = i / 5;
            int c = i % 5;
            if (pos[r][c] == 1) power++;
        }
    }
    return (power >= 4);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);

    // 교실 위치 입력 받기
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char in;
            cin >> in;
            pos[i][j] = (in == 'S') ? 1 : 0; // 'S'는 1, 'Y'는 0
        }
    }

    int ret = 0;

    // 25개 중 7개의 비트를 선택하는 모든 경우의 수 탐색
    for (int bit = 0; bit < (1 << 25); bit++) {
        if (__builtin_popcount(bit) == 7) {
            if (dasomPower(bit) && connCheck(bit)) {
                ret++;
            }
        }
    }

    cout << ret;
    return 0;
}
