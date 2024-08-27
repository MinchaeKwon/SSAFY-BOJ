#include <bits/stdc++.h>

using namespace std;

int K, A, B, psum_A[4000]={0,}, psum_B[4000]={0,};
vector<int> A_v, B_v;
map<int,int> A_mp, B_mp;
int A_sum=0, B_sum=0, cnt=0;

int main()
{
    cin >> K;
    cin >> A >> B;
    
    A_v.resize(A+1);
    B_v.resize(B+1);
    for (int i=1;i<=A;i++){
        cin >> A_v[i];
        A_sum+=A_v[i];
    }
    for (int i=1;i<=B;i++){
        cin >> B_v[i];
        B_sum+=B_v[i];
    }
    A_mp[A_sum]=1;
    B_mp[B_sum]=1;
    if (A_sum==K) cnt++;
    if (B_sum==K) cnt++;
    for (int i=1;i<=A-2;i++) A_v.push_back(A_v[i]);
    for (int i=1;i<=B-2;i++) B_v.push_back(B_v[i]);
    for (int i=1;i<A_v.size();i++) psum_A[i]=psum_A[i-1]+A_v[i];
    for (int i=1;i<B_v.size();i++) psum_B[i]=psum_B[i-1]+B_v[i];

    // for (int i=1;i<=A_v.size();i++) cout << psum_A[i] << " ";
    // cout << "\n";
    // for (int i=1;i<=B_v.size();i++) cout << psum_B[i] << " ";
    // cout << "\n";
    
    for (int i=1;i<=A;i++){
        for (int j=0;j<=A-2;j++){
            int val=psum_A[i+j]-psum_A[i-1];
            A_mp[val]++;
            if ((val)==K) cnt++;
        }
    }
    for (int i=1;i<=B;i++){
        for (int j=0;j<=B-2;j++){
            int val=psum_B[i+j]-psum_B[i-1];
            B_mp[val]++;
            if ((val)==K) cnt++;
        }
    }
    for (auto i:A_mp){
        if (B_mp.count(K-i.first)){
            cnt+=i.second*B_mp[K-i.first];
        }
    }
    cout << cnt;
}       