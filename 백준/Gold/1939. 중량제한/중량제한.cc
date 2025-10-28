#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001];
vector<pair<int, pair<int, int>>> v;

int Find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}

void Merge(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int A, B, C;
    while (M--) {
        cin >> A >> B >> C;
        v.push_back({C, {A, B}});
    }
    sort(v.begin(), v.end(), greater<>());
    
    cin >> A >> B;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < v.size(); i++) {
        int a = v[i].second.first;
        int b = v[i].second.second;
        int c = v[i].first;

        Merge(a, b);

        if (Find(A) == Find(B)) {
            cout << c;
            break;
        }
    }
    
    return 0;
}