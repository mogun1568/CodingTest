#include <iostream>
#include <queue>

using namespace std;

int a, b, c;
bool liter[201];
bool visited[201][201];

struct bucket {
    int a, b, c;
};

void bfs() {
    queue<bucket> q;
    visited[a][b] = true;
    q.push({0, 0, c});

    while (!q.empty()) {
        int ca = q.front().a;
        int cb = q.front().b;
        int cc = q.front().c;
        q.pop();

        if (visited[ca][cb]) {
            continue;
        }
        visited[ca][cb] = true;

        if (ca == 0) {
            liter[cc] = true;
        }

        // a -> b
        if (ca + cb > b) {
            q.push({ca + cb - b, b, cc});
        } else {
            q.push({0, ca + cb, cc});
        }

        // a -> c
        if (ca + cc > c) {
            q.push({ca + cc - c, cb, c});
        } else {
            q.push({0, cb, ca + cc});
        }

        // b -> a
        if (ca + cb > a) {
            q.push({a, ca + cb - a, cc});
        } else {
            q.push({ca + cb, 0, cc});
        }

        // b -> c
        if (cb + cc > c) {
            q.push({ca, cb + cc - c, c});
        } else {
            q.push({ca, 0, cb + cc});
        }

        // c -> a
        if (ca + cc > a) {
            q.push({a, cb, ca + cc - a});
        } else {
            q.push({ca + cc, cb, 0});
        }

        // c -> b
        if (cb + cc > b) {
            q.push({ca, b, cb + cc - b});
        } else {
            q.push({ca, cb + cc, 0});
        }  
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b >> c;

    bfs();

    for (int i = 0; i <= c; i++) {
        if (liter[i]) {
            cout << i << " ";
        }
    }
    
    return 0;
}