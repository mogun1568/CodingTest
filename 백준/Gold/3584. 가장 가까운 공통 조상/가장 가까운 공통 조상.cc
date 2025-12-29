#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10001;

vector<int> tree[MAX];
int depth[MAX];
int parent[MAX];
bool visited[MAX];

void init(int N) {
    for (int i = 1; i <= N; i++) {
        tree[i].clear();
        parent[i] = 0;
        visited[i] = false;
    }
}

void DFS(int node, int d) {
    depth[node] = d;
    
    for (const auto& next : tree[node])
        DFS(next, d + 1);
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

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        init(N);
    
        int a, b;
        for (int i = 0; i < N - 1; i++) {
            cin >> a >> b;
            tree[a].push_back(b);
            parent[b] = a;
        }

        for (int i = 1; i <= N; i++) {
            if (parent[i] == 0) {
                DFS(i, 0);
                break;
            }
        }
    
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
    
    return 0;
}