#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

char arr[5][5];
int temp_arr[5][5] = { 0, }, visitied[5][5] = { 0, }, answer=0;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
vector<int> choose_v;

pair<int, int> dfs(int sz,int y, int x) {
	visitied[y][x] = 1;
	int sum = 1;
	int on = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
		if (visitied[ny][nx]||!temp_arr[ny][nx]) continue;
		pair<int, int> temp = dfs(sz+1,ny, nx);
		sum += temp.first;
		on += temp.second;
	}
	if (arr[y][x] == 'S') on++;
	return { sum,on };
}

void choose(int lev, int idx) {
	if (lev == 7) {
		pair<int,int> ret=dfs(0,choose_v[0]/5,choose_v[0]%5);
		//cout << ret.first << " " << ret.second << "\n";
		if (ret.first == 7 && ret.second >= 4) answer++;
		fill(&visitied[0][0], &visitied[0][0] + 5 * 5, 0);
		return;
	}
	for (int i = idx+1; i < 25; i++) {
		int y = i / 5;
		int x = i % 5;
		choose_v.push_back(i);
		temp_arr[y][x] = 1;

		choose(lev + 1, i);

		choose_v.pop_back();
		temp_arr[y][x] = 0;
	}
}

int main()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	choose(0, -1);
	cout << answer;
}