#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 3000000

int V, E, K;
vector<pair<int, int>> line[20001];
int path[20001];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    path[K] = 0;
    pq.push({0, K});

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        for (int i = 0; i < line[u].size(); i++) {
            int v = line[u][i].first;
            int nw = w + line[u][i].second;

            if (path[v] <= nw)
                continue;

            path[v] = nw;
            pq.push({nw, v});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> V >> E >> K;

    int u, v, w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        line[u].push_back({v, w});
    }

    for (int i = 1; i <= V; i++)
        path[i] = INF;

    dijkstra();

    for (int i = 1; i <= V; i++)
        if (path[i] == INF)
            cout << "INF\n";
        else
            cout << path[i] << "\n";
    
    return 0;
}