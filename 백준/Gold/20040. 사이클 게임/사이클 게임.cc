#include <iostream>

using namespace std;

int N, M;
int parent[500000];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);

    // 이미 같은 집합이면 중복 선분이 아닌 이상 사이클이 될 수 밖에 없음
    if (x == y)
        return true;
	else if (x < y)
        parent[y] = x;
	else
        parent[x] = y;

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    int x, y;
    for (int i = 1; i <= M; i++) {
        cin >> x >> y;

        if (Union(x, y)) {
            cout << i;
            return 0;
        }
    }

    cout << 0;
    
    return 0;
}