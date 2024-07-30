#include <bits/stdc++.h>

using namespace std;

string str, temp_str="";
int cnt=0;
set<string> st;

void query(int start,int end){
    if (start==0&&end==str.size()){
        st.insert(temp_str);
        return;
    }
    if (start>0) {
        string temp_str_2=temp_str;
        temp_str=temp_str+" "+str.substr(start-1,end-start+1);
        query(start-1,end);
        temp_str=temp_str_2;
    }
    if (end<str.size()){
        string temp_str_2=temp_str;
        temp_str=temp_str+" "+str.substr(start,end+1-start);
        query(start,end+1);
        temp_str=temp_str_2;
    }
}

int main()
{
    cin >> str;

    for (int i=0;i<str.size();i++){
        string temp_str_2=temp_str;
        temp_str=temp_str+" "+str[i];
        query(i,i+1);
        temp_str=temp_str_2; 
    }
    // for (auto i=st.begin();i!=st.end();i++){
    //     cout << *i << "\n";
    // }
    cout << st.size();
}