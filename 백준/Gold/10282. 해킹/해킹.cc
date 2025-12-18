#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

vector<pair<int, int>> dependence[10001];
int hackingTime[10001];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        dependence[i].clear();
        hackingTime[i] = INF;
    }   
}

void dijkstra(int c) {
    int cnt = 1, hTime = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    hackingTime[c] = 0;
    pq.push({0, c});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cTime = pq.top().first;
        pq.pop();

        if (cTime > hackingTime[cur])
            continue;

        hTime = cTime;

        for (int i = 0; i < dependence[cur].size(); i++) {
            int next = dependence[cur][i].first;
            int nTime = cTime + dependence[cur][i].second;

            if (nTime >= hackingTime[next])
                continue;

            if (hackingTime[next] == INF)
                cnt++;

            hackingTime[next] = nTime;
            pq.push({nTime, next});
        }
    }

    cout << cnt << " " << hTime << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, d, c;
        cin >> n >> d >> c;

        init(n);
        
        int a, b, s;
        while (d--) {
            cin >> a >> b >> s;
            dependence[b].push_back({a, s});
        }

        dijkstra(c);
    }
    
    return 0;
}