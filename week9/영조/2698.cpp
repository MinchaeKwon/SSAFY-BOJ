#include <bits/stdc++.h>

using namespace std;

int main()
{
    int TC;
    cin >> TC;
    while(TC--){
        long long n, k, dp[101][101][2]={0,};
        dp[0][0][0]=1;
        dp[0][0][1]=1;
        dp[0][1][0]=0;
        dp[0][1][1]=0;
        cin >> n >> k;
        if (n==1||k>=n){
            cout << "0\n";
            continue;
        }
        for (int i=1;i<n;i++){
            for (int j=0;j<n;j++){
                dp[i][j][0]+=(dp[i-1][j][1]+dp[i-1][j][0]);
                dp[i][j][1]+=dp[i-1][j][0];
                if (j>0) dp[i][j][1]+=dp[i-1][j-1][1];
            }
        }
        cout << dp[n-1][k][1]+dp[n-1][k][0] << "\n";
    }
}
