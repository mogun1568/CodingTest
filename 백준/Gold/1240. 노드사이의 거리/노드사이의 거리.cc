#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int, int>> tree[1001];
bool visited[1001];

int Bfs(int sn, int en) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    visited[sn] = true;
    q.push({sn, 0});

    int cnt = 0;
    while (!q.empty()) {
        int cn = q.front().first;
        int cc = q.front().second;
        q.pop();

        if (cn == en) {
            cnt = cc;
            break;
        }
        
        for (int i = 0; i < tree[cn].size(); i++) {
            int nn = tree[cn][i].first;
            int nc = cc + tree[cn][i].second;

            if (visited[nn]) {
                continue;
            }

            visited[nn] = true;
            q.push({nn, nc});
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, a, b, d;
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> d;
        tree[a].push_back({b, d});
        tree[b].push_back({a, d});
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << Bfs(a, b) << "\n";
    }
    
    return 0;
}