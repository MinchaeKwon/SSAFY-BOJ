#include <bits/stdc++.h>

using namespace std;

int T, N, M, D;
int mp[1001][1001]={0,}, visitied[1001]={0,};

int dfs(int prev,int node){
    //cout << node << ": ";
    int sum=0;
    for (int i=1;i<=1000;i++){
        if (mp[node][i]&&!visitied[i]) {
            visitied[node]=1;
            sum+=dfs(node,i);
            visitied[node]=0;
        }
    }
    int ret=min(sum,mp[prev][node]);
    if (sum==0) ret=mp[prev][node]; 
    //cout << ret << "\n";
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int tc=0;tc<T;tc++){
        // 초기화
        fill(&mp[0][0],&mp[0][0]+1001*1001,0);
        fill(visitied,visitied+1001,0);

        cin >> N >> M;
        for (int i=0;i<M;i++){
            int a,b,D;
            cin >> a >> b >> D;
            mp[a][b]=D;
            mp[b][a]=D;
        }
        mp[0][1]=INT_MAX;
        if (N==1) cout << 0 << "\n";
        else cout << dfs(0,1) << "\n";
    }
    
}