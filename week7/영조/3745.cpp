#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while(cin >> N){
        int len=0, arr[100001]={0,};
        for (int i=0;i<N;i++){
            int num;
            cin >> num;
            auto idx=lower_bound(arr,arr+len,num);
            if (*idx==0) len++;
            *idx=num;
        }
        cout << len << "\n";
    }
}
