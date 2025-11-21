#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 3000000

vector<pair<int, int>> edge[20001];
int weight[20001];

void Dijkstra(int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    weight[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        
        if (weight[u] < w)
            continue;

        for (int i = 0; i < edge[u].size(); i++) {
            int v = edge[u][i].first;
            int nw = w + edge[u][i].second;

            if (weight[v] <= nw)
                continue;

            weight[v] = nw;
            pq.push({nw, v});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int V, E, K, u, v, w;
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }

    for (int i = 1; i <= V; i++)
        weight[i] = INF;

    Dijkstra(K);

    for (int i = 1; i <= V; i++) {
        if (weight[i] == INF)
            cout << "INF";
        else
            cout << weight[i];
        cout << "\n";
    }
    
    return 0;
}