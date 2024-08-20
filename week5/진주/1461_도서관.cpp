#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int book[10001] = { 0, };
int idx = 0;
int ret = 0;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> book[i];
        if (book[i] < 0)
            idx++; //음수일 때 인덱스 추가
    }

    sort(book, book+N);

    for (int i = N-1; i >= idx; i -= M) {
        ret += (book[i]*2); //양수 부터 M씩 줄어들게
    }

    for (int i = 0; i < idx; i += M) {
        ret += abs(book[i] * 2);
    }

    ret -= max(abs(book[0]), abs(book[N-1]));
    cout << ret << "\n";
    return 0;
}
