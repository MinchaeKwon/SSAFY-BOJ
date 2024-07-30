#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v;
string str;
int N, DAT[100]={0,}, cnt=0;
bool RET=false;

bool isVisitied(int start,int sz){
    for (int i=start;i<start+sz;i++){
        if (DAT[i]){
            return true;
        }
    }
    return false;
}

void fillDAT(int start, int sz, int num){
    for (int i=start;i<start+sz;i++) DAT[i]=num;
}

void query(string n){
    //cout << stoi(n) << "\n";
    if (RET==true) return;
    if (stoi(n)==1){
        RET=true;
        sort(v.begin(),v.end());
        for (auto i:v){
            cout << str.substr(i.first,i.second) << " ";
        }
        return;
    }
    n=to_string(stoi(n)-1);
    for (int i=0;i<=str.size()-n.size();i++){
        if (str.substr(i,n.size())==n&&!isVisitied(i,n.size())){
            v.push_back({i,n.size()});
            fillDAT(i,n.size(),1);
            query(to_string(stoi(n)));
            fillDAT(i,n.size(),0);
            v.pop_back();
        }
    }
}

int main()
{
    cin >> str;
    if (str.size()<10) N=str.size();
    else N=9+(str.size()-9)/2;
    query(to_string(N+1));
}