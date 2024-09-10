#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

int N, K;
priority_queue<pair<pair<int, int>, int>> PQ; // {{시간, 직원 번호}, 작업 번호}
vector<int> staff; // 사용할 수 있는 직원 번호를 저장하는 벡터
int curTime = 0; // 현재 시간을 추적

ll ret = 0;
ll turn = 1; // 작업 처리 순서를 나타내는 변수

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;
    for(int i=K; i > 0; i--) {
        staff.emplace_back(i); // K명의 직원 번호를 역순으로 staff 벡터에 추가
    }

    for(int i = 0; i < N; i++) {
        int id, w;
        cin >> id >> w;

        if(staff.empty()) { // 사용 가능한 직원이 없는 경우
            curTime = PQ.top().first.first; // 가장 먼저 끝나는 작업의 시간을 현재 시간으로 설정
            while(!PQ.empty()) {
                if(PQ.top().first.first < curTime) break; // 가장 먼저 끝나는 작업이 현재 시간보다 이전에 끝나면 종료
                ret += (turn++) * (ll)PQ.top().second;
                staff.emplace_back(PQ.top().first.second); // 작업을 완료한 직원 번호를 staff 벡터에 추가
                PQ.pop();
            }
        }

        PQ.push({{curTime - w, staff.back()}, id}); // (현재 시간에서 작업 시간을 뺀 값, 직원 번호, 작업 번호)
        staff.pop_back(); // 해당 직원은 작업에 배정되었으므로 staff 벡터에서 제거
    }
    while (!PQ.empty()) { // 남아있는 작업이 있을 경우
        ret += (turn++)*(ll)PQ.top().second;
        PQ.pop();
    }
    cout << ret << "\n";
    return 0;
}
