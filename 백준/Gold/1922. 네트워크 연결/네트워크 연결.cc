#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<pair<int, int>> cpt[1001];
bool visited[1001];

int Dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    int ans = 0;

    while (!pq.empty()) {
        int a = pq.top().second;
        int cc = pq.top().first;
        pq.pop();

        if (visited[a])
            continue;
        
        visited[a] = true;
        ans += cc;

        for (int i = 0; i < cpt[a].size(); i++) {
            int b = cpt[a][i].first;
            int nc = cpt[a][i].second;

            if (visited[b])
                continue;

            pq.push({nc, b});
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    int a, b, c;
    while (M--) {
        cin >> a >> b >> c;
        cpt[a].push_back({b, c});
        cpt[b].push_back({a, c});
    }

    cout << Dijkstra();
    
    return 0;
}