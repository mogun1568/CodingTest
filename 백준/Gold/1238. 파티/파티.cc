#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, X, ans;
vector<pair<int, int>> v[2][1001];
int visited[2][1001];

void Dijkstra(int dir) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    visited[dir][X] = 0;
    pq.push({0, X});

    while (!pq.empty()) {
        int a = pq.top().second;
        int t = pq.top().first;
        pq.pop();

        if (t > visited[dir][a])
            continue;

        for (int i = 0; i < v[dir][a].size(); i++) {
            int b = v[dir][a][i].first;
            int nt = t + v[dir][a][i].second;

            if (nt >= visited[dir][b])
                continue;

            visited[dir][b] = nt;
            pq.push({nt, b});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, a, b, t;
    cin >> N >> M >> X;
    
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> t;
        v[0][a].push_back({b, t});
        v[1][b].push_back({a, t});
    }

    for (int i = 1; i <= N; i++) {
        visited[0][i] = 1000000;
        visited[1][i] = 1000000;
    }

    Dijkstra(0);
    Dijkstra(1);

    int time;
    for (int i = 1; i <= N; i++) {
        time = visited[0][i] + visited[1][i];
        ans = max(ans, time);
    }

    cout << ans;
    
    return 0;
}