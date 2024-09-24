#include <iostream>
#include <algorithm>
using namespace std;

const int loop = 100000;
const int INF = loop * 4 + 1;
int order[100001];
int N = 0;
int dp[100001][5][5];

int dist(int a, int b) {
    if (a == b) return 1;
    if (a == 0) return 2;

    a--;
    b--;

    if ((a + 1) % 4 == b || (a + 3) % 4 == b) return 3;
    else if ((a + 2) % 4 == b) return 4;
    else return INF;
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    fill(&dp[0][0][0], &dp[100000][4][5], INF);
    dp[0][0][0] = 0;

    for (int i = 0; i < loop; ++i) {
        cin >> order[i];
        if (order[i] == 0) break;
        N++;
    }

    for (int i = 1; i <= N; ++i) {
        for (int x = 0; x < 5; ++x) {
            for (int y = 0; y < 5; ++y) {
                if (dp[i - 1][x][y] >= INF) continue;
                int a = dist(x, order[i - 1]);  // 왼발 움직임
                int b = dist(y, order[i - 1]);  // 오른발 움직임

                dp[i][x][order[i - 1]] = min(dp[i][x][order[i - 1]], dp[i - 1][x][y] + b);
                dp[i][order[i - 1]][y] = min(dp[i][order[i - 1]][y], dp[i - 1][x][y] + a);
            }
        }
    }

    int ret = INF;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            ret = min(ret, dp[N][i][j]);
        }
    }
    cout << ret;
    return 0;
}
