#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	while (true) {
		cin >> T;
		if (cin.eof()) break;
		int arr[100001];
		
		for (int t = 0; t < T; ++t) {
			cin >> arr[t];
		}

		vector<int> tmp;
		for (int i = 0; i < T; i++) {
			int val = arr[i];

			if (tmp.empty() || tmp.back() < val) tmp.push_back(val);
			else {
				auto pos = lower_bound(tmp.begin(), tmp.end(), val);
				*pos = val;
			}
			
		}
		cout << tmp.size() << "\n";
	}
}
