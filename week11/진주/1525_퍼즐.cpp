#include <iostream>
#include <queue>
#include <map>
using namespace std;
const int MAP = 3;
// 3*3 에서 인접한 곳 움직이면서 최종 상태가 123456780과 일치하는 경우 
// 그 중에서 최소 길이를 찾는다
// BFS 탐색으로 최단 경로 찾기 -> 최소 이동 수를 만족
// + 메모리를 아끼기 위해 3*3의 퍼즐 형태를 string으로 저장

int grid[3][3];
map<string, int> ret;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool rangeCheck(int r, int c) {
    if(0<=r && r<MAP && 0<=c && c<MAP) return true;
    else return false;
}

int bfs(string nowS) {
    queue<string> Q;
    Q.push(nowS);

    while(!Q.empty()) {
        string tmp = Q.front();
        Q.pop();

        // 종료 조건, bfs 최단거리
        if(tmp == "123456780") {
            return ret[tmp];
        }

        auto blankPos = tmp.find('0');
        for(int i=0; i<4; i++) {
            int nr = (blankPos/3) + dr[i];
            int nc = (blankPos%3) + dc[i];

            if(rangeCheck(nr, nc)) {
                string nxt = tmp;
                swap(nxt[blankPos], nxt[nr*3+nc]);
                if(!ret[nxt]) {
                    ret[nxt] = ret[tmp]+1; //이동 수 map에 저장
                    Q.push(nxt);
                }
            }
        }
    }
    return -1; //불가능
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    string S = "";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
            S += ('0'+grid[i][j]); //문자열 형식으로 추가
        }
    }
    ret[S] = 0;
    //cout << S << "\n";
    cout << bfs(S);
    return 0;
}
