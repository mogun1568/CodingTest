#include <iostream>
using namespace std;

int parent[100001];

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

    int G, P;
    cin >> G >> P;

    for (int i = 1; i <= G; i++)
        parent[i] = i;

    int g, ans = 0;
    bool isFull = false;
    for (int i = 0; i < P; i++) {
        cin >> g;

        if (isFull)
            continue;

        int x = Find(g);
        if (x == 0) {
            isFull = true;
            continue;
        }

        Merge(x, x - 1);
        ans++;
    }

    cout << ans;
    
    return 0;
}