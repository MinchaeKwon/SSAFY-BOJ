#include <iostream>
#include <string>

using namespace std;

string str, temp_str="", temp_str_2="";
int visitied[11]={0,};
int DAT[26]={0,};

int query(string _str,int sz){
    int sum=0;
    if (_str.size()>=sz) {
        // cout << temp_str_2 << "\n";
        return 1;
    }
    for (int i=0;i<str.size();i++){
        if (!visitied[i]&&(*(_str.end()-1)!=str[i])){
            _str+=str[i];
            visitied[i]=1;
            // temp_str_2+='0'+i;
            sum+=query(_str,sz);
            _str=_str.substr(0,_str.size()-1);
            visitied[i]=0;
            // temp_str_2=temp_str_2.substr(0,temp_str_2.size()-1);
        }
    }
    return sum;
}

int fact(int num){
    if (num==1) return 1;
    else return num*fact(num-1);
}

int main(){
    
    cin >> str;
    int divide=1;
    for (char i:str) DAT[i-'a']++;
    for (int i=0;i<26;i++){
        if (DAT[i]) divide*=fact(DAT[i]);
    }
    cout << query(temp_str,str.size())/divide;
}