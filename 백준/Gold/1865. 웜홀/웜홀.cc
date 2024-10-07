#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int TC, N, M, W;
vector<pair<pair<int, int>, int>> road;
int dist[501];

bool Bellmanford() {
    for (int i = 1; i <= N; i++)
        dist[i] = INF;

    dist[1] = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < road.size(); j++) {
            int s = road[j].first.first;
            int e = road[j].first.second;
            int t = road[j].second;

            if (dist[e] > dist[s] + t) {
                dist[e] = dist[s] + t;
            }
        }
    }

    for (int i = 0; i < road.size(); i++) {
        int s = road[i].first.first;
        int e = road[i].first.second;
        int t = road[i].second;

        if (dist[e] > dist[s] + t)
            return true;
    }

    return false;
}

int main() {
    cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;

        road.clear();
        int s, e, t;
        for (int i = 0; i < M; i++) {
            cin >> s >> e >> t;
            road.push_back({{s, e}, t});
            road.push_back({{e, s}, t});
        }
        for (int i = 0; i < W; i++) {
            cin >> s >> e >> t;
            road.push_back({{s, e}, -t});
        }

        if (Bellmanford())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}