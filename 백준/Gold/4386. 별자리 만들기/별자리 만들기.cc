#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int parent[101];
vector<pair<double, pair<int, int>>> star;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    vector<pair<double, double>> v;
    double x, y, d;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        for (int j = 0; j < v.size(); j++) {
            d = sqrt(pow(x - v[j].first, 2) + pow(y - v[j].second, 2));
            d = floor(d * 100) / 100.0;
            star.push_back({d, {j + 1, i}});
        }
        v.push_back({x, y});
    }
    sort(star.begin(), star.end());

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    double answer = 0;
    for (int i = 0; i < star.size(); i++) {
        int a = star[i].second.first;
        int b = star[i].second.second;
        double c = star[i].first;

        if (Find(a) != Find(b)) {
            Union(a, b);
            answer += c;
        }
    }

    cout << answer;
    
    return 0;
}