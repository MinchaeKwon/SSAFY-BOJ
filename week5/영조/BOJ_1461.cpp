#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    int cnt=0;
    vector<int> plus_v, minus_v;

    cin >> N >> M;

    for (int i=0;i<N;i++){
        int temp;
        cin >> temp;
        if (temp>0) plus_v.push_back(temp);
        else minus_v.push_back(abs(temp));
    }

    if (plus_v.size()) sort(plus_v.begin(),plus_v.end());
    if (minus_v.size()) sort(minus_v.begin(),minus_v.end());

    if (minus_v.size()==0||((plus_v.size()&&minus_v.size())&&(*(plus_v.end()-1)>*(minus_v.end()-1)))){
        int sz=min(M,int(plus_v.size()));
        cnt+=*(plus_v.end()-1);
        plus_v.erase(plus_v.end()-sz,plus_v.end());
    }
    else if (plus_v.size()==0||((plus_v.size()&&minus_v.size())&&(*(plus_v.end()-1)<=*(minus_v.end()-1)))){
        int sz=min(M,int(minus_v.size()));
        cnt+=*(minus_v.end()-1);
        minus_v.erase(minus_v.end()-sz,minus_v.end());
    }
    while(plus_v.size()){
        int sz=min(M,int(plus_v.size()));
        cnt+=2*(*(plus_v.end()-1));
        plus_v.erase(plus_v.end()-sz,plus_v.end());
    }
    while(minus_v.size()){
        int sz=min(M,int(minus_v.size()));
        cnt+=2*(*(minus_v.end()-1));
        minus_v.erase(minus_v.end()-sz,minus_v.end());
    }
    cout << cnt;
}