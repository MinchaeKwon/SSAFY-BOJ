#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int T, N, M, D;
int mp[1001][1001]={0,}, visitied[1001]={0,};

int dfs(int prev,int node,int lev){
    cout << node << ": ";
    int sum=0;
    for (int i=1;i<=1000;i++){
        if (mp[node][i]&&!visitied[i]) {
            visitied[node]=1;
            sum+=dfs(node,i,lev+1);
            visitied[node]=0;
        }
    }
    int ret=min(sum,mp[prev][node]);
    cout << ret << "\n";
    return ret;
}

int main()
{
    cin >> T;
    for (int tc=0;tc<T;tc++){
        cin >> N >> M;
        for (int i=0;i<M;i++){
            int a,b,D;
            cin >> a >> b >> D;
            mp[a][b]=D;
            mp[b][a]=D;
        }
    }
    mp[0][1]=INT_MAX;
    mp[1][0]=INT_MAX;
    cout << dfs(0,1,0);
}