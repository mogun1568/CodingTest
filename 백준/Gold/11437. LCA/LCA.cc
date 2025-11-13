#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[50001];
int depth[50001];
int parent[50001];
bool visited[50001];

void DFS(int node, int d) {
    depth[node] = d;
    visited[node] = true;

    for (const auto& next : tree[node]) {
        if (visited[next])
            continue;

        parent[next] = node;
        DFS(next, d + 1);
    }
}

int LCA(int a, int b) {
    // 깊이 맞추기
    while (depth[a] != depth[b]) {
        if (depth[a] > depth[b])
            a = parent[a];
        else
            b = parent[b];
    }

    // 부모 맞추기
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    DFS(1, 0);

    int M;
    cin >> M;
    while (M--) {
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
    
    return 0;
}