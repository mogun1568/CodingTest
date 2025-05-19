#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 100000000

vector<pair<int, int>> bus[1001];
int city[1001];

void Dijkstra(int s) {
    priority_queue<pair<int, int>> pq;
    city[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int cs = pq.top().second;
        int cc = pq.top().first;
        pq.pop();

        if (cc > city[cs])
            continue;

        for (int i = 0; i < bus[cs].size(); i++) {
            int ce = bus[cs][i].first;
            int nc = cc + bus[cs][i].second;

            if (nc >= city[ce])
                continue;

            city[ce] = nc;
            pq.push({nc, ce});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, s, e, c;
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> s >> e >> c;
        bus[s].push_back({e, c});
    }
    cin >> s >> e;

    for (int i = 1; i <= N; i++)
        city[i] = INF;
    
    Dijkstra(s);

    cout << city[e];
    
    return 0;
}