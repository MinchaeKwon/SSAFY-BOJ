#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> v;
int dp[100001][4][4];
set<pair<int, int>> pos_v[100001];

int main()
{
	// 초기화
	fill(&dp[0][0][0], &dp[0][0][0] + 100001 * 4 * 4, 21e8);
	v.push_back(0);

	while (1) {
		int num;
		cin >> num;
		if (num == 0) break;
		v.push_back(num);
	}
	
	set<pair<int,int>> temp;
	pos_v[0].insert({ 0, 0 });
	dp[0][0][0] = 0;

	for (int i = 1; i < v.size();i++) {
		// num은 현재 이동해야 하는 방향
		int num = v[i];
		for (auto j:pos_v[i-1]) {
			int left_before = j.first;
			int right_before = j.second;

			// 왼쪽 발이 이동
			int left_after = num;
			int right_after = right_before;
			int add=0;
			// 왼쪽 발의 이동 정도에 따라 add 값 변동
			if (left_before == 0) add = 2;
			else if (left_before == left_after) add = 1;
			else if (abs((left_after - left_before) % 2) == 0) add = 4;
			else if (abs((left_after - left_before) % 2) == 1) add = 3;
			// 이동 후 dp의 값이 이동 전 dp의 값 + add 보다 크다면 dp 갱신
			if (dp[i][left_after][right_after] > dp[i - 1][left_before][right_before] + add) {
				dp[i][left_after][right_after] = dp[i - 1][left_before][right_before] + add;
			}
			// i번째에서 가능한 조합 저장
			pos_v[i].insert({ left_after,right_after });
			//cout << left_before << "->" << left_after << ": ";
			//cout << (left_after - left_before) % 2 << "\n";
			// 오른쪽 발이 이동
			left_after = left_before;
			right_after = num;
			if (right_before == 0) add = 2;
			else if (right_before == right_after) add = 1;
			else if (abs((right_after - right_before) % 2) == 0) add = 4;
			else if (abs((right_after - right_before) % 2) == 1) add = 3;
			if (dp[i][left_after][right_after] > dp[i - 1][left_before][right_before] + add) {
				dp[i][left_after][right_after] = dp[i - 1][left_before][right_before] + add;
			}
			pos_v[i].insert({ left_after,right_after });
			cout << right_before << "->" << right_after << ": ";\
			cout << (right_after - right_before) % 2 << "\n";
		}
	}
	int answer = 21e8;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			answer = min(answer, dp[v.size()-1][i][j]);
		}
	}
	cout << answer;
}
