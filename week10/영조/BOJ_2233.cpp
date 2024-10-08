#include <bits/stdc++.h>

using namespace std;

int prev_node[2001], left_node[2001]={0,}, right_node[2001]={0,};
int N, del_1,del_2, del_node1=-1, del_node2=-1, idx=1, temp=1;
int visitied[2001]={0,};
pair<int,int> loc[2001];
char arr[4000];

int main()
{
    cin >> N;
    for (int i=1;i<=2*N;i++) cin >> arr[i];
    cin >> del_1 >> del_2;

    // 만약 제거해야하는 게 root일 때
    if (del_1==0||del_1==2*N||del_2==0||del_2==2*N){
        cout << 1 << " " << 2*N ;
    }

    prev_node[1]=0;
    loc[1]={1,2*N};
    // tree 만들기
    for (int i=2;i<=2*N;i++){
        if (arr[i]=='0'){
            if (!left_node[temp]){
                left_node[temp]=++idx;
                prev_node[idx]=temp;
            }
            else{
                right_node[temp]=++idx;
                prev_node[idx]=temp;
            }
            temp=idx;
            // loc에 해당 노드의 입,출 번호를 저장
            loc[temp].first=i;
            if (i==del_1||i==del_2){
                if (del_node1==-1) del_node1=temp;
                else del_node2=temp;
            }
        }
        else{
            loc[temp].second=i;
            if (i==del_1||i==del_2){
                if (del_node1==-1) del_node1=temp;
                else del_node2=temp;
            }
            temp=prev_node[temp];
        }
    }
    // 첫번째 제거 노드부터 visitied
    for (int i=del_node1;i!=0;i=prev_node[i]){
        visitied[i]=1;
    }
    // 두번째 제거 노드부터 visited 확인
    for (int i=del_node2;i!=0;i=prev_node[i]){
        if (visitied[i]==1){
            cout << loc[i].first << " " << loc[i].second;
            break;
        }
    }
    return 0;
}