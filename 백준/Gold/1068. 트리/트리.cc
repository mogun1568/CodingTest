#include <iostream>
#include <vector>

using namespace std;

int e, cnt;
vector<int> tree[51];

void dfs(int node) {
    if (node == e) {
        return;
    }

    if (tree[node].size() == 0) {
        cnt++;
        return;
    }

    for (int i = 0; i < tree[node].size(); i++) {
        if (tree[node][i] == e && tree[node].size() == 1) {
            cnt++;
            continue;
        }

        dfs(tree[node][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, r, p;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;
        if (p == -1) {
            r = i;
            continue;
        } 
        tree[p].push_back(i);
    }
    cin >> e;

    dfs(r);

    cout << cnt;

    return 0;
}