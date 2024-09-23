#include<iostream>
#include<algorithm>
using namespace std;

int N;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int grid[504][504];
int dp[504][504];
int ret;

int dfs(int r, int c){

	if(dp[r][c] != 0) return dp[r][c];

	dp[r][c] = 1; //처음 한 칸 count
	for(int i=0; i<4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];

		if(nr < 0 || nc < 0 || nr >=N || nc >= N) continue;

		if(grid[nr][nc] > grid[r][c]){
			dp[r][c] = max(dp[r][c], dfs(nr,nc) + 1);
		}
	}
	return dp[r][c];
}

int main(void){
	cin.tie(0);
	cout.tie(0);
    ios_base::sync_with_stdio(0);

	cin >> N;

	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			cin >> grid[i][j];
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			ret = max(ret, dfs(i,j));
		}
	}
	cout << ret << "\n";
	return 0;
}
