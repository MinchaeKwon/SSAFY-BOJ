#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, L, P;
pair<int, int> station[10001];
int ret = 0;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i < N; i++){
        cin >> station[i].first >> station[i].second;
    }

    cin >> L >> P;

    priority_queue<int> PQ;
    sort(station, station+N);

    int np = 0;
    int nl = P;

    while(nl < L){
        while (np < N && station[np].first <= nl){
            PQ.push(station[np++].second);
        }

        // 목적지 도착 못했는데 갈 수 있는 곳 없을 때
        if (PQ.empty()){
            ret = -1;
            break;
        }

        nl += PQ.top();
        PQ.pop();
        ret++;
    }

    cout << ret << "\n";
    return 0;
}
