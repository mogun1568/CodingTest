#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree[1000001];
int DP[1000001][2];
bool visited[1000001];

void DFS(int cur) {
    visited[cur] = true;
    DP[cur][0] = 1;

    for (int i = 0; i < tree[cur].size(); i++) {
        int child = tree[cur][i];
        if (visited[child])
            continue;

        DFS(child);
        DP[cur][0] += min(DP[child][0], DP[child][1]);
        DP[cur][1] += DP[child][0];
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while (N--) {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    DFS(1);

    cout << min(DP[1][0], DP[1][1]); 
        
    return 0;
}