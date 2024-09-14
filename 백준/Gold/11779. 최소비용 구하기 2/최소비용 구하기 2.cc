#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 987654321

int n, m, s, e;
vector<pair<int, int>> info[1001];
pair<int, int> bus[1001];

void Bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bus[s].first = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cc = pq.top().first;
        pq.pop();

        if (cc > bus[cur].first)
            continue;

        for (int i = 0; i < info[cur].size(); i++) {
            int next = info[cur][i].first;
            int nc = cc + info[cur][i].second;

            if (nc >= bus[next].first)
                continue;

            bus[next].first = nc;
            bus[next].second = cur;
            pq.push({nc, next});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        info[a].push_back({b, c});
    }
    cin >> s >> e;

    for (int i = 1; i <= 1000; i++) {
        bus[i].first = MAX;
    }

    Bfs();

    
    int cur = e;
    vector<int> v;
    v.push_back(cur);
    while (cur != s) {
        v.push_back(bus[cur].second);
        cur = bus[cur].second;
    }

    cout << bus[e].first << "\n";
    cout << v.size() << "\n";
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << " ";
    
    return 0;
}