#include <iostream>
#include <string>

using namespace std;
string str;
bool isVisble[101] = { false, };

void printLine() {
    for (int i=0; i < 101; i++){
        if (isVisble[i]) cout << str[i];
    }
    cout << "\n";
}

void findNext(int st, int ed) {
    int nextMin = st;
    for(int i=st; i < ed; i++) if(str[nextMin] > str[i]) nextMin = i;

    isVisble[nextMin] = true;
    printLine();

    if (nextMin+1 < ed) findNext(nextMin+1, ed);
    if (nextMin-1 >= st) findNext(st, nextMin);
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> str;
    int MAX_SIZE = str.length();
    int cur = 0;

    for(int i=0; i < MAX_SIZE; i++){
        if (str[cur] > str[i]) cur = i;
    }

    isVisble[cur] = true;
    printLine();

    //제일 빠른 알파벳이 맨 앞에 오래 있어야 하므로 cur ~ end 먼저 돌기
    if (cur+1 < MAX_SIZE) findNext(cur+1, MAX_SIZE);
    if (cur-1 >= 0) findNext(0, cur);

    return 0;
}
