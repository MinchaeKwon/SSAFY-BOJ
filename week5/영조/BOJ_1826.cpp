#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, dest, oil, cnt=0;
vector<pair<int,int>> v;
priority_queue<int> pq;

int main()
{
    
    cin >> N;
    v.resize(N);
    for (int i=0;i<N;i++){
        cin >> v[i].first >> v[i].second;
    }
    cin >> dest >> oil;

    sort(v.begin(),v.end());
    v.push_back({dest,0});

    for (int i=0;i<=N;i++){
        // 현재 기름으로 i번째까지 갈 수 없을 때
        if (oil<v[i].first){
            // 지금까지 지나온 주유소 중 가장 기름 많이 주는 곳부터
            while(pq.size()){
                oil+=pq.top();
                pq.pop();
                cnt++;
                // i번째까지 갈 수 있다면 break;
                if (oil>=v[i].first){
                    break;
                }
            }
            // 모든 주유소를 들렸는데 i번째까지 갈 수 없다면 -1 출력
            if (oil<v[i].first){
                cout << "-1";
                exit(0);
            }
        }
        // 지나온 주유소 추가
        if (i!=N) pq.push(v[i].second);
        //cout << oil << " " << cnt << "\n";
    }
    cout << cnt;
    
}