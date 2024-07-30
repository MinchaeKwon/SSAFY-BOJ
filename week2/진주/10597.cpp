#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s;
int sLen;
int range;
bool vst[51] = { false, };
vector<int> ret;

void printVector(const vector<int>& vec) {
	for (int num : vec) {
		cout << num << " ";
	}
	cout << "\n";
}

int checkVst() {
	int ret = 0;
	for (int i = 1; i <= range; i++) {
		ret += vst[i];
	}
	return ret;
}

void dfs(int idx) {

	if (ret.size() >= range) {

		if (ret.size() == range && checkVst() == range) {
			printVector(ret);
			exit(0);
		}
		return;
	}

	if (idx >= sLen) return;

	// 한 자리 숫자 추가
	int num1 = s[idx] - '0';
	
	if (!vst[num1]) {

		// 0 하나만 오면 안된다
		if (num1 == 0) return;

		ret.push_back(num1);
		vst[num1] = true;

		dfs(idx + 1);

		ret.pop_back(); // 백트래킹
		vst[num1] = false;
	}

	// 두 자리 숫자 추가
	if (idx + 1 < sLen) {
		int num2 = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
		if (num2 <= range && !vst[num2]) {

			ret.push_back(num2);
			vst[num2] = true;

			dfs(idx + 2);

			ret.pop_back(); // 백트래킹
			vst[num2] = false;
		}
	}
}


int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> s;
	sLen = s.length();

	// 1~9 까지는 len 9
	// 1~19 까지 9 + 2*10 = 29
	// 1~20 까지 9 + 2 *11 = 22+9 = 31

	if (sLen < 10) {
		for (int i = 0; i < sLen; i++) {
			cout << s[i] << " ";
		}
	}
	else {
		range = sLen - 9;
		range = (range / 2) + 9; //이러면 max N값 찾음
		dfs(0);
	}
}
