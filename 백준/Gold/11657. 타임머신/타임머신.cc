#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int N, M;
long long dist[501];
vector<pair<int, int>> edge[501];
bool cycle;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }

    for (int i = 2; i <= N; i++) {
        dist[i] = INF;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < edge[j].size(); k++) {
                if (dist[j] == INF)
                    continue;
    
                int next = edge[j][k].first;
                int nd = edge[j][k].second;
                
                if (dist[next] <= dist[j] + nd)
                    continue;

                dist[next] = dist[j] + nd;
                
                if (i == N) 
                    cycle = true;
            }
        }
    }

    if (cycle) {
        cout << -1;
        return 0;
    }

    for (int i = 2; i <= N; i++) {
        cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
    }
    
    return 0;
}