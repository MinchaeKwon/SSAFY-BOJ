#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int S, M, N;
ll ret = 0;
int marr[1001] = { 0, };
int narr[1001] = { 0, };
int arrCnt_M[2000001] = {0, };
int arrCnt_N[2000001] = {0, };
map<int, int> cnt;

void calSum (int p, int arr[], int arrCnt[]) {
	for (int i = 1; i <= p; i++) {
		int sum = 0;

		for (int j = 0; j < i; j++) sum += arr[j];
		arrCnt[sum]++;

		if (sum == S) ret++;

		if (i == p) break;

		for (int j = 1; j < p; j++) {
			sum -= arr[j - 1];
			sum += arr[(j + i - 1) % p];
			arrCnt[sum]++;

			if (sum == S) ret++;
		}
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> S;
	cin >> M >> N;

	for (int i = 0; i < M; i++) cin >> marr[i];
	for (int i = 0; i < N; i++) cin >> narr[i];
	//누적합, 투포인터로 가능한 조합 만들어 놓고 하나에서 이분탐색?

	calSum(M, marr, arrCnt_M);
	calSum(N, narr, arrCnt_N);

	for (int i = 1; i < S; i++) {
		int j = S - i;
		ret += arrCnt_M[i] * arrCnt_N[j];
	}

	cout << ret << "\n";
	return 0;
}
