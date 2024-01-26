#include <iostream>
#include <queue>

using namespace std;

int m, n;
bool banner[250][250];

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                continue;
            }

            if (!banner[nr][nc]) {
                continue;
            }

            banner[nr][nc] = false;
            q.push({nr, nc});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int cnt = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> banner[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (banner[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;
    
    return 0;
}