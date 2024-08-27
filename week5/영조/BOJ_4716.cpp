#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct info{
    char AorB;
    int dist;
    int idx;
};

bool cmp(info A,info B){
    return A.dist < B.dist;
}

int N, A, B, DAT[1000]={0,};
vector<info> v;

int main()
{
    while(1){
        int answer=0;
        v.clear();
        cin >> N >> A >> B;
        if (N==0&&A==0&&B==0) break;

        for (int i=0;i<N;i++){
            int K, Da, Db;
            cin >> K >> Da >> Db;
            DAT[i]=K;
            v.push_back({'A',Da,i});
            v.push_back({'B',Db,i});
        }
        
        sort(v.begin(),v.end(),cmp);

        for (int i=0;i<v.size();i++){      
            int idx=v[i].idx;
            int prev=DAT[idx];
            if (v[i].AorB=='A'){
                // 방에 이미 다 채웠으면 continue;
                if (DAT[idx]==0) continue;
                // DAT[idx] 도 줄어야 함
                DAT[idx]=max(DAT[idx]-A,0);
                // A가 줄어야 함
                if (A>0) A-=prev;
            }
            else if (v[i].AorB=='B'){
                // 방에 이미 다 채웠으면 continue;
                if (DAT[idx]==0) continue;
                // DAT[idx] 도 줄어야 함
                DAT[idx]=max(DAT[idx]-B,0);
                // B가 줄어야 함
                if (B>0) B-=prev;
            }
            answer+=(prev-DAT[idx])*v[i].dist;
            //cout << v[i].AorB << " " << prev << " " << DAT[idx] << "\n";
        }
        cout << answer << "\n";
    }
}
    