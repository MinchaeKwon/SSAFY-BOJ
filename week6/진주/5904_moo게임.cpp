#include <iostream>
using namespace std;
int N;
char moo[3] = {'m', 'o', 'o'};

void DQ(int N, int K, int len){
    int nlen = 2*len + K+3;

    if(N <= 3){
        cout << moo[N-1];
        return;
    }

    if(nlen < N) DQ(N, K+1, nlen);
    else{
        if(N > len && N <= len+K+3){
            if(N-len != 1) cout << 'o';
            else cout << 'm';
            return;
        }
        else DQ(N-(len+K+3), 1, 3);
    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    DQ(N, 1, 3);
    return 0;
}
