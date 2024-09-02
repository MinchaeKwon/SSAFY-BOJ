// 문제에 주어진 조건에 따라 연결하는 경우는 최장 증가 수열을 구하는 문제로 치환이 가능하다.
// 따라서 이분 탐색으로 최장 증가 수열을 구한다.
#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    // 원본과 lis 벡터
    vector<int> v(N), lis;
    // 원본 배열을 순서대로 순회하며 이분 탐색을 통해 단조 증가하도록 관리해준다.
    for (int& i : v) {
        cin >> i;
        auto it = lower_bound(lis.begin(), lis.end(), i);
        if (it == lis.end()) lis.push_back(i);
        else *it = i;
    }
    cout << lis.size();
}