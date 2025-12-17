#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

vector<pair<int, int>> roads[2001];
int intersection[2001];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        roads[i].clear();
        intersection[i] = INF;
    }
}

void dijkstra(int s, int g, int h) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    intersection[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cDis = pq.top().first;
        pq.pop();

        if (cDis > intersection[cur])
            continue;

        for (int i = 0; i < roads[cur].size(); i++) {
            int next = roads[cur][i].first;
            int nDis = cDis + roads[cur][i].second;

            if (nDis >= intersection[next])
                continue;
            
            intersection[next] = nDis;
            pq.push({nDis, next});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m, t, s, g, h;
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        init(n);
        
        int a, b, d;
        while (m--) {
            cin >> a >> b >> d;

            d *= 2; 
            if ((a == g && b == h) || (a == h && b == g))
                d--; 

            roads[a].push_back({b, d});
            roads[b].push_back({a, d});
        }

        dijkstra(s, g, h);

        vector<int> ans;
        while(t--) {
            int x;
            cin >> x;

            if (intersection[x] != INF && intersection[x] % 2 != 0)
                ans.push_back(x);
        }
        sort(ans.begin(), ans. end());

        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
    }
    
    return 0;
}