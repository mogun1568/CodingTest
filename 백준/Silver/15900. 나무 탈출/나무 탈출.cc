#include <iostream>
#include <vector>

using namespace std;

int result;
vector<int> tree[500001];
bool visited[500001];

void dfs(int a, int cnt) {
    if (tree[a].size() == 1) {
        result += cnt;
    }

    for (auto t : tree[a]) {
        if (visited[t]) {
            continue;
        }

        visited[t] = true;
        dfs(t, cnt + 1);
        visited[t] = false;
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

    visited[1] = true;
    dfs(1, 0);

    if (result % 2 != 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    
    return 0;
}