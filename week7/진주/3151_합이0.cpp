#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int tmp = -(arr[i] + arr[j]);
            auto lower = lower_bound(arr.begin() + j + 1, arr.end(), tmp);
            auto upper = upper_bound(arr.begin() + j + 1, arr.end(), tmp);

            // lower_bound와 upper_bound 사이의 개수만큼 cnt에 더하기
            cnt += (upper - lower);
        }
    }

    cout << cnt;
    return 0;
}
