#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{   
    int N, mx=0, arr[100000], prefix_sum[100000];
    scanf("%d",&N);
    for (int i=0;i<N;i++){
        scanf("%d ",&arr[i]);
        if (i==0) prefix_sum[i]=arr[i];
        if (i>0) prefix_sum[i]+=prefix_sum[i-1]+arr[i];
    }
    for (int i=0;i<N;i++){
        // cout << prefix_sum[i] << " ";
        if (i>=1&&i<N-1){
            mx=max(mx,prefix_sum[N-1]-prefix_sum[0]+prefix_sum[N-1]-prefix_sum[i]-arr[i]);
            mx=max(mx,prefix_sum[N-2]+prefix_sum[i-1]-arr[i]);
            mx=max(mx,prefix_sum[i]-prefix_sum[0]+prefix_sum[N-2]-prefix_sum[i-1]);
        }
    }
    cout << mx;
}