#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N, arr[100000];
pair<int,int> answer[100000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		answer[i].first = 0;
		answer[i].second = 21e8;
	}
	stack<pair<int, int>> right_stk;
    // 특정 건물의 오른쪽 시야 체크
	for (int i = N - 1; i >= 0; i--) {
        // 자신보다 크거나 같은 건물이 나올 떄까지 pop();
        // 값을 날려도 되는 이유는 어차피 해당 건물에 막혀서 안보이기 떄문
		while (right_stk.size() && (right_stk.top().second <= arr[i])) {
			right_stk.pop();
			if (!right_stk.size()) break;
		}
        // 볼 수 있는 건물 갯수 : stack의 크기
		answer[i].first = right_stk.size();
        
		if (right_stk.size()) answer[i].second = right_stk.top().first;
		right_stk.push({ i,arr[i] });
	}
	stack<pair<int, int>> left_stk;
	for (int i = 0; i < N; i++) {
		while (left_stk.size() && left_stk.top().second <= arr[i]) {
			left_stk.pop();
			if (!left_stk.size()) break;
		}
		answer[i].first += left_stk.size();
		if (left_stk.size()) {
            // 거리가 같다면, 가장 가까운 번호로 계산
			if (abs(left_stk.top().first-i) <= abs(answer[i].second - i)) {
				answer[i].second = left_stk.top().first;
			}
		}
		left_stk.push({ i,arr[i] });
	}
	for (int i = 0; i < N; i++) {
		cout << answer[i].first << " ";
		if (answer[i].first) cout << answer[i].second+1;
		cout << "\n";
	}
}