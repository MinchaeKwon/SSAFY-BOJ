#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

string str, preorder, inorder;
pair<int, int> v[200];
set<char> visitied;
map<char, int> DAT;

void postorder(char node) {
	int left = v[int(node)].first;
	int right = v[int(node)].second;
	if (left != -1) {
		postorder(char(left));
	}
	if (right != -1) {
		postorder(char(right));
	}
	cout << node;
}

void maketree(char node, string temp_inorder) {
	// 방문처리
	visitied.insert(node);
	// inorder 기준 left, right 벡터에 넣어줌
	int root_idx = temp_inorder.find(node);
	if (root_idx == -1) return;
	string left_str="", right_str="";
	int left_mn = 21e8, right_mn = 21e8;
	for (int i = root_idx - 1; i >= 0; i--) {
		left_mn = min(left_mn, DAT[temp_inorder[i]]);
	}
	if (root_idx>=1) left_str = temp_inorder.substr(0, root_idx);
	for (int i = root_idx + 1; i < temp_inorder.size(); i++) {
		right_mn = min(right_mn, DAT[temp_inorder[i]]);
	}
	if (root_idx+1<temp_inorder.size()) right_str = temp_inorder.substr(root_idx + 1);
	int left_node = -1, right_node = -1;
	if (left_str.size()) {
		left_node = preorder[left_mn];
		maketree(char(left_node), left_str);
	}
	if (right_str.size()) {
		right_node = preorder[right_mn];
		maketree(char(right_node), right_str);
	}
	v[int(node)] = { left_node,right_node };
}

int main()
{
	while (cin >> preorder >> inorder) {
		// 초기화
		visitied.clear();
		DAT.clear();
		for (int i = 0; i < 100; i++) {
			v[i].first = -1;
			v[i].second = -1;
		}
		// 입력 후 split
		//cin >> preorder >> inorder;
		//if (!preorder.length()) break;
		for (int i = 0; i < preorder.size(); i++) DAT[preorder[i]] = i;
		// preorder와 inorder 정보를 바탕으로 트리 만들기
		char root = preorder[0];
		maketree(root, inorder);
		// visitied 초기화
		visitied.clear();
		// postorder 로 출력
		postorder(root);
		cout << "\n";
	}
	return 0;
}
