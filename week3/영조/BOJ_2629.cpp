#include <iostream>
#include <vector>
#include <set>

using namespace std;

int choo_cnt, gooseul_cnt;
vector<int> gooseul_v;
vector<int> choo_v;
vector<int> DP[15001];

int main()
{
    // 입력
    cin >> choo_cnt;
    for (int i=0;i<choo_cnt;i++){
        int choo;
        cin >> choo;
        choo_v.push_back(choo);
    }
    cin >> gooseul_cnt;
    for (int i=0;i<gooseul_cnt;i++){
        int gooseul;
        cin >> gooseul;
        gooseul_v.push_back(gooseul);
    }
    DP[0].push_back(0);
    for (int i=0;i<choo_v.size();i++){
        int val=choo_v[i];
        vector<int> temp_v;
        for (int j=1;j<=15000;j++){
            if (j>=val&&DP[j-val].size()) temp_v.push_back(j);
        }
        for (int j:temp_v){
            for (int k:DP[j-val]){
                int temp=k|=(1<<i);
                DP[j].push_back(temp);
            }
        }
    }
    for (int i:gooseul_v){
        int flag=0;
        for (int j=0;j<=15000;j++){
            if (DP[j].size()&&DP[i+j].size()){
                for (int k:DP[j]){
                    for (int l:DP[i+j]){
                        if (!(k&l)) {
                            cout << "Y ";
                            flag=1;
                            break;
                        }
                    }
                    if (flag) break;
                }
                if (flag) break;
            }
        }
        if (!flag) cout << "N ";
    }
}