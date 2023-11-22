#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int l, er, ec;
int dr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int board[300][300];
bool visit[300][300];

void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visit[r][c] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= l || nc < 0 || nc >= l) {
                continue;
            }

            if (!visit[nr][nc]) {
                q.push({nr, nc});
                board[nr][nc] = board[r][c] + 1;
                visit[nr][nc] = true;
            }

            if (nr == er && nc == ec) {
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, r, c;
    cin >> t;

    while (t--) {
        cin >> l >> r >> c >> er >> ec;

        bfs(r, c);

        cout << board[er][ec] << "\n";

        memset(board, 0, sizeof(board));
        memset(visit, false, sizeof(visit));
    }
}