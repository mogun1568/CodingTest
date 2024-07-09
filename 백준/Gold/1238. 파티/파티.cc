#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, X, answer;
vector<pair<int, int>> v[1001];
int visited[1001];

void Init() {
    for (int i = 1; i <= N; i++)
        visited[i] = 1000000;
}

int Dijkstra(int start, int end) {
    Init();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    visited[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int ct = pq.top().first;
        int cv = pq.top().second;
        pq.pop();

        if (cv == end)
            return ct;

        for (int i = 0; i < v[cv].size(); i++) {
            int nt = ct + v[cv][i].second;
            int nv = v[cv][i].first;

            if (nt >= visited[nv])
                continue;

            visited[nv] = nt;
            pq.push({nt, nv});
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> X;

    int a, b, t;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> t;
        v[a].push_back({b, t});
    }

    int time;
    for (int i = 1; i <= N; i++) {
        time = Dijkstra(i, X);
        time += Dijkstra(X, i);

        answer = max(answer, time);
    }

    cout << answer;
    
    return 0;
}