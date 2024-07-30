#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;

int D, P;
ll ret;
map<pair<ll, int>, bool> visited;

int getLength(ll num){
    int len = 0;
    while (num){
        num /= 10;
        len++;
    }
    return len;
}

void calc(ll num, int pcnt){
    //방문 체크
    if (visited[{num, pcnt}] || getLength(num) > D)
        return;

    visited[{num, pcnt}] = true;
    if (pcnt == P){
        ret = max(ret, num);
        return;
    }
    for (int i = 2; i <= 9;i++) calc(num * i, pcnt + 1);
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> D >> P;
    ret = -1;
    calc(1, 0);
    
    cout << ret;
    return 0;
}
