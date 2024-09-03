#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, maxCost, answer;
vector<pair<int, int>> roads[100001];
bool visited[100001];

void Bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cCost = pq.top().first;
        pq.pop();

        if (visited[cur])
            continue;

        visited[cur] = true;
        answer += cCost;
        maxCost = max(maxCost, cCost);

        for (int i = 0; i < roads[cur].size(); i++) {
            int next = roads[cur][i].first;
            int nCost = roads[cur][i].second;

            pq.push({nCost, next});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        roads[a].push_back({b, c});
        roads[b].push_back({a, c});
    }

    Bfs();

    cout << answer - maxCost;
    
    return 0;
}