#include <iostream>

using namespace std;

int r, c, k, result;
char map[6][6];
bool visited[6][6];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int cr, int cc, int cnt) {
    if (cr == 1 && cc == c) {        
        if (cnt == k) {
            result++;
        }
        
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nr = cr + dr[i];
        int nc = cc + dc[i];

        if (nr < 1 || nr > r || nc < 1 || nc > c) {
            continue;
        }

        if (visited[nr][nc] || map[nr][nc] == 'T') {
            continue;
        }

        
        visited[nr][nc] = true;
        dfs(nr, nc, cnt + 1);
        visited[nr][nc] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c >> k;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> map[i][j];
        }
    }

    visited[r][1] = true;
    dfs(r, 1, 1);

    cout << result;
    
    return 0;
}