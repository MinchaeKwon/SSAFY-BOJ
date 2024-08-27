#include <iostream>
#include <string>
using namespace std;

string pre, in;
int idx = 0;

void findPost(int st, int ed) {
	if (st > ed) return;

	// root를 중심으로 분할해서 탐색
	// inorder 순서에서 root 자리를 찾는다
	int tmpRoot = in.find(pre[idx++]);

	findPost(st, tmpRoot - 1);
	findPost(tmpRoot + 1, ed);

	cout << in[tmpRoot];
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);

	while (true) {
		// 순서 문자열 초기화하고 입력 받기
		pre = "";
		in = "";
		idx = 0;
		cin >> pre >> in;

		int len = pre.length();
		if (len == 0) break;

		findPost(0, len-1); //전체 길이 start ~ end

		cout << "\n";
	}
	return 0;
}
