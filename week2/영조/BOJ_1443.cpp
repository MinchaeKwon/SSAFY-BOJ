#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int D, P, cnt=0, qcnt=0;
long long sum=1, mx=1;
map<pair<long long,int>,bool> mp;
map<long long,int> visitied;

void query(int sz,int lev,int limit){
    if (mp.count({sum,lev})) return;
    // if (visitied.find(sum)!=visitied.end()&&visitied[sum]==lev) return;
    if (sum>sz) return;
    if (mx!=1&&sum*pow(9,limit-lev)<mx) return;
    if (sum*pow(2,limit-lev)>=sz) return;
    if (limit==lev){
        mx=max(sum,mx);
        return;
    }
    mp[{sum,lev}]=true;
    // visitied[sum]=lev;
    for (int i=9;i>=2;i--){
        sum*=i;
        query(sz,lev+1,limit);
        sum/=i;
    }
}


int main()
{
    cin >> D >> P;
    if (pow(2,P)>=pow(10,D)) cout << "-1";
    else{
        query(pow(10,D),0,P);
        cout << mx << "\n";
    }
}