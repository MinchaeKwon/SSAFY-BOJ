#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string str;
    int left_cnt=0, right_cnt=0, cnt=0;
    int psum[100001]={0,};
    cin >> str;
    for (char i:str){
        if (i=='(') left_cnt++;
        if (i==')') right_cnt++;
    }
    if (left_cnt>right_cnt){
        reverse(str.begin(),str.end());
        for (int i=0;i<str.size();i++){
            if (str[i]==')'){
                psum[i+1]=psum[i]+1;
            }
            else{
                psum[i+1]=psum[i]-1;
                cnt++;
            }
            if (psum[i+1]==-1){
                cout << cnt;
                exit(0);
            }
        }
    }
    if (right_cnt<left_cnt){
        for (int i=0;i<str.size();i++){
            if (str[i]=='('){
                psum[i+1]=psum[i]+1;
            }
            else{
                psum[i+1]=psum[i]-1;
                cnt++;
            }
            if (psum[i+1]==-1){
                cout << cnt;
                exit(0);
            }
        }
    }
}