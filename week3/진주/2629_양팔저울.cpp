#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int weight[31];
int marble[7];
bool dp[31][40001];

void fillDpTable() {
    dp[0][0] = true;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 40000; j++) {
            if (!dp[i-1][j]) continue;
            dp[i][j] = true;
            
            if (abs(j - weight[i]) >= 0) dp[i][abs(j - weight[i])] = true;
            if (j + weight[i] <= 40000) dp[i][j + weight[i]] = true;
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> weight[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> marble[i];
    }

    fillDpTable();
    for (int i = 0; i < M; i++) {
        if (dp[N][marble[i]]) cout << "Y ";
        else cout << "N ";
    }
    return 0;
}
