#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, answer;
vector<pair<int, int>> cpt[1001];
bool visited[1001];

void Dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int cc = pq.top().second;
        int cp = pq.top().first;
        pq.pop();

        if (visited[cc])
            continue;
        
        visited[cc] = true;
        answer += cp;

        for (int i = 0; i < cpt[cc].size(); i++) {
            int nc = cpt[cc][i].first;
            int np = cpt[cc][i].second;

            if (visited[nc])
                continue;

            pq.push({np, nc});
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
        cpt[a].push_back({b, c});
        cpt[b].push_back({a, c});
    }

    Dijkstra();

    cout << answer;
    
    return 0;
}