#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[40001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> tmp;
	for (int i = 0; i < N; i++) {
		int val = arr[i];

		if (tmp.empty() || tmp.back() < val) tmp.push_back(val);
		else {
			auto pos = lower_bound(tmp.begin(), tmp.end(), val);
			*pos = val;
		}
	}
	cout << tmp.size() << "\n";
}
