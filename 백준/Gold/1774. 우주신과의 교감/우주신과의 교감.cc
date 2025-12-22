#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

vector<pair<long long, pair<int, int>>> channels;
int parent[1001];

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

    parent[y] = x;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> v;
    int X, Y;
    for (int i = 1; i <= N; i++) {
        cin >> X >> Y;
        v.push_back({X, Y});
        parent[i] = i;
    }

    long long dis;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            long long llx = (long long)v[j].first - v[i].first;
            long long lly = (long long)v[j].second - v[i].second;
            dis = llx * llx + lly * lly;
            channels.push_back({dis, {i + 1, j + 1}});
        }
    }
    sort(channels.begin(), channels.end());
    
    while (M--) {
        cin >> X >> Y;
        merge(X, Y);
    }

    double ans = 0.0;
    for (auto ch : channels) {
        dis = ch.first;
        X = ch.second.first;
        Y = ch.second.second;

        if (!merge(X, Y))
            continue;

        ans += sqrt(dis);
    }

    printf("%.2f", ans);
    
    return 0;
}