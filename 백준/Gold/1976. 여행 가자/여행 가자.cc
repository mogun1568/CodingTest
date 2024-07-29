#include <iostream>

using namespace std;

int N, M;
int parent[201];

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

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int x, root;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> x;

            if (x == 1)
                Union(i, j);
        }
    }

    cin >> x;
    root = Find(x);
    for (int i = 1; i < M; i++) {
        cin >> x;

        if (root != Find(x)) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    
    return 0;
}