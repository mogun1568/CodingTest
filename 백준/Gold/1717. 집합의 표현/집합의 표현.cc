#include <iostream>
using namespace std;

int parent[1000001];

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

    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i <= N; i++)
        parent[i] = i;

    int o, a, b;
    while (M--) {
        cin >> o >> a >> b;

        if (!o)
            Union(a, b);
        else {
            if (Find(a) == Find(b))
                cout << "YES";
            else
                cout << "NO";
            cout << "\n";
        }
    }
    
    return 0;
}