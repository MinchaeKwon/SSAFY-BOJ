#include <bits/stdc++.h>

using namespace std;

int N, M, parent[1001];
char school[1001];
typedef struct Edge{
    int from;
    int to;
    int weight;
};
vector<Edge> v;

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findparent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = findparent(parent[node]);
}

void Union(int a, int b) {
    int A = findparent(a);
    int B = findparent(b);
    parent[A] = B;
}

int main()
{
    cin >> N >> M;
    for (int i = 1;i <= N;i++) {
        cin >> school[i];
        parent[i] = i;
    }
    for (int i = 0;i < M;i++) {
        int from, to, w;
        cin >> from >> to >> w;
        v.push_back({ from,to,w });
    }
    sort(v.begin(), v.end(),cmp);
    int edgeCnt = 0;
    int weightSum = 0;
    for (auto i : v) {
        if (school[i.from] == school[i.to]) continue;
        if (findparent(i.from) == findparent(i.to)) continue;
        Union(i.from, i.to);
        weightSum += i.weight;
        edgeCnt++;
    }
    if (edgeCnt != N - 1) cout << -1;
    else cout << weightSum;
}