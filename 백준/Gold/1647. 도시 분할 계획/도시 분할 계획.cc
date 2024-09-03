#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer;
int parent[100001];
vector<pair<int, pair<int, int>>> roads;

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
    
    cin >> N >> M;

    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        roads.push_back({c, {a, b}});
    }
    sort(roads.begin(), roads.end());

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int maxCost = 0;
    for (int i = 0; i < M; i++) {
        int a = roads[i].second.first;
        int b = roads[i].second.second;
        int c = roads[i].first;

        if (Find(a) != Find(b)) {
            Union(a, b);
            answer += c;
            maxCost = max(maxCost, c);
            
        }
    }

    cout << answer - maxCost;
    
    return 0;
}