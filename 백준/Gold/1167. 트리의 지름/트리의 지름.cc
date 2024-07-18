#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int V, answer, farNode;
vector<pair<int, int>> tree[100001];
bool visited[100001];

void Bfs(int a) {
    answer = 0;
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    visited[a] = true;
    q.push({a, 0});

    while (!q.empty()) {
        int ca = q.front().first;
        int cc = q.front().second;
        q.pop();

        if (cc > answer) {
            answer = cc;
            farNode = ca;
        }
        
        for (int i = 0; i < tree[ca].size(); i++) {
            int na = tree[ca][i].first;
            int nc = cc + tree[ca][i].second;

            if (visited[na])
                continue;

            visited[na] = true;
            q.push({na, nc});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> V;

    int a, b, c;
    for (int i = 0; i < V; i++) {
        cin >> a;
        while(1) {
            cin >> b;
            if (b == -1)
                break;
            cin >> c;

            tree[a].push_back({b, c});
        }
    }

    Bfs(1);
    Bfs(farNode);

    cout << answer;
    
    return 0;
}