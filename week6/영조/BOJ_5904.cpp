#include <iostream>

using namespace std;

long long N,idx=3,arr[1000000];
char DAT[3]={'m','o','o'};

int main()
{
    int N;
    cin >> N;
    N--;
    if (N<3){
        cout << DAT[N];
        exit(0);
    }
    arr[3]=3;
    // N보다 큰 값이 나올 때까지, 가운데 값을 인덱스로 갖는 수열의 크기를 저장
    while(arr[idx]<=N){
        arr[idx+1]=2*arr[idx]+(idx+1);
        idx++;
    }
    cout << arr[idx] << "\n";
    // 가운데 값을 1씩 줄이면서 탐색
    for (int i=idx;i>=3;i--){
        // temp 배열에 왼쪽, 가운데, 오른쪽 값이 차례로 들어감
        int temp[4];
        temp[0]=0;
        temp[1]=(arr[i]-i)/2;
        temp[2]=temp[1]+i;
        temp[3]=arr[i];
        for (int j=1;j<4;j++){
            if (temp[j]>N){
                if (j==2){
                    if (N-temp[1]==0){
                        cout << "m";
                        exit(0);
                    }
                    else{
                        cout << "o";
                        exit(0);
                    }
                } 
                N=N-temp[j-1];
                if (N<3){
                    cout << DAT[N];
                    exit(0);
                }
                break;
            }
        }
    }
}