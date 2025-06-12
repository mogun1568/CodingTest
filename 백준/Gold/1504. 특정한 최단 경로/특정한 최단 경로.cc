#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 64000000

int N;
vector<pair<int, int>> graph[801];
int visited[801];

void Clear() {
    for (int i = 1; i <= N; i++)
        visited[i] = MAX;
}

void BFS(int start) {
    Clear();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    visited[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int a = pq.top().second;
        int c = pq.top().first;
        pq.pop();

        if (c > visited[a])
            continue;

        for (int i = 0; i < graph[a].size(); i++) {
            int b = graph[a][i].first;
            int nc = c + graph[a][i].second;

            if (nc > visited[b])
                continue;

            visited[b] = nc;
            pq.push({nc, b});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int E, a, b, c, v1, v2;
    cin >> N >> E;
    while (E--) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    BFS(1);
    int oneTov1 = visited[v1];
    int oneTov2 = visited[v2];

    BFS(v1);
    int v1Tov2 = visited[v2];
    int v1ToN = visited[N];

    BFS(v2);
    int v2ToN = visited[N];

    int ans = MAX;
    ans = min(ans, oneTov1 + v1Tov2 + v2ToN);
    ans = min(ans, oneTov2 + v1Tov2 + v1ToN);

    if (ans == MAX)
        cout << -1;
    else
        cout << ans;
    
    return 0;
}