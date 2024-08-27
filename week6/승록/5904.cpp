// 0, 1, 2, ... n 번째로써 가능한 moo 문자열들 전처리 후 길이에 따라 분기하고 재귀
// 과정에서 이분 탐색
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> moos = {0, 3};

char mooo(int k) {
    // 이전 범위까지 이분탐색해서 몇 번째 moo 문자열의 몇 번째 글자인지를 찾아냄
    // 현재 속한 문자열이 lo번쨰 moo 문자열이고 이 문자열에서 추가되는 가운데 moo의 길이는 curmoo
    auto it = lower_bound(moos.begin(), moos.end(), k);
    int lo = *(it - 1), curmoo = it - moos.begin() + 2;
    k -= lo;
    if (k <= curmoo) return k == 1 ? 'm' : 'o';
    return mooo(k - curmoo);
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    while (moos.back() < 1e9) {
        moos.push_back(moos.back() * 2 + moos.size() + 2);
    }
    
    int N;
    cin >> N;
    cout << mooo(N);
}