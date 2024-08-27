#include <iostream>
#include <vector>
using namespace std;

const int MAX = 3 * 3 * 3 * 3 * 3 * 3 * 3 + 1;
int N;
vector<vector<int>> grid(MAX, vector<int>(MAX));
int zero = 0;
int one = 0;
int mi = 0;

bool check(int sr, int sc, int er, int ec) {
	int tmp = grid[sr][sc];

	for (int i = sr; i < er; i++) {
		for (int j = sc; j < ec; j++) {
			if (grid[i][j] != tmp) return false;
		}
	}

	return true;
}

void DQ(int sr, int sc, int size) {
	int er = sr + size;
	int ec = sc + size;

	if (check(sr, sc, er, ec)) {
		if (grid[sr][sc] == 0) {
			zero++;
		}
		else if (grid[sr][sc] == 1) {
			one++;
		}
		else if (grid[sr][sc] == -1) {
			mi++;
		}
	}
	else {
		int newSize = size / 3;

		DQ(sr, sc, newSize);
		DQ(sr, sc + newSize, newSize);
		DQ(sr, sc + 2 * newSize, newSize);
		DQ(sr + newSize, sc, newSize);
		DQ(sr + newSize, sc + newSize, newSize);
		DQ(sr + newSize, sc + 2 * newSize, newSize);
		DQ(sr + 2 * newSize, sc, newSize);
		DQ(sr + 2 * newSize, sc + newSize, newSize);
		DQ(sr + 2 * newSize, sc + 2 * newSize, newSize);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	// 3으로 나눠지도록 1 ~ 3^N 형태
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

	DQ(0, 0, N);
	cout << mi << "\n" << zero << "\n"  << one << "\n";

	return 0;
}
