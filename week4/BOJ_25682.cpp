#include <bits/stdc++.h>

using namespace std;

int N, M, K, chess[2001][2001];
int psum[2001][2001]={0,}, mn=INT_MAX;

int main()
{
    cin >> N >> M >> K;

    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            char temp;
            cin >> temp;
            chess[i][j]=temp=='B'?1:0; 
            psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
            if ((i+j)%2==0) psum[i][j]+=chess[i][j];
            else psum[i][j]+=!chess[i][j];
        }

    }

    // for (int i=1;i<=N;i++){
    //     for (int j=1;j<=M;j++){
    //         cout << psum[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i=K;i<=N;i++){
        for (int j=K;j<=M;j++){
            int val=psum[i][j]-(psum[i-K][j]+psum[i][j-K])+psum[i-K][j-K];
            mn=min(mn,K*K-val);
            mn=min(mn,val);
        }
    }
    cout << mn;
}