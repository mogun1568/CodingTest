#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[200001];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return false;
    else
        parent[y] = x;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, pair<int, int>>> roads;
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        roads.clear();
        int x, y, z, ans = 0;
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> z;
            roads.push_back({z, {x, y}});
            ans += z;
        }
        sort(roads.begin(), roads.end());

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int a, b, c;
        for (int i = 0; i < m; i++) {
            a = roads[i].second.first;
            b = roads[i].second.second;
            c = roads[i].first;

            if (merge(a, b))
                ans -= c;       
        }

        cout << ans << "\n";
    }
    
    return 0;
}