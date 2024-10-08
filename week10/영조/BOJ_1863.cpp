#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, num, cnt=0;
    stack<int> stk;
    vector<int> v;
    cin >> N;
    v.resize(N+1);
    v[0]=0;
    for (int i=1;i<=N;i++){
        cin >> num >> v[i];
    }
    for (int i=1;i<=N;i++){
        // 현재 건물보다 stk의 top이 낮거나 같을 떄까지 stk.pop()
        // v[i]보다 큰 이전의 건물은 의미가 없음
        while (stk.size()&&v[i]<stk.top()){
            stk.pop();
        }
        // 만약 높이가 0이거나, top의 높이가 v[i]와 같다면 하나가 중복될 수 있음
        if (v[i]==0||(stk.size()&&stk.top()==v[i])){
            continue;
        }
        cnt++;
        stk.push(v[i]);
    }
    cout << cnt;
}