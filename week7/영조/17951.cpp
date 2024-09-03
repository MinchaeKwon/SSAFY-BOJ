#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int N, K, arr[100001], psum[100001] = {0,};
int score, mx = -1;

int isPossible(int num) {
    int prev=0, cnt=0;
    for (int i=1;i<=N;i++){
        if (psum[i]-psum[prev]>=num){
            cnt++;
            prev=i;
        }
    }
    if (cnt>=K) return 1;
    else return 0;
}

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i];
    }
    int r = psum[N];
    int l = 0;
    while (l <= r) {
        int mid = (l + r + 1) / 2;
        if (isPossible(mid)) {
            score=max(mid,score);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    //cout << isPossible(50);
    cout << score;
}
