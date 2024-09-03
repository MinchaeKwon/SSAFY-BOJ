#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int N;
long long sum=0;
vector<int> v;
map<int,vector<int>> mp;

int BS(int num,int morethan) {
	int s_idx = lower_bound(v.begin(), v.end(), num)-v.begin();
	int e_idx = upper_bound(v.begin(), v.end(), num)-v.begin();
	s_idx = max(s_idx - 1, morethan);
	return max(0,e_idx - (s_idx+1));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	/*for (int i = 0; i < N; i++) {
		cout << v[i] << " ";
	}*/
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int num = -(v[i] + v[j]);
			sum+=BS(num, j);
		}
	}
	cout << sum;
}
