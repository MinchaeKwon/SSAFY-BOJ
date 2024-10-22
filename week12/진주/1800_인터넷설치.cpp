#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e7+1
using namespace std;
using ll = long long;
using pi = pair<int, int>;

int N, P, K;
int ret = -1;
vector<pi> adj[1001];

bool dijkstra(int start, int price){
    vector<ll> dist(N+1, INF);
    priority_queue<pi, vector<pi>, greater<pi>> PQ;
    dist[start] = 0;

    PQ.push({0, start});

    while(!PQ.empty()){
        int curDist = PQ.top().first;
        int curNode = PQ.top().second;
        PQ.pop();

        if(curDist > dist[curNode]) continue;

        for(auto &edge: adj[curNode]){
            int nxtNode = edge.first;
            int nxtDist = curDist + (edge.second > price) ;

            if(nxtDist < dist[nxtNode]){
                dist[nxtNode] = nxtDist;
                PQ.push({nxtDist, nxtNode});
            }
        }
    }
    return dist[N] <= K;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    int maxCost = 0;

    cin >> N >> P >> K;
    for(int i=0; i<P; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        maxCost = max(maxCost, w);
    }

    // 최소 price 이분 탐색(mid)로 찾기
    int l = 0;
    int r = maxCost;
    while(l <= r){
        int mid = (l+r)/2;
        if (dijkstra(1, mid)){
            ret = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ret;
    return 0;
}
