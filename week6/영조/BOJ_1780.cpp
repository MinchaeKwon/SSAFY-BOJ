#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int N, arr[5000][5000], DAT[3] = { 0, };

void dc(int y, int x, int sz) {
	int val = arr[y][x];
	for (int i = y; i < y + sz; i++) {
		for (int j = x; j < x + sz; j++) {
			if (arr[i][j] != val) {
				sz /= 3;
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						dc(y + k * sz, x + l * sz, sz);
					}
				}
				return;
			}
		}
	}
	DAT[val + 1]++;
}

int main()
{
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	dc(0, 0, N);
	for (int i = 0; i < 3; i++) cout << DAT[i] << "\n";
}
