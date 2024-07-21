#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, farNode, answer;
vector<pair<int, int>> tree[10001];
bool visited[10001];

void Bfs(int a) {
    answer = 0;
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    visited[a] = true;
    q.push({a, 0});

    while (!q.empty()) {
        int ca = q.front().first;
        int cw = q.front().second;
        q.pop();

        if (cw > answer) {
            farNode = ca;
            answer = cw;
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
    
    cin >> N;

    int a, b, c;
    for (int i = 1; i < N; i++) {
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    Bfs(1);
    Bfs(farNode);

    cout << answer;
    
    return 0;
}