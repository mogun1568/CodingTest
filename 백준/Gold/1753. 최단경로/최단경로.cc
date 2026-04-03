#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 2e9;

vector<pair<int, int>> graph[20001];
int visited[20001];

void dijkstra(int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    visited[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (w > visited[cur])
            continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nw = w + graph[cur][i].second;

            if (nw < visited[next]) {
                visited[next] = nw;
                pq.push({nw, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int V, E, K;
    cin >> V >> E >> K;

    int u, v, w;
    while (E--) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    for (int i = 1; i <= V; i++)
        visited[i] = INF;

    dijkstra(K);

    for (int i = 1; i <= V; i++) {
        if (visited[i] == INF) cout << "INF";
        else cout << visited[i];
        cout << "\n";
    }
    
    return 0;
}