#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 50001

int N, M;
int dist[MAX];
vector<pair<int, int>> v[MAX];

void Dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    pq.push({1, 0});

    while (!pq.empty()) {
        int cur = pq.top().first;
        int cow = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nCow = cow + v[cur][i].second;

            if (nCow < dist[next]) {
                dist[next] = nCow;
                pq.push({next, nCow});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (int i = 0; i < MAX; i++) {
        dist[i] = 987654321;
    }

    Dijkstra();

    cout << dist[N];
    
    return 0;
}