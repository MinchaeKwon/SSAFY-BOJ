#include <iostream>
#include <vector>
using namespace std;

int N, ret;
bool vst[1000000];
vector<int> tmp, retVector;

void sol(int n, int m) {

	if (n != 0 && m == 0 && n > ret) {
		ret = n;
		retVector = tmp;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (((1 << i) & m) > 0) {
			int k = (~(1 << i)) & m;
			if ((n != 0 && k == 0) || !vst[k]) {
				vst[k] = true;
				tmp.push_back(i);
				sol(n + 1, k);
				tmp.pop_back();
			}
		}

		if (((1 << i) & m) == 0) {
			int k = (1 << i) | m;

			if (!vst[k]) {
				vst[k] = true;
				tmp.push_back(i);
				sol(n + 1, k);
				tmp.pop_back();
			}
		}
	}
}

int main(void) {

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	sol(0, 0);
	cout << ret-1 << "\n";
	for (auto r : retVector) cout << r+1 << " ";

	return 0;
}
