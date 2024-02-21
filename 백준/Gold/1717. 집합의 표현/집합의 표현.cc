#include <iostream>

using namespace std;

int parent[1000001];

int find(int x) {
	if (parent[x] == x) {
		return x;
    }

	parent[x] = find(parent[x]);

	return parent[x];
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) {
        return;
    }
    
	parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, c, a, b;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }


    for (int i = 0; i < m; i++) {
        cin >> c >> a >> b;

        if (c == 0) {
            merge(a, b);
        } else {
            if (find(a) == find(b)) {
				cout << "YES\n";
            }
			else {
				cout << "NO\n";
            }
        }
    }

    return 0;
}