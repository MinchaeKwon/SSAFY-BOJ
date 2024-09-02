// 문제 조건의 오름세인 부분은 최장 증가 수열인 부분이다.
// 최장 증가 수열을 펜윅 트리로 구해보자. 자세한 내용은 외부 자료 참고.
#include <bits/stdc++.h>
using namespace std;
// 펜윅 트리의 최대 크기는 10만이며, 1-based 이다.
int N, fw[100001];

// 업데이트 함수는 최댓값 범위까지 최우측 비트를 더해가며 보게 된다.
// 업데이트는 i번 원소로 끝나는 최장 증가 수열의 최대 길이가 k라는 정보이다.
void fw_upd(int i, int k) {
    while (i <= 1e5) {
        fw[i] = max(fw[i], k);
        i += i & -i;
    }
}
// 조회 함수는 해당 노드로부터 최솟값 범위까지 최우측 비트를 빼가며 보게 된다.
// 원본의 1번 원소부터 i번 원소까지 중 최댓값을 반환하며, 이는 해당하는 원소들로 만들 수 있는 최장 증가 수열의 최대 길이이다.
int fw_max(int i) {
    int ret = 0;
    while (i > 0) {
        ret = max(ret, fw[i]);
        i -= i & -i;
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while (1) {
        cin >> N;
        if (cin.eof()) break;
        // 쿼리마다 펜튁 트리를 초기화
        memset(fw, 0, sizeof(fw));
        // 각각의 원소들은 주어지는 순서대로 처리한다.
        // 여기서, 현 시점의 원소 x 를 끝으로 하는 최장 증가 수열을 만드는 경우를 생각해보자.
        // 그 경우, 현재까지 저장된 0 부터 x - 1 까지의 가능한 최장 증가 수열에 1을 더한 길이이다.
        // 이것을 펜윅 트리를 통해 처리한다.
        int lis = 0;
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            int cur_max = fw_max(x - 1) + 1;
            lis = max(lis, cur_max);
            fw_upd(x, cur_max);
        }
        
        cout << lis << "\n";
    }
}