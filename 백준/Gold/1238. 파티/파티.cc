#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, X, answer;
vector<pair<int, int>> v[2][1001];
int visited[2][1001];

void Dijkstra(int dir) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    visited[dir][X] = 0;
    pq.push({0, X});

    while (!pq.empty()) {
        int ct = pq.top().first;
        int cv = pq.top().second;
        pq.pop();

        if (ct > visited[dir][cv])
            continue;

        for (int i = 0; i < v[dir][cv].size(); i++) {
            int nt = ct + v[dir][cv][i].second;
            int nv = v[dir][cv][i].first;

            if (nt >= visited[dir][nv])
                continue;

            visited[dir][nv] = nt;
            pq.push({nt, nv});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> X;

    int a, b, t;
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
        answer = max(answer, time);
    }

    cout << answer;
    
    return 0;
}