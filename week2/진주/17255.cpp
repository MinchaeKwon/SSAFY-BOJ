#include <iostream>
#include <cstring>
#include <map>
#include <set>
using namespace std;

int ret;
string S;
map<set<string>, int> vst;

void dfs(int l, int r, string tmp, set<string> tmpS){
    if(tmp.length() == S.length()){
        if(tmp == S) vst[tmpS] = 1;
        return;
    }

    if(l > 0){
        tmpS.insert(S[l-1]+tmp);
        dfs(l-1, r, S[l-1]+tmp, tmpS);
        tmpS.erase(S[l-1]+tmp);
    }

    if(r < S.length()){
        tmpS.insert(tmp+S[r+1]);
        dfs(l, r+1, tmp+S[r+1], tmpS);
        tmpS.erase(tmp+S[r+1]);
    }
}


int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> S;
    for(int i=0; i < S.size(); i++){
        string tmp = "";
        set<string> tmpS = {tmp+S[i]};
        dfs(i, i, tmp+S[i], tmpS);
    }
    ret = vst.size();

    cout << ret;
    return 0;
}
