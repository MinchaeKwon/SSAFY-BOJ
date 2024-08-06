#include <iostream>
#include <vector>
using namespace std;

//1. 리프 노드를 다 끊어낼건데
//2. 리프 노드 한 개를 끊는 값과, 리프 노드의 부모를 끊는 값을 비교
//3. 그런데 부모가 바로 위 부모가 아니라 중간 부모일 수도 있음
//4. 리프 부터 타고 가면서 dp로 min을 갱신해줘야함
//5. min(바로 밑 자식들의 합, 본인 Weight)

const int INF = 20000; //20*1000
int T, N, M;
vector<pair<int, int>> tree[1001];
bool vst[1001] = {false, };
int dp[1001];

void init(){
    for(int i=0; i < 1001; i++){
        tree[i].clear();
        vst[i] = false;
        dp[i] = INF;
    }
}

//자식들의 합을 반환하는 dfs함수
int dfs(int st, int ed){
    if (!vst[ed]){
        //탐색 시작
        bool isLeaf = true;
        vst[ed] = true;
        int sum = 0;

        for(int i=0; i < tree[ed].size(); i++){
            int nxt = tree[ed][i].first;
            int nxtW = tree[ed][i].second;
            if(nxt == st) continue; //역방향 이동 금지

            isLeaf = false;
            dp[nxt] = nxtW;
            sum += dfs(ed, nxt);
        }
        if(isLeaf) dp[ed] = tree[ed][0].second;
        else dp[ed] = min(dp[ed], sum);
    }
    return dp[ed];
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;

    for(int t=0; t < T; t++){
        cin >> N >> M;

        if (N==1){ //edge case
            cout << 0 << "\n";
            break;
        }
        init();

        for(int m=0; m < M; m++){
            int u, v, w;
            cin >> u >> v >> w;
            tree[u].push_back({v, w});
            tree[v].push_back({u, w});
        }
        cout << dfs(0, 1) << "\n";
    }
    return 0;
}
