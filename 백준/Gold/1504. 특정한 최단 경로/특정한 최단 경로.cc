#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 987654321

int N, E, v1, v2, answer = MAX;
vector<pair<int, int>> graph[801];
int visited[801];

void Init() {
    for (int i = 1; i <= N; i++)
        visited[i] = MAX;
}

void Bfs(int start) {
    Init();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    visited[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cp = pq.top().second;
        int cd = pq.top().first;
        pq.pop();

        if (cd > visited[cp])
            continue;

        for (int i = 0; i < graph[cp].size(); i++) {
            int np = graph[cp][i].first;
            int nd = cd + graph[cp][i].second;

            if (nd > visited[np])
                continue;

            visited[np] = nd;
            pq.push({nd, np});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c;
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    if (E == 0) {
        cout << -1;
        return 0;
    }

    Bfs(1);
    int oneTov1 = visited[v1];
    int oneTov2 = visited[v2];

    Bfs(v1);
    int v1Tov2 = visited[v2];
    int v1ToN = visited[N];

    Bfs(v2);
    int v2ToN = visited[N];
 
    answer = min(answer, oneTov1 + v1Tov2 + v2ToN);
    answer = min(answer, oneTov2 + v1Tov2 + v1ToN);

    if (answer == MAX)
        cout << -1;
    else
        cout << answer;
    
    return 0;
}