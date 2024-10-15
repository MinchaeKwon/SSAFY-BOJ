// 1525 퍼즐
// 그냥 해싱과 unordered_set을 잘 써서 BFS
#include <bits/stdc++.h>
using namespace std;

int hf(int *arr) {
    int ret = 0;
    for (int i  = 0; i < 9; i++) ret = ret * 10 + arr[i];
    return ret;
}

int main() {
    const int dest = 123456780;
    int S = 0;
    for (int i = 0; i < 9; i++) {
        int x; cin >> x;
        S =  S * 10 + x;
    }

    queue<int> q;
    unordered_set<int> vis;
    q.push(S);
    vis.insert(S);
    int sz = 1;

    int arr[9] = {0,};
    for (int t = 0; sz > 0; t++) {
        while (sz--) {
            int cur = q.front();
            q.pop();

            if (cur == dest) {
                cout << t << '\n';
                return 0;
            }

            int idx = 9, zi = -1;
            while (idx--) {
                arr[idx] = cur % 10, cur /= 10;
                if (!arr[idx]) zi = idx;
            }
            
            if (zi % 3 > 0) {
                swap(arr[zi], arr[zi - 1]);
                int h = hf(arr);
                if (!vis.count(h)) {
                    q.push(h);
                    vis.insert(h);
                }
                swap(arr[zi], arr[zi - 1]);
            }
            if (zi % 3 < 2)  {
                swap(arr[zi], arr[zi + 1]);
                int h = hf(arr);
                if (!vis.count(h)) {
                    q.push(h);
                    vis.insert(h);
                }
                swap(arr[zi], arr[zi + 1]);
            }
            if (zi / 3 > 0) {
                swap(arr[zi], arr[zi - 3]);
                int h = hf(arr);
                if (!vis.count(h)) {
                    q.push(h);
                    vis.insert(h);
                }
                swap(arr[zi], arr[zi - 3]);
            }
            if (zi / 3 < 2) {
                swap(arr[zi], arr[zi + 3]);
                int h = hf(arr);
                if (!vis.count(h)) {
                    q.push(h);
                    vis.insert(h);
                }
                swap(arr[zi], arr[zi + 3]);
            }
        }
        sz = q.size();
    }

    cout << -1 << '\n';
}