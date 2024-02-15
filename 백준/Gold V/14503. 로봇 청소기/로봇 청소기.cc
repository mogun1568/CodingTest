#include <iostream>

using namespace std;

int n, m, result;
int room[50][50];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(int r, int c, int d, int cnt) {
    bool check = false;
    for (int i = 3; i >= 0; i--) {
        int nd = (d + i) % 4;
        int nr = r + dr[nd];
        int nc = c + dc[nd];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
            continue;
        }

        if (room[nr][nc] != 0) {
            continue;
        }

        check = true;
        room[nr][nc] = 2;
        dfs(nr, nc, nd, cnt + 1);
        return;
    }

    if (!check) {
        int nd = (d + 2) % 4;
        int nr = r + dr[nd];
        int nc = c + dc[nd];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m && room[nr][nc] != 1) {
            dfs(nr, nc, d, cnt);
        } else {
            result = cnt;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int r, c, d;
    cin >> n >> m >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    room[r][c] = 2;
    dfs(r, c, d, 1);
    
    cout << result;
    
    return 0;
}