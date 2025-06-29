#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int farNode, ans;
vector<pair<int, int>> tree[10001];
bool visited[10001];

void Bfs(int a) {
    ans = 0;
    memset(visited, false, sizeof(visited));
    
    queue<pair<int, int>> q;
    visited[a] = true;
    q.push({a, 0});

    while (!q.empty()) {
        int ca = q.front().first;
        int cw = q.front().second;
        q.pop();

        if (cw > ans) {
            farNode = ca;
            ans = cw;
        }

        for (int i = 0; i < tree[ca].size(); i++) {
            int na = tree[ca][i].first;
            int nw = cw + tree[ca][i].second;

            if (visited[na])
                continue;

            visited[na] = true;
            q.push({na, nw});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, a, b, c;
    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    Bfs(1);
    Bfs(farNode);

    cout << ans;
    
    return 0;
}