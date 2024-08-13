#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int ret;
string kipa;
int state[100001] = { 0, };
int preL[100001] = { 0, };
int preR[100001] = { 0, };

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> kipa;
	int N = kipa.length();
	int sum = 0;

	//닫는 괄호 -1, 여는 괄호 1
	for (int i = 0; i < N; i++) {
		if (kipa[i] == ')') {
			sum--;
			state[i] = -1;
		} 
		else {
			sum++;
			state[i] = 1;
		}
	}

	//누적합 배열 만들기
	preL[0] = state[0];
	preR[N-1] = state[N-1];

	for (int i = 1; i < N; i++) preL[i] = preL[i-1] + state[i];
	for (int i = N-2; i >= 0; i--) preR[i] = preR[i + 1] + state[i];

	if (sum == 0) ret = 0; //이미 완벽한 괄호 쌍인 경우
	else if (sum < 0) {
		// 닫는 괄호의 수가 더 많은 경우
		// 닫는 괄호를 여는 괄호로 바꿀 수 있는지 확인한다.
		for (int i = 0; i < N; i++) {
			if (state[i] == -1) ret++;
			if (preL[i] == -1) break;
		}
	}
	else {
		// 여는 괄호의 수가 더 많은 경우
		// 여는 괄호를 닫는 괄호로 바꿀 수 있는지 확인한다.
		for (int i = N-1; i > 0; i--) {
			if (state[i] == 1) ret++;
			if (preR[i] == 1) break;
		}
	}

	cout << ret << "\n";
	return 0;
}
