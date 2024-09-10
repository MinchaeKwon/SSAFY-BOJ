#include <iostream>
#include <queue>
using namespace std;

int N, H, T;
priority_queue<int> PQ;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> H >> T;

	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		PQ.push(tmp);
	}

	int cnt = 0;
	bool flg = false;

	int top = PQ.top();
	if (H > top) {
		cnt = 0;
		flg = true;
	}
	else {
		for (int i = 1; i <= T; ++i) {
			int top = PQ.top();

			if (H > top) {
				flg = true;
				break;
			}
			else {
				// top이 1이면 더 이상 줄일 수 없다
				if (top == 1) break;

				int tmp = top / 2;
				cnt++;
				PQ.pop();
				PQ.push(tmp);
			}
		}
	}

	if (flg) cout << "YES\n" << cnt;
	else {
		// 모든 T번의 시도 후에도 H가 top보다 크지 않다면
		if (H > PQ.top()) cout << "YES\n" << T;
		else cout << "NO\n" << PQ.top();
	}
	return 0;
}
