#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S;
int ret;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> S;
    sort(S.begin(), S.end());
    ret = 0;

    do{
        int tmp = 1;
        for(int i=0; i < S.size()-1; i++){
            if(S[i] == S[i+1]){
                tmp = 0;
                break;
            }
        }
        ret += tmp;
    } while (next_permutation(S.begin(), S.end()));

    cout << ret;
    return 0;
}
