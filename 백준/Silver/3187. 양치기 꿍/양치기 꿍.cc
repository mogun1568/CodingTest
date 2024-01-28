#include <iostream>
#include <string>
#include <queue>

using namespace std;

int R, C, sheep, wolf;
char area[250][250];
bool visited[250][250];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs(int r, int c) {
    int k = 0, v = 0;
    queue<pair<int, int>> q;
    visited[r][c] = true;
    q.push({r, c});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        if (area[cr][cc] == 'k') {
            k++;
        } else if (area[cr][cc] == 'v') {
            v++;
        }
        
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                continue;
            }

            if (area[nr][nc] == '#' || visited[nr][nc]) {
                continue;
            }

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    if (k > v) {
        sheep += k;
    } else {
        wolf += v;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C;

    string s;
    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < C; j++) {
            area[i][j] = s[j];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (area[i][j] == '#' || visited[i][j]) {
                continue;
            }

            bfs(i, j);
        }
    }
    
    cout << sheep << " " << wolf;
    
    return 0;
}