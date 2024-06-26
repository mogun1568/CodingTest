#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;
long long answer;
vector<pair<int, int>> v[10001];
bool visited[10001];

void Bfs(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cn = pq.top().second;
        int cw = pq.top().first;
        pq.pop();

        if (visited[cn])
            continue;
        
        visited[cn] = true;
        answer += cw;

        for (int i = 0; i < v[cn].size(); i++) {
            int nn = v[cn][i].first;
            int nw = v[cn][i].second;

            if (visited[nn])
                continue;

            pq.push({nw, nn});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> V >> E;

    int A, B, C;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        v[A].push_back({B, C});
        v[B].push_back({A, C});
    }

    Bfs(1);

    cout << answer;
    
    return 0;
}