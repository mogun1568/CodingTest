#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001];
int result[1000001];

void dfs(int node, int preNode) {
    for (auto t : tree[node]) {
        if (t != preNode) {
            result[t] = node;
            dfs(t, node);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(1, 0);

    for (int i = 2; i <= n; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}