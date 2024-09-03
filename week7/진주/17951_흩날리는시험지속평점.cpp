#include <iostream>
#include <vector>
using namespace std;
int N, K;

// 현재 주어진 mid 값으로 만들 수 있는 그룹의 수 계산
int countGroups(const vector<int>& arr, int targetSum) {
    int cnt = 0;
    int curSum = 0;

    for (int now : arr) {
        curSum += now;

        if (curSum >= targetSum) {
            // 그룹의 합이 targetSum 이상이 되면 그룹 확정
            cnt++;
            curSum = 0; // 다음 그룹을 위해 합 초기화
        }
    }
    return cnt;
}

// 가능한 최대 그룹의 최소 합을 찾는 함수
int findScore(const vector<int>& arr, int k) {
    int st = 0;
    int ed = 1e9;

    while (st <= ed) {
        int mid = (st+ed)/2;

        if (countGroups(arr, mid) < k) {
            // 그룹 수가 k보다 작으면 targetSum 감소
            ed = mid - 1;
        } else {
            // 그룹 수가 k 이상이면 targetSum 증가
            st = mid + 1;
        }
    }
    return ed; // 가능한 최대 그룹의 최소 합
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N>> K;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << findScore(arr, K);
    return 0;
}
