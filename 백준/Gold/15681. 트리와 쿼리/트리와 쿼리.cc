#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001];
bool visited[100001];
int dp[100001];

int Dfs(int u) {
    for (int i = 0; i < tree[u].size(); i++) {
        if (visited[tree[u][i]]) {
            continue;
        }

        visited[tree[u][i]] = true;
        dp[u] += Dfs(tree[u][i]);
    }

    return dp[u];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, r, q, u, v;
    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
    }
    
    visited[r] = true;
    Dfs(r);

    for (int i = 0; i < q; i++) {
        cin >> u;
        cout << dp[u] << "\n";
    }
    
    return 0;
}