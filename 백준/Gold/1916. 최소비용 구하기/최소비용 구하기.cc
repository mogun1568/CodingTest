#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dp[1001];
vector<pair<int, int>> road[1001];

void bfs(int start) {
    priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (cost > dp[cur]) {
            continue;
        }

        for (int i = 0; i < road[cur].size(); i++) {
            int next = road[cur][i].first;
            int nCost = dp[cur] + road[cur][i].second;

            if (nCost >= dp[next]) {
                continue;
            }

            dp[next] = nCost;
            pq.push({nCost, next});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, a, b, c, start, arrival;
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        road[a].push_back({b, c});
    }
    cin >> start >> arrival;

    fill_n(dp, 1001, 200000000);
    
    dp[start] = 0;
    bfs(start);

    cout << dp[arrival];
    
    return 0;
}